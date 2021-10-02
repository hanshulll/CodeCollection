// C++ program to return first node of loop
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int key;
	struct Node* next;
};

Node* newNode(int key)
{
	Node* temp = new Node;
	temp->key = key;
	temp->next = NULL;
	return temp;
}

void printList(Node* head)
{
	while (head != NULL) {
		cout << head->key << " ";
		head = head->next;
	}
	cout << endl;
}

bool detectLoop(Node* head)
{

	Node* temp = new Node;
	while (head != NULL) {

		if (head->next == NULL) {
			return false;
		}

		if (head->next == temp) {
			return true;
		}

		Node* nex = head->next;

		head->next = temp;

		head = nex;
	}

	return false;
}

/* Driver program to test above function*/
int main()
{
	Node* head = newNode(1);
	head->next = newNode(2);
	head->next->next = newNode(3);
	head->next->next->next = newNode(4);
	head->next->next->next->next = newNode(5);

	head->next->next->next->next->next = head->next->next;

	bool found = detectLoop(head);
	if (found)
		cout << "Loop Found";
	else
		cout << "No Loop";

	return 0;
}
