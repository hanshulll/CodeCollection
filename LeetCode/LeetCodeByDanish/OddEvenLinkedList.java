package LeetCode;

import SelfCode.LL;

import java.util.List;

public class OddEvenLinkedList {
    ListNode head;
    ListNode tail;
    int size;

    public OddEvenLinkedList(){
        this.size = 0;
    }

    public class ListNode {
      int val;
      ListNode next;
      ListNode() {}
      ListNode(int val) { this.val = val; }
      ListNode(int val, ListNode next) {
          this.val = val; this.next = next;
      }
    }
    public void insertAtFirst(int val){
        ListNode n = new ListNode(val);
        n.next = head;
        head = n;

        if(tail == null){
            tail =head;
        }
        size+=1;
    }

    public void display(){
        ListNode n = head;
        while(n != tail){
            System.out.print(n.val+" --> ");
            n = n.next;
        }
        System.out.println(n.val);
        System.out.println();
    }
    public ListNode oddEvenList(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }

        ListNode h1 = head;
        ListNode h2 = h1.next;

        ListNode curr = head;
        ListNode n = curr.next;

        while(curr != null){
            curr.next = n.next;
            curr = n;
            if(n.next != null){
                n = n.next;
                break;
            }
        }

        ListNode temp = h1;
        while (temp.next != null){
            temp = temp.next;
        }
        temp.next = h2;
        return h1;
    }

    public static void main(String[] args) {
        OddEvenLinkedList l = new OddEvenLinkedList();
        l.insertAtFirst(10);
        l.insertAtFirst(20);
        l.insertAtFirst(30);
        l.insertAtFirst(40);
        l.insertAtFirst(50);
        l.display();
        l.oddEvenList(l.head);
        l.display();

    }

}
