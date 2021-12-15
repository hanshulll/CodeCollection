package LeetCode;
/*
https://leetcode.com/problems/remove-linked-list-elements/submissions/

 */
public class RemoveDuplicate {
    Node head;
    Node tail;
    int size;

    private class Node {
        int data;
        Node next;

        public Node(int val) {
            this.data = val;
        }

        public Node(int val, Node next) {
            this.data = val;
            this.next = next;
        }

        public Node() {

        }
    }

    public void insertAtFirst(int val) {
        Node n = new Node(val);
        n.next = head;
        head = n;

        if (tail == null) {
            tail = head;
        }
        size += 1;
    }

    public void display() {
        Node n = head;
        while (n != tail) {
            System.out.print(n.data + " --> ");
            n = n.next;
        }
        System.out.println(n.data);
        System.out.println();
    }


   //  * Definition for singly-linked list.
      public class ListNode {
      int val;
      ListNode next;
      ListNode() {}
      ListNode(int val) { this.val = val; }
     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
      }


    public ListNode removeElements(ListNode head, int val) {
        if (head == null || head.next == null && head.val != val) {
            return head;
        }
        if (head.val == val && head.next == null) {
            return null;
        }
        ListNode pre = null;
        ListNode curr = head;
        ListNode ret = pre;

        do {
                if (curr.val == val) {
                    curr = curr.next;
                } else {
                    if (pre == null) {
                        pre = curr;
                        curr = curr.next;
                        ret = pre;
                    } else {
                        pre.next = curr;
                        pre = curr;
                        curr = curr.next;
                    }
                }
            }while (pre.next != null);

            return ret.next;


        }
    }

}
