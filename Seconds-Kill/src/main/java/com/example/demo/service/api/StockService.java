package com.example.demo.service.api;

import com.example.demo.pojo.Stock;
import org.springframework.stereotype.Repository;

@Repository
public interface StockService {

    /**
     * 根据id获取剩余库存
     * @param id
     * @return
     */
    int getStockCount(int id);

    /**
     * 根据id查询剩余库存信息
     * @param id
     * @return
     */
    Stock getStockById(int id);

    /**
     * 根据 id 更新库存信息
     * @param stock
     * @return
     */
    int updateStockById(Stock stock);

    /**
     * 乐观锁更新库存信息
     * @param stock
     * @return
     */
    int updateStockByOptimistic(Stock stock);

    /**
     * 初始化数据库
     * @return
     */
    int initDBBefore();
}
