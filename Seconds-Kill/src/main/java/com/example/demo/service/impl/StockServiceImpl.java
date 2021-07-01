package com.example.demo.service.impl;

import com.example.demo.dao.StockMapper;
import com.example.demo.pojo.Stock;
import com.example.demo.service.api.StockService;
import org.springframework.beans.factory.annotation.Autowired;

public class StockServiceImpl implements StockService {


    @Autowired
    private StockMapper stockMapper;

    @Override
    public int getStockCount(int id) {
        Stock stock = stockMapper.selectByPrimaryKey(id);
        return stock.getCount();
    }

    @Override
    public Stock getStockById(int id) {
        return stockMapper.selectByPrimaryKey(id);
    }

    @Override
    public int updateStockById(Stock stock) {
        return stockMapper.updateByPrimaryKeySelective(stock);
    }

    @Override
    public int updateStockByOptimistic(Stock stock) {
        return stockMapper.updateByOptimistic(stock);
    }

    @Override
    public int initDBBefore() {
        return stockMapper.initDBBefore();
    }
}
