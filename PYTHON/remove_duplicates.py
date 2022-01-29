# Question Link : https://leetcode.com/problems/remove-duplicates-from-sorted-list/
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev = head
        current = head

        if head:
            val = head.val
            head = head.next

            while (head != None):
                if head.val == val:
                    prev.next = head.next
                    head = head.next
                else:
                    val = head.val
                    prev = head
                    head = head.next

        return current


