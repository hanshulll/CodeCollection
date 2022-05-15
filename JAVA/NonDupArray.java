class NoDupArray {

    private long[] a;//ref to array a
    private int nEliments;//number of data items

    public NoDupArray(int max) {//constructor
        a = new long[max];
        nEliments = 0;
    }

    public boolean find(long SearchKey) {//find specified value
        for (int i = 0; i < nEliments; i++) {
            if (a[i] == SearchKey) {
                return true;
            }
        }
        return false;
    }// end find()

    public void insert(long value) {//put element into array

        if (this.nEliments == this.a.length) {
            System.out.println("array is full");
        } else {
            if (find(value)) {
                System.out.println("value allready exist");
            } else {
                a[this.nEliments] = value;
                this.nEliments++;
            }
        }
    }//end insert()

    public boolean delete(long value) {//delete the element if it found
        for (int i = 0; i < this.nEliments; i++) {
            if(this.a[i]== value){
                for(int j=i;j<this.nEliments-1;j++){
                    this.a[j]=this.a[j+1];
                }
                this.nEliments--;
                System.out.println("value deleted");
                return true;
            }


        }
        System.out.println("value not found;");
        return false;
    }//end delete()

    public void display() {//display array contents
        System.out.println("values in the array-----------");
        for(int i=0;i<this.nEliments;i++){
            System.out.print(this.a[i]+" ");
        }
        System.out.println();
    } //end display()
}

public class NoDupArrayApp {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        NoDupArray x= new NoDupArray(6);
        x.insert(9);
        x.insert(5);
        x.insert(5);
        x.insert(6);
        x.insert(2);
        x.display();




    }

}
