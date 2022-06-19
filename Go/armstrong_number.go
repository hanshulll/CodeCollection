// Simple Program to check Armstrong Number

/* A positive integer is called an Armstrong number of order n if
the sum of cubes of each digits is equal to the number itself.
153 = 1*1*1 + 5*5*5 + 3*3*3  // 153 is an Armstrong number.
*/


package main
import "fmt"

func main() {
	var number,tempNumber,remainder int
	var result int =0
	fmt.Print("Enter any three digit number : ")
	fmt.Scan(&number)

	tempNumber = number

	// Use of For Loop as While Loop
	for {
		remainder = tempNumber%10
		result += remainder*remainder*remainder		
		tempNumber /=10
		
		if(tempNumber==0){
			break  // Break Statement used to stop the loop
		}
	}

	if(result==number){
		 fmt.Printf("%d is an Armstrong number.",number)
	}else{
		fmt.Printf("%d is not an Armstrong number.",number)
	}
}
