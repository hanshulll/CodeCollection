package LeetCode;
import java.util.*;
import java.io.*;
/*
https://leetcode.com/problems/palindrome-linked-list/
Given the head of a singly linked list, return true if it is a palindrome.

Input: head = [1,2,2,1]
Output: true

Input: head = [1,2]
Output: false


Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9
 */
public class Palindrome {
    public class ListNode {
      int val;
      ListNode next;
      ListNode() {}
      ListNode(int val) { this.val = val; }
      ListNode(int val, ListNode next) { this.val = val; this.next = next; }
  }
    public boolean isPalindrome(ListNode head) {

//         if(head.next == null) return true;
//         int left = 0;
//         int right = -1;

//         ListNode temp = head;

//         while(temp != null){
//             right +=1;
//             temp = temp.next;
//         }
//         while(left<right){
//             ListNode ln = getNode(left , head);
//             ListNode rn = getNode(right , head);

//             if(ln.val != rn.val){
//                 return false;
//             }
//             left++;
//             right--;

//         }
//         return true;
        ArrayList<Integer> list = new ArrayList<>();
        ListNode temp1 = head;
        while(temp1 != null){
            list.add(temp1.val);
            temp1 = temp1.next;
        }

        ListNode  temp = head , pre = null , next = null;
        while(temp != null){
            next = temp.next;
            temp.next = pre;
            pre = temp;
            temp = next;
        }

        head = pre;
        temp = head;
        for(int i = 0 ; i<list.size() ; i++){
            if(list.get(i) != temp.val){
                return false;
            }
            temp = temp.next;
        }

        return true;
    }
}
