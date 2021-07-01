package com.example.demo.common;

import com.example.demo.pojo.Stock;
import com.example.demo.service.api.StockService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.ApplicationArguments;
import org.springframework.boot.ApplicationRunner;
import org.springframework.stereotype.Component;

/**
 * 缓存预热，Spring Boot启动后立即执行
 */
@Component
public class RedisPreheatRunner implements ApplicationRunner {

    @Autowired
    private StockService stockService;

    @Override
    public void run(ApplicationArguments args) throws Exception {
        Stock stock=stockService.getStockById(1);
        //删除旧缓存

    }
}
