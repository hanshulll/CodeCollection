package com.example.ordermanagementsystem.controller;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import com.example.ordermanagementsystem.entity.Order;
import com.example.ordermanagementsystem.service.IOrderService;

/**
 * 
 * @author Debanjan
 *
 */

@RestController
@RequestMapping("/api/orders")
public class OrderController {

	@Autowired
	private IOrderService orderservice;
	
	@GetMapping("/getorders")
	public List<Order> getAllOrders() {
		return this.orderservice.getAllOrders();
	}
	
	@GetMapping("/getoderbyid/{id}")
	public Order getOrderById(@PathVariable("id") long orderId) {
		return this.orderservice.getOrderById(orderId);
	}
	
	@GetMapping("/getoderbystatus/{status}")
	public List<Order> getOrderByStatus(@PathVariable("status") String status) {
		return this.orderservice.findByOrderStatus(status);
	}
	
	@GetMapping("/getorderbytype/{type}")
	public List<Order> getOrderByType(@PathVariable("type") String type) {
		return this.orderservice.findByOrderType(type);
	}
	
	@PostMapping("/addorder")
	public Order saveOrder(@RequestBody Order order) {
		return this.orderservice.saveOrder(order);
	}
	
	@PutMapping("/updateorder/{orderId}")
	public Order updateOrder(@RequestBody Order order, @PathVariable("orderId") long orderId) {
		return this.orderservice.updateOrder(order, orderId);
	}
	
	@DeleteMapping("/deleteorder/{orderId}")
	public ResponseEntity<Order> deletOrder(@PathVariable("orderId") long orderId) {
		return this.orderservice.deleteOrder(orderId);
	}
}
