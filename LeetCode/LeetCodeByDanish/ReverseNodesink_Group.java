package LeetCode;
/*
https://leetcode.com/problems/reverse-nodes-in-k-group/
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list.
 If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]
Example 3:

Input: head = [1,2,3,4,5], k = 1
Output: [1,2,3,4,5]
Example 4:

Input: head = [1], k = 1
Output: [1]
 */

public class ReverseNodesink_Group {
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

    // Middle os A linked List
    public ListNode middleNode(ListNode head) {
        ListNode fast = head;
        ListNode slow = head;

        while(fast != null && fast.next != null){
            fast = fast.next.next;
            slow = slow.next;
        }
        return slow;
    }

    // Reverse A Linked List.
    public ListNode reverseListInplace(ListNode head){
        ListNode prev = null, curr = head, next = null;
        while(curr != null){
            next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    public ListNode reverseKGroup(ListNode head, int k) {
        if(k <= 1 || head == null){
            return head;
        }

        ListNode current = head;
        ListNode pre = null;

        while (true){
            ListNode last = pre;
            ListNode newEnd = current;

            ListNode next = current.next;
            for(int i =0 ; current != null && i<k ; i++){
                current.next = pre;
                pre = current;
                current = next;
                if(next != null){
                    next = next.next;
                }
            }
            if(last != null){
                last.next = pre;
            }else{
                head = pre;
            }

            newEnd.next = current;

            if(current == null){
                break;
            }
            pre = newEnd;

        }
        return head;

    }


}
