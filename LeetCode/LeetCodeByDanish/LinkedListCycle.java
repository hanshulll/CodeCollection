package LeetCode;

import java.util.List;

public class LinkedListCycle {
    class ListNode {
      int val;
      ListNode next;
      ListNode(int x) {
          val = x;
          next = null;
      }
  }
    public boolean hasCycle(ListNode head) {
        ListNode f = head;
        ListNode s = head;
        if(head == null) return false;
        if(head.next == null) return false;

        while(f != null && f.next != null ){
            f = f.next.next;
            s = s.next;

            if( f == s){
                return true;
            }
        }
        return false;
    }

    // If there is a cycle , find length of the cycle.
    public int CycleLength(ListNode head) {
        ListNode f = head;
        ListNode s = head;

        while(f != null && f.next != null ){
            f = f.next.next;
            s = s.next;

            if( f == s){
               // Calculate the Length.
                ListNode temp = s;
                int length = 0;
                do {
                    temp = temp.next;
                    length++;
                }while(temp != f);
                return  length;
            }
        }
        return 0;
    }

    public ListNode detectCycle(ListNode head) {
        int length = 0;

        ListNode f = head;
        ListNode s = head;


        while(f != null && f.next != null ){
            f = f.next.next;
            s = s.next;

            if( f == s){
                length = CycleLength(s);
                break;
            }
        }

        if(length ==0 )return  null;

        // Find the Start Node.
        ListNode first = head;
        ListNode second = head;

        while (length > 0){
            second = second.next;
            length--;
        }

        // Keep Moving both forward , and  they will meet  at the cycle.
        while (first != second){
            first = first.next;
            second = second.next;
        }
        return second;


    }
}
