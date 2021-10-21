// Implementation of stack data structure using array


#include<iostream>
using namespace std;
class stack {
private:
    int size;
    int top;
    int *s;
public:
    stack(int size);
    ~stack();
    void push(int x);
    int pop();
    int peek(int index);
    int isFull();
    int isEmpty();
    int stackTop();
    void display();
};
stack::stack(int size) {
    this->size = size;
    top = -1 ;
    s = new int [size];
}
stack::~stack() {
    delete[]s;
}
void stack::push(int x) {
    if (isFull()) cout << "Stack Overflow" << endl;
    else {
        top++;
        s[top] = x;
    }
}
int stack::pop() {
    int x = -1;
    if (isEmpty()) cout << "Stack Underflow " << endl;
    else {
        x = s[top];
        top--;
    }
    return x;
}
int stack::peek(int pos) {
    int x = -1;
    if (top - pos + 1 < 0 || top - pos + 1 == size) cout << "Invalid Position !" << endl;
    else {
        x = s[top - pos + 1];
    }
    return x;
}
int stack::isFull() {
    return (top == size - 1);
}
int stack::isEmpty() {
    return (top == -1);
}
void stack::display() {
    cout << "Stack : ";
    for (int i = top ; i >= 0 ; i--) {
        cout << s[i] << "|" << flush;
    }
    cout << endl;
}
int stack::stackTop() {
    if ((isEmpty())) return -1 ;
    return s[top];
}

int main() {
    int a[] = {1, 2, 3, 4, 5};
    stack stk(5);
    for (int i = 0 ; i < 5 ; i++) stk.push(a[i]) ;
    stk.display();
    stk.push(11);
    cout << "Stack full: " << stk.isFull() << endl;
    cout << "Peek at 0th: " << stk.peek(0) << endl;
    cout << "Peek at 3rd: " << stk.peek(3) << endl;
    cout << "Peek at 10th: " << stk.peek(10) << endl;
    cout << "Top element: " << stk.stackTop() << endl;
    for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
        cout << stk.pop() << ", " << flush;
    }
    cout << endl;
    stk.pop();
    cout << "Stack empty: " << stk.isEmpty() << endl;
    return 0;

}