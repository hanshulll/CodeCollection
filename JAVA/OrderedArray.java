package orderedarray;

public class OrderedArray {
    
    private long[] a; // declaring an array
    private int n; //number of data items in the array

    public OrderedArray (int max) {
        this.a = new long[max];
        this.n = 0;
    }

    public int size() { // return max size of the array
        return this.a.length;
    }

    public int find(long key) {
        
        for (int i = 0; i < n; i++) {
            if (a[i] == key) {
                return i;
            }
        }
        return -1; 
    }

    public void insert(long value) { // inserting elements into the arrray
        
        if (this.n == size()) {
            System.out.println("array is filled , can not insert");
            return;
        }
        for (int i = 0; i < n; i++) {
            if (value < a[i]) {
                for (int j = n - 1; j >= i; j--) {
                    this.a[j + 1] = a[j];
                }
                this.a[i] = value;
                this.n++;
                return;
            }
        }
        this.a[n] = value;
        n++;

    }

    public boolean delete(long value) {
       
        int index = find(value);
        if (index == -1) {
            System.out.println("Deletion terminated because could not find the value");
            return false;
        } else {
            for (int i = index; i < n - 1; i++) {
                this.a[i] = this.a[i + 1];
            }
            this.n--;
            return true;
        }

    }

    void display() { 
       
        for (int i = 0; i < this.n; i++) {
            System.out.print(this.a[i] + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
              
        OrderedArray arr = new OrderedArray(7);
        arr.insert(7);
        arr.insert(8);
        arr.insert(3);
        arr.insert(4);
        arr.display();
        arr.delete(11);
        arr.display();
    }
    
}
