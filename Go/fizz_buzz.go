package main

import "fmt"

func check(num1 int, num2 int) bool {
	if num1 % num2 == 0 {
		return true
	}
	return false
}

func main() {
	start := 1;
	max := 1000;

	for start <= max {
		s,n := check(start,3),check(start,5)
		if s == true && n == true {
			fmt.Println("FizzBuzz")
		} else if s == true && n == false {
			fmt.Println("Fizz")
		} else if s == false && n == true {
			fmt.Println("Buzz")
		} else {
			fmt.Println(start)
		}

		start ++
	}
}