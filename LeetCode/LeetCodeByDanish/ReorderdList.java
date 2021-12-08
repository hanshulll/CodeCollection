package LeetCode;
/*
https://leetcode.com/problems/reorder-list/
 */
public class ReorderdList {
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
    public ListNode middleNode(ListNode head) {
        ListNode fast = head;
        ListNode slow = head;

        while(fast != null && fast.next != null){
            fast = fast.next.next;
            slow = slow.next;
        }
        return slow;
    }
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

    public void reorderList(ListNode head) {
        if(head == null || head.next == null){
            return;
        }

        ListNode middle = middleNode(head);

        ListNode hs = reverseListInplace(middle);
        ListNode hf = head;

        // Rearrange it again.
        while (hf != null && hs != null){
            ListNode temp = hf.next;
            hf.next = hs;
            hf = temp;

            temp = hs.next;
            hs.next = hf;
            hs = temp;
        }

        // next of tail to null
        if(hf != null){
            hf.next = null;
        }

    }

    public static void main(String[] args) {

    }
}
