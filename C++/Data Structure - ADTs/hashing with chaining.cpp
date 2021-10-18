#include<iostream>
using namespace std;
#define size 10

struct node{
    int data;
    struct node* next;
};

struct node* table[size]={NULL};


struct node* newNode(int key){
    struct node* ptr=new node;
    ptr->data=key;
    ptr->next=NULL;
    return ptr;
}

int hash1(int key){
    return (key%size);
}

void insert (int key){
    int index=hash1(key);
    if(table[index]==NULL){
       table[index]=newNode(key);
       return; 
    }
    struct node* temp=table[index];
    struct node* prev;
    while(temp!=NULL){
        prev=temp;
        temp=temp->next;
    }
    prev->next=newNode(key);
    return;
}

struct  node* search(int key){
    int index=hash1(key);
    struct node* temp=table[index];
    while(temp!=NULL){
        if(temp->data==key){
            cout<<"Element found!!!";
            return temp;
        }
        temp=temp->next;
    }
    cout<<"Element not present!!";
    return NULL;
}

void del(int key){
    int index=hash1(key);
    struct node* temp=table[index];
    struct node* prev;
    while(temp!=NULL &&temp->data!=key){
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL){
        cout<<"Does not exist ";
        return;
    }
    if(temp==table[index]){
        table[index]=temp->next;
        delete(temp);
        return;
    }
    prev->next=temp->next;
    return;
}
void display(){
    for(int i=0;i<size;i++){
        cout<<"Table index "<<i<<": ";
        struct node* temp=table[i];
        while(temp!=NULL){
            cout<<temp->data<<"--->";
            temp=temp->next;
        }
        cout<<endl;
    }
}

int main(){
    int ch;
    while(1){
        cout<<"**************************************************************"<<endl;
        cout<<" 1: Insert an element in hash table\n 2: Search an element\n 3: Delete an element\n 4: Display\n 5: Exit\n";
        cout<<"**************************************************************"<<endl;
        cout<<"Enter your choice>>>> ";
        cin>>ch;
        switch(ch){
            case 1:
                int num;
                cout<<"enter an element: ";
                cin>>num;
                insert(num);
                cout<<endl;
                break;
            case 2:
                int s;
                cout<<"enter an element to serach: ";
                cin>>s;
                search(s);
                cout<<endl;
                break;
            case 3:
                int d;
                cout<<"Enter an element to delete: ";
                cin>>d;
                del(d);
                cout<<endl;
                break;
            case 4:
                display();
                cout<<endl;
                break;
            case 5:
                exit(0);
            default:
                cout<<"Enter appropriate option!!!!";
                cout<<endl;
                break;
        }
    }
    return 0;
}