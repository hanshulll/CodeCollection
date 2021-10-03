
import kotlin.math.sqrt

/**
 * This program takes an array of numbers
 * and sums up all the prime numbers available
 * in the array
 *
 * GitHub Username: mayorJAY
 */
class PrimeNumberAdder {

    fun main() {
        val myArray = intArrayOf(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30)
        sumPrimeNumbers(myArray);
    }

    private fun sumPrimeNumbers(numbers: IntArray) {
        var sum = 0
        for (num in numbers) {
            if (isPrimeNumber(num)) {
                sum += num
            }
        }
        println(sum)
    }

    private fun isPrimeNumber(n: Int): Boolean {
        // Exclude 0 and 1 cos they are not prime numbers
        if (n <= 1) {
            return false
        }
        // Identify the actual prime numbers
        var i = 2
        while (i <= sqrt(n.toDouble())) {
            if (n % i == 0) {
                return false
            }
            i++
        }
        return true
    }
}