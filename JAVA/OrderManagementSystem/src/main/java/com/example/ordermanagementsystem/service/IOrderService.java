package com.example.ordermanagementsystem.service;

import java.util.List;

import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Service;

import com.example.ordermanagementsystem.entity.Order;

/**
 * 
 * @author Debanjan
 *
 */

@Service
public interface IOrderService {
	Order getOrderById(long orderId);
	List<Order> getAllOrders();

	List<Order> findByOrderType(String ordType);
	List<Order> findByOrderStatus(String ordStatus);
	
	Order saveOrder(Order order);
	
	Order updateOrder(Order order, long orderId);
	ResponseEntity<Order> deleteOrder(long orderId);
}
