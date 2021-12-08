package LeetCode;//package LeetCode;
//
///*
// Merge two sorted linked lists and return it as a sorted list.
// The list should be made by splicing together the nodes of the first two lists.
// https://leetcode.com/problems/merge-two-sorted-lists/
// */

import java.util.List;

public class MergeTwoSortedList {

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

    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode dummyHead = new ListNode();
        ListNode tail = dummyHead;

        while (l1 != null && l2 != null) {
            if (l1.val < l2.val) {
                tail.next = l1;
                l1 = l1.next;
                tail = l2.next;
            } else {
                tail.next = l2;
                l2 = l2.next;
                tail = tail.next;
            }

        }
        if (l1 != null) {
            tail.next = l1;
        }
        if (l2 != null)
            tail.next = l1;
        return dummyHead.next;


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

}

