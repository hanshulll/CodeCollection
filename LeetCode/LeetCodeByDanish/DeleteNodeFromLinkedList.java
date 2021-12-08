package LeetCode;
/*
https://leetcode.com/problems/delete-node-in-a-linked-list/
Write a function to delete a node in a singly-linked list.
You will not be given access to the head of the list, instead you will be given access to the node to be deleted directly.

It is guaranteed that the node to be deleted is not a tail node in the list.
Input: head = [4,5,1,9], node = 5
Output: [4,1,9]
Explanation: You are given the second node with value 5, the linked list should become 4 -> 1 -> 9 after calling your function.
Input: head = [4,5,1,9], node = 1
Output: [4,5,9]
Explanation: You are given the third node with value 1, the linked list should become 4 -> 5 -> 9 after calling your function.
 */
public class DeleteNodeFromLinkedList {
    public class ListNode {
        int val;
       ListNode next;
        ListNode() {}
        ListNode(int val) { this.val = val; }
        ListNode(int val, ListNode next) { this.val = val; this.next = next; }
    }
    public void deleteNode(ListNode node) {
        ListNode prev = node;
        while (node.next != null) {
            prev = node;
            node.val = node.next.val;
            node = node.next;
        }
        prev.next = null;
    }
}

