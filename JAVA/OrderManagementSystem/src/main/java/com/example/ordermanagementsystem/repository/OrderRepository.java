package com.example.ordermanagementsystem.repository;

import java.util.List;

import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.Query;
import org.springframework.stereotype.Repository;

import com.example.ordermanagementsystem.entity.Order;

/**
 * 
 * @author Debanjan
 *
 */

@Repository
public interface OrderRepository extends JpaRepository<Order, Long> {
	
	@Query("select o from Order o where o.orderType like %?1")
	List<Order> findByOrderType(String ordType);
	
	List<Order> findByOrderStatus(String ordStatus);
}
