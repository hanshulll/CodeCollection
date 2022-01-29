



public class StackArrayApp {

   
    public static void main(String[] args) {
        // TODO code application logic here

        StackArray obj = new StackArray(6);
        obj.push(4);
        obj.push(20);
        obj.push(67);
        obj.push(45);
        obj.push(34);
        obj.push(88);
        //obj.push(100);
        obj.display();

        try{
            int k = obj.peek();
            System.out.println("Peek is"+k);
        }catch(Exception e){
        }
        try {
            int k = obj.peek();
            System.out.println("Peek is " + k);
            System.out.println("poped an item: " + obj.pop());
            System.out.println("poped an item: " + obj.pop());
            System.out.println("poped an item: " + obj.pop());
            System.out.println("poped an item: " + obj.pop());
            System.out.println("poped an item: " + obj.pop());
            System.out.println("poped an item: " + obj.pop());
            System.out.println("poped an item: " + obj.pop());
        } catch (Exception e) {
            System.out.println(e);
        }
        
        
        
        StackArrayApp s = new StackArrayApp();
        System.out.print("Binary value of 50 is :");
        s.decimalToBinary(50);
        

    }
    
  public void decimalToBinary(int no){
      int temp = no;
      int count=0;
      
      while(temp !=0){
      temp = temp/2;
      count++;
      }
      
  StackArray myStack = new StackArray(count);
  
  temp = no;
  
  while(temp != 0 ){
  int remain = temp%2;
  temp = temp/2;
  myStack.push(remain);
  }
  
  while(!myStack.isEmpty()){
      try{
          System.out.print(myStack.pop()); 
      }catch(Exception e){
         
      }
  }
  
  }  
    
    
    
 
}

class StackArray {

    private int maxSize; //size of stack array
    private int[] stackData;
    private int top; //top of stack
//-------------------------------------------------------------------------

    public StackArray(int s) {
        this.stackData = new int[s];
        this.maxSize = s;
        this.top = -1;
    }

    public boolean isEmpty() {
        return top == -1;
    }

    public boolean isFull() {
        return top + 1 == maxSize;
    }

    public void push(int item) {

        if (isFull()) {
            System.out.println("Stack is full cannot push");
            return;
        }
        //top++;
        stackData[++top] = item;

    }

    public int pop() throws Exception {
        if (isEmpty()) {
            throw new Exception("Stack is empty cannot pop");
            //return wenne nathi nisa exception ekak enawa
        }
        return stackData[top--];

    }

    public int peek() throws Exception {
        if (isEmpty()) {
            throw new Exception(" Stack is empty cannot peak");
        }
        return stackData[top];
    }

    public void display() {
        System.out.println("Start printing stack data");
        for (int i = top; i >= 0; i--) {
            System.out.println(stackData[i]);
        }
        System.out.println("End printing stack data");

    }

}
