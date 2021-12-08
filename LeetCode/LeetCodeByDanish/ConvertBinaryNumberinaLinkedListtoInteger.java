package LeetCode;

public class ConvertBinaryNumberinaLinkedListtoInteger {
    public class ListNode {
        int val;
        MiddleofListNode.ListNode next;
        ListNode() {}
        ListNode(int val) { this.val = val; }
        ListNode(int val, MiddleofListNode.ListNode next) { this.val = val; this.next = next; }
    }

    public int getDecimalValue(ListNode head) {
        ListNode temp = head;
        int digit = 0;
        int pow =1;
        while (temp != null){
           int tempval = temp.val;
           digit *=pow;
           digit += tempval;
           pow = 10;

        }

        return binaryToDecimal(digit);

    }

   public int binaryToDecimal(int n){
       int ans = 0;
       int pow = 1;

       while (n > 0)
       {
           int r = n % 2;
           n /= 2;

           ans += r * pow;

           pow *= 10;
       }
       return ans;
    }



}
