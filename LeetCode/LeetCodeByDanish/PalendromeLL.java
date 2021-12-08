package LeetCode;

import SelfCode.ReverseLL;

import java.util.List;

/*
https://leetcode.com/problems/palindrome-linked-list/
Given the head of a singly linked list, return true if it is a palindrome.
 */
public class PalendromeLL {
    ListNode head;
    ListNode tail;

    int size;

    public class ListNode {
        int val;
        ListNode next;

        ListNode() {
        }

        ListNode(int val) {
            this.val = val;
        }

        ListNode(int val, ListNode next) {
            this.val = val;
            this.next = next;
        }
    }

    public void insertAtFirst(int val) {
        ListNode n = new ListNode(val);
        n.next = head;
        head = n;

        if (tail == null) {
            tail = head;
        }
        size += 1;
    }

    public void display() {
        ListNode n = head;
        while (n != tail) {
            System.out.print(n.val + " --> ");
            n = n.next;
        }
        System.out.println(n.val);
        System.out.println();
    }

    public ListNode reverseListInplace(ListNode node){
        ListNode prev = null, curr = head, next = null;
        while(curr != null){
            next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    public ListNode mid(ListNode head){
        ListNode fast = head;
        ListNode slow = head;

        while(fast != null && fast.next != null){
            fast = fast.next.next;
            slow = slow.next;
        }
        return slow;


    }

    public boolean isPalindrome(ListNode head){
        ListNode middle = mid(head);
        ListNode headSecond = reverseListInplace(middle);
        ListNode reverseHead = headSecond;

        // Compare Both the halfs.
        while (head != null && headSecond != null){
            if(head.val != headSecond.val){
                break;
            }
            head = head.next;
            headSecond = headSecond.next;
        }
        reverseListInplace(reverseHead);

        return head == null || headSecond == null;

    }




    public static void main(String[] args) {
        PalendromeLL l = new PalendromeLL();
        l.insertAtFirst(1);
        l.insertAtFirst(2);
        l.insertAtFirst(3);
        l.insertAtFirst(2);
        l.insertAtFirst(1);
        l.display();
//        l.reverseListInplace(l.head);
//        l.display();
      boolean ans=   l.isPalindrome(l.head);
        System.out.println(ans);



    }
}
