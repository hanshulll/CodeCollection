import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;

class SinglyLinkedListNode {
    public int data;
    public SinglyLinkedListNode next;

    public SinglyLinkedListNode(int nodeData) {
        this.data = nodeData;
        this.next = null;
    }
}

class SinglyLinkedList {
    public SinglyLinkedListNode head;
    public SinglyLinkedListNode tail;

    public SinglyLinkedList() {
        this.head = null;
        this.tail = null;
    }

    public void insertNode(int nodeData) {
        SinglyLinkedListNode node = new SinglyLinkedListNode(nodeData);

        if (this.head == null) {
            this.head = node;
        } else {
            this.tail.next = node;
        }

        this.tail = node;
    }
    
    public SinglyLinkedListNode getHead(){
        return head;
    }
}

class SinglyLinkedListPrintHelper {
    public static void printList(SinglyLinkedListNode node, String sep) {
        while (node != null) {
            System.out.print(node.data);

            node = node.next;

            if (node != null) {
                System.out.print(sep);
            }
        }
    }
}

class Result {

    public static void reversePrint(SinglyLinkedListNode llist) {
    // Write your code here
        if(llist.next==null){
            
            System.out.println(llist.data);
            return;
        }
        else{
            reversePrint(llist.next);
            System.out.println(llist.data);
        }
    }

}

public class Solution {
    public static void main(String[] args) throws IOException {
        Scanner input=new Scanner(System.in);
        int listCount=input.nextInt();
        for(int i=0;i<listCount;i++){
            int listElmtCount=input.nextInt();
            SinglyLinkedList list=new SinglyLinkedList();
            for(int j=0;j<listElmtCount;j++){
                list.insertNode(input.nextInt());
            }
            
            Result.reversePrint(list.head);
            
        }
    }
}
