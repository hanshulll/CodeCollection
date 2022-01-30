/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head, *n = temp, *prev = nullptr;
        while(temp){
            temp = temp->next;
            n->next = prev;
            prev = n;
            n = temp;
        }
        head = prev;
        return head;
    }
};