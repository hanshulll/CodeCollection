package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter your name : ")
	text, _ := reader.ReadString('\n')

	fmt.Println("\nCongratulations!!\nYou have entered : ", text)
}
