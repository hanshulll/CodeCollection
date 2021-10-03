public class Largest {

    public static void main(String[] args) {
        double[] numArray = { 44.4, -34.5, 40.0, 28.5, 95.5, 54.7, -99.7, -66.5 };
        double largest = numArray[0];

        for (double num: numArray) {
            if(largest < num)
                largest = num;
        }

        System.out.format("Largest element = %.2f", largest);
    }
}
