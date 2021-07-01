package com.example.demo.service.api;

import com.example.demo.pojo.Stock;
import org.springframework.stereotype.Repository;

@Repository
public interface OrderService {

    /**
     * 清空订单表
     * @return
     */
    int delOrderDBBefore();

    /**
     * 创建订单存在超卖问题
     *
     * @param sid
     * @return
     * @throws Exception
     */
    int createWrongOrder(int sid) throws Exception;

    /**
     * 数据库乐观锁更新库存，解决超卖问题
     *
     * @param sid
     * @return
     * @throws Exception
     */
    int createOptimisticOrder(int sid) throws Exception;

    /**
     * 数据库乐观锁更新库存，库存查找Redis减小数据库读压力
     *
     * @param sid
     * @return
     * @throws Exception
     */
    int createOrderWithLimitAndRedis(int sid) throws Exception;

    /**
     * 限流+Redis缓存库存信息+KafkaTest 异步发送消息
     *
     * @param sid
     * @throws Exception
     */
    void createOrderWithLimitAndRedisAndKafa(int sid) throws Exception;

    /**
     * kafka消费消息
     *
     * @param stock
     * @return
     * @throws Exception
     */
    int consumerTopicToCreateOrderWithKafka(Stock stock) throws Exception;
}
