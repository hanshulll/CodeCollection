
import java.util.Scanner

/**
 * This program request for an input from the user
 * and displays the input on the console
 *
 * GitHub Username: mayorJAY
 */
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