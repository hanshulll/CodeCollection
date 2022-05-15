package com.example.ordermanagementsystem.entity;

import java.util.Date;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.Table;

/**
 * 
 * @author Debanjan
 *
 */

@Entity
@Table(name = "orders")
public class Order {
	@Id
	@GeneratedValue(strategy = GenerationType.AUTO)
	private long id;
	
	@Column(name = "ordertype")
	private String orderType;	
	
	@Column(name = "ordervalue")
	private double orderValue;
	
	@Column(name = "orderdate")
	private Date orderDate;
	
	@Column(name = "orderstatus")
	private String orderStatus;

//	Constructors
	public Order() {
		super();
	}

	public Order(String orderType, double orderValue, Date orderDate, String orderStatus) {
		super();
		this.orderType = orderType;
		this.orderValue = orderValue;
		this.orderDate = orderDate;
		this.orderStatus = orderStatus;
	}

//	Getters and setters
	public long getId() {
		return id;
	}

	public void setOrderId(long id) {
		this.id = id;
	}

	public String getOrderType() {
		return orderType;
	}

	public void setOrderType(String orderType) {
		this.orderType = orderType;
	}

	public double getOrderValue() {
		return orderValue;
	}

	public void setOrderValue(double orderValue) {
		this.orderValue = orderValue;
	}

	public Date getOrderDate() {
		return orderDate;
	}

	public void setOrderDate(Date orderDate) {
		this.orderDate = orderDate;
	}

	public String getOrderStatus() {
		return orderStatus;
	}

	public void setOrderStatus(String orderStatus) {
		this.orderStatus = orderStatus;
	}

}
