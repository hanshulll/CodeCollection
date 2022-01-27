/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#define node ListNode

class Solution {
public:
    node* getIntersectionNode(node* l1,node* l2){
        node *p1=l1,*p2=l2;
        while(p1&&p2){
            p1=p1->next;
            p2=p2->next;
        }
        if(p2){swap(p1,p2);swap(l1,l2);}
        p2=l1;
        while(p1&&p2){p1=p1->next;p2=p2->next;}
        p1=l2;
        while(p1&&p2){
            if(p1==p2)return p1;
            p1=p1->next;
            p2=p2->next;
        }
        return p1;
    }
};
