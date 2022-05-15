class Question2 {


    void sort(int arr[]) {
        int n = arr.length;
        int number = 0;

        for (int i = 0; i < n - 1; i++) {
            // Find the minimum element in unsorted array 
            int min = i;

            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[min]) {
                    min = j;
                }
            }

            //swaping
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;

            number++;
        }
        System.out.println(number);
    }

    // Prints the array 
    void newArray(int arr[]) {

        for (int i = 0; i < arr.length; ++i) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }

}
