package com.example.ordermanagementsystem.exception;

import org.springframework.http.HttpStatus;
import org.springframework.web.bind.annotation.ResponseStatus;

/**
 * 
 * @author Debanjan
 *
 */

@ResponseStatus(value = HttpStatus.NOT_FOUND)
public class OrderNotFoundException extends RuntimeException {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	public OrderNotFoundException(String message) {
		super(message);	
	}
	
}
