package com.example.demo.service.impl;

import com.example.demo.common.StockWithRedis.RedisKeysConstant;
import com.example.demo.common.StockWithRedis.StockWithRedis;
import com.example.demo.common.utils.RedisPoolUtil;
import com.example.demo.dao.StockOrderMapper;
import com.example.demo.pojo.Stock;
import com.example.demo.pojo.StockOrder;
import com.example.demo.service.api.OrderService;
import com.google.gson.Gson;
import com.google.gson.GsonBuilder;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.kafka.core.KafkaTemplate;
import org.springframework.transaction.annotation.Transactional;


import java.util.Date;

@Slf4j
@Transactional(rollbackFor = Exception.class)

public class OrderServiceImpl implements OrderService {

    @Autowired
    private StockServiceImpl stockService;

    @Autowired
    private StockOrderMapper orderMapper;

    @Autowired
    private KafkaTemplate<String, String> kafkaTemplate;

    @Value("${spring.kafka.template.default-topic}")
    private String kafkaTopic;

    private Gson gson = new GsonBuilder().create();

    @Override
    public int delOrderDBBefore() {
        return orderMapper.delOrderDBBefore();
    }

    @Override
    public int createWrongOrder(int sid) throws Exception {
        Stock stock=checkStock(sid);
        saleStock(stock);
        int res=createOrder(stock);
        return res;
    }



    @Override
    public int createOptimisticOrder(int sid) throws Exception {
        //校验库存
        Stock stock=checkStock(sid);
        //乐观锁更新
        saleStockOptimstic(stock);
        //创建订单
        int id =createOrder(stock);

        return id;
    }

    @Override
    public int createOrderWithLimitAndRedis(int sid) throws Exception {
        Stock stock=checkStockWithRedis(sid);
        saleStockOptimsticWithRedis(stock);
        int res=createOrder(stock);
        return res;
    }

    @Override
    public void createOrderWithLimitAndRedisAndKafa(int sid) throws Exception {
        Stock stock=checkStockWithRedis(sid);
        kafkaTemplate.send(kafkaTopic,gson.toJson(stock));
        log.info("消息发送至kafka成功");
    }

    @Override
    public int consumerTopicToCreateOrderWithKafka(Stock stock) throws Exception {
        // 乐观锁更新库存和 Redis
        saleStockOptimsticWithRedis(stock);
        int res = createOrder(stock);
        if (res == 1) {
            log.info("Kafka 消费 Topic 创建订单成功");
        } else {
            log.info("Kafka 消费 Topic 创建订单失败");
        }

        return res;
    }

    //Redis校验库存
    private Stock checkStockWithRedis(int sid) throws Exception {
        Integer count = Integer.parseInt(RedisPoolUtil.get(RedisKeysConstant.STOCK_COUNT + sid));
        Integer sale = Integer.parseInt(RedisPoolUtil.get(RedisKeysConstant.STOCK_SALE + sid));
        Integer version = Integer.parseInt(RedisPoolUtil.get(RedisKeysConstant.STOCK_VERSION + sid));
        if(count<1){
            log.info("库存不足");
            throw new RuntimeException("库存不足 ："+sale);

        }
        Stock stock = new Stock();
        stock.setId(sid);
        stock.setCount(count);
        stock.setSale(sale);
        stock.setVersion(version);
        stock.setName("手机");

        return stock;
    }
    /**
     * 更新数据库和 DB
     */
    private void saleStockOptimsticWithRedis(Stock stock) throws Exception {
        int res = stockService.updateStockByOptimistic(stock);
        if (res == 0) {
            throw new RuntimeException("并发更新库存失败");
        }
        // 更新 Redis
        StockWithRedis.updateStockWithRedis(stock);
    }

    //校验库存
    private Stock checkStock(int sid) throws Exception{
        Stock stock=stockService.getStockById(sid);
        if(stock.getCount()<1)
        {
            throw new RuntimeException("库存不足");
        }
        return stock;
    }

    private int saleStock(Stock stock){
        stock.setSale(stock.getSale()+1);
        stock.setCount(stock.getCount()-1);
        return stockService.updateStockById(stock);
    }

    //乐观锁扣库存
    private void saleStockOptimstic(Stock stock) throws Exception {
        int count = stockService.updateStockByOptimistic(stock);
        if (count == 0) {
            throw new RuntimeException("并发更新库存失败");
        }
    }

    private int createOrder(Stock stock) throws Exception{
        StockOrder order=new StockOrder();
        order.setId(stock.getId());
        order.setName(stock.getName());
        order.setCreateTime(new Date());
        int res=orderMapper.insertSelective(order);
        if(res==0){
            throw  new RuntimeException("创建订单失败");
        }
        return res;
    }
}
