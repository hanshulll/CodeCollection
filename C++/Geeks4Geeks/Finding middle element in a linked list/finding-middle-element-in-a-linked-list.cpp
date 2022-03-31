// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
/* Link list Node 
struct Node {
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
}; */
class Solution{
    public:
    /* Should return data of middle node. If linked list is empty, then  -1*/
    int count(Node *head){
        int cnt = 0;
        Node* temp = head;
        while(temp!=NULL){
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }
    int getMiddle(Node *head)
    {
        // Your code here
        if(!head){
            return -1;
        }
        int len = count(head);
        Node* temp = head;
        if(len%2 == 0){
            len = (len/2);
            ++len;
            while(--len){
                temp = temp->next;
            }
        }
        else{
            len = len/2;
            while(len--){
                temp = temp->next;
            }
        }
        
        return temp->data;
    }
};


// { Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        cout << ob.getMiddle(head) << endl;
    }
    return 0;
}
  // } Driver Code Ends