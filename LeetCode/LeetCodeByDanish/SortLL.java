package LeetCode;

import java.util.List;

/*
https://leetcode.com/problems/sort-list/
Given the head of a linked list, return the list after sorting it in ascending order.
Input: head = [4,2,1,3]
Output: [1,2,3,4]

Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]

 */
public class SortLL {
    public class ListNode {
      int val;
      ListNode next;
      ListNode() {}
      ListNode(int val) { this.val = val; }
      ListNode(int val, ListNode next) { this.val = val; this.next = next; }
  }

  public ListNode mergeTwoLists2(ListNode l1, ListNode l2){
        ListNode h3 = new ListNode();
        h3.next = null;
        ListNode tail = h3;

        ListNode l11 = l1;
        ListNode l22 =  l2;

        while ( l11 != null && l22 != null){
          if(l11.val < l22.val){
            tail.next = l11;
            l11 = l11.next;
            tail = tail.next;
          }else{
            tail.next = l22;
            l22 = l22.next ;
            tail = tail.next;
          }
        }

        if(l11 != null){
          tail.next = l11;
        }
        if(l22 != null){
          tail.next = l22;
        }
        return  h3.next;
    }

    public ListNode middleNode(ListNode head) {
        ListNode fast = head;
        ListNode slow = head;

        while(fast.next != null && fast.next.next != null){
          fast = fast.next.next;
          slow = slow.next;
        }
        if(fast.next != null){
          slow = slow.next;
        }
        return slow;

      }
  public ListNode sortList(ListNode head) {
      if(head == null || head.next == null){
        return head;
      }
      ListNode mid = middleNode(head);
      ListNode left = sortList(head);
      ListNode right = sortList(mid);

      return mergeTwoLists2(left , right);
  }

}
