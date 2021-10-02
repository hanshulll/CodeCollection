package com.example.ordermanagementsystem.service;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Service;

import com.example.ordermanagementsystem.entity.Order;
import com.example.ordermanagementsystem.exception.OrderNotFoundException;
import com.example.ordermanagementsystem.repository.OrderRepository;

/**
 * 
 * @author Debanjan
 *
 */

@Service
public class OrderService implements IOrderService {

	@Autowired
	private OrderRepository orderrepository;
	
	@Override
	public List<Order> getAllOrders() {
		// TODO Auto-generated method stub
		return this.orderrepository.findAll();
	}

	@Override
	public Order getOrderById(long orderId) {
		// TODO Auto-generated method stub
		return this.orderrepository.findById(orderId)
				.orElseThrow(() -> new OrderNotFoundException("Order not found with id " + orderId));
	}

	@Override
	public Order saveOrder(Order order) {
		// TODO Auto-generated method stub
		return this.orderrepository.save(order);
	}

	@Override
	public Order updateOrder(Order order, long orderId) {
		// TODO Auto-generated method stub
		Order existingorder = this.orderrepository.getById(orderId);
		existingorder.setOrderStatus(order.getOrderStatus());
		existingorder.setOrderType(order.getOrderType());
		existingorder.setOrderValue(order.getOrderValue());
		return this.orderrepository.save(existingorder);
	}

	@Override
	public ResponseEntity<Order> deleteOrder(long orderId) {
		// TODO Auto-generated method stub
		Order existingorder = this.orderrepository.findById(orderId)
				.orElseThrow(() -> new OrderNotFoundException("Order not found with id " + orderId));
		this.orderrepository.delete(existingorder);
		return ResponseEntity.ok().build();
	}
	
	@Override
	public List<Order> findByOrderType(String ordType) {
		return this.orderrepository.findByOrderType(ordType);
	}
	
	@Override
	public List<Order> findByOrderStatus(String ordStatus) {
		return this.orderrepository.findByOrderStatus(ordStatus);
	}

}
