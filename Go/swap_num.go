//Swap two numbers without temp variable

package main

import "fmt"

func main(){
    fmt.Print("Enter first number : ")
    var first int
    fmt.Scanln(&first)
    fmt.Print("Enter second number : ")
    var second int
    fmt.Scanln(&second)
    first = first-second
    second = first+second
    first = second-first
    fmt.Println("First number :",first)
    fmt.Println("Second number :",second)
}
