
import java.util.Scanner

class InputDisplay {

    private val scanner: Scanner = Scanner(System.`in`)

    fun main() {
        // Taking the input
        println("Enter any String: ")
        val input: String = scanner.nextLine()

        // Displaying the input
        print(" Your entered String is : $input")
    }
}