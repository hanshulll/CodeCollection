/*
AVL tree is a self-balancing Binary Search Tree (BST) where the difference between 
heights of left and right subtrees cannot be more than one for all nodes.
Q: Program to insert nodes in AVL tree and delete nodes in AVL tree.
*/

/*
Time Complexity:
Inserting node in AVL tree: O(logn)
Deleting node from AVL tree: O(logn)
*/

#include<iostream>
using namespace std;
class node
{
	public: 
	int data;
	int height;
	node *left;
	node *right;
};
int max(int a, int b)
{
	return (a>b)?a:b;
}
int height(node* n)
{
	if (n == NULL)
	return 0;
	return n->height;
}
node* newNode(int data)
{
	node* new_node = new node();
	new_node->data = data;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->height = 1; // New node is initially added at leaf
	return new_node;
}
node *rightRotate(node *y)
{
	node *x = y->left;
	node *t = x->right;
	// Perform rotation
	x->right = y;
	y->left = t;
	// Update heights
	y->height = max(height(y->left), height(y->right))+1;
	x->height = max(height(x->left), height(x->right))+1;
	return x; // Return new root
}
node *leftRotate(node *x)
{
	node *y = x->right;
	node *t = y->left;
	// Perform rotation
	y->left = x;
	x->right = t;
	// Update heights
	x->height = max(height(x->left), height(x->right))+1;
	y->height = max(height(y->left), height(y->right))+1;
	// Return new root
	return y;
}
// Get balance factor of node n
int getBalance(node* n)
{
	if (n == NULL)
	return 0;
	return height(n->left) - height(n->right);
}
node* insert(node* n, int data)
{
	// Perform normal BST insertion
	if (n == NULL)
	return newNode(data);
	if (data < n->data)
	n->left = insert(n->left, data);
	else if (data > n->data)
	n->right = insert(n->right, data);
	else
	return n; // Equal data values are not allowed in BST
	// Update height of this ansector node
	n->height = 1+max(height(n->left), height(n->right));
	// Get balance factor of this ansector node to check whether this node became unbalanced
	int balance = getBalance(n);
	// If this node becomes unbalanced, then there are 4 cases
	// Left Left case
	if (balance > 1 && data < n->left->data)
	return rightRotate(n);
	// Right Right case
	if (balance < -1 && data > n->right->data)
	return leftRotate(n);
	// Left Right case
	if (balance > 1 && data > n->left->data)
	{
		n->left = leftRotate(n->left);
		return rightRotate(n);
	}
	// Right Left case
	if (balance < -1 && data < n->right->data)
	{
		n->right = rightRotate(n->right);
		return leftRotate(n);
	}
	// return the (unchanged) node pointer
	return n;
}
node* findMin(node* n)
{
	node* temp = n;
	// Loop down to find the leftmost leaf
	while (temp->left != NULL)
	temp = temp->left;
	return temp;
}
node* deleteNode(node* root, int data)
{
	// Perform standard BST delete
	if (root == NULL)
	return root;
	else if (data < root->data)
	root->left = deleteNode(root->left, data);
	else if (data > root->data)
	root->right = deleteNode(root->right, data);
	else
	{
		// No child
		if (root->left == NULL && root->right == NULL)
		{
			delete root;
			root = NULL;
		}
		// 1 child
		else if (root->left == NULL)
		{
			node* temp = root;
			root = root->right;
			delete temp;
		}
		else if (root->right == NULL)
		{
			node* temp = root;
			root = root->left;
			delete temp;
		}
		// 2 children
		else
		{
			node* temp = findMin(root->right);
			root->data = temp->data;
			root->right = deleteNode(root->right, temp->data);
		}
	}
	if (root == NULL)
	return root;
	// Update height of current node
	root->height = 1+max(height(root->left), height(root->right));
	// Get balance factor of this node to check whether this node became unbalanced
	int balance = getBalance(root);
	// If this node becomes unbalanced, then there are 4 cases
	// Left Left case
	if (balance > 1 && getBalance(root->left) >= 0)
	return rightRotate(root);
	// Right Right case
	if (balance < -1 && getBalance(root->right) <= 0)
	return leftRotate(root);
	// Left Right case
	if (balance > 1 && getBalance(root->left) < 0)
	{
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}
	// Right Left case
	if (balance < -1 && getBalance(root->right) > 0)
	{
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}
	return root;
}
void pre_order(node* root)
{
	if (root == NULL)
	return;
	cout<<root->data<<" ";
	pre_order(root->left);
	pre_order(root->right);
}
void in_order(node* root)
{
	if (root == NULL)
	return;
	in_order(root->left);
	cout<<root->data<<" ";
	in_order(root->right);
}
void post_order(node* root)
{
	if (root == NULL)
	return;
	post_order(root->left);
	post_order(root->right);
	cout<<root->data<<" ";
}
int main()
{
	node *root = NULL;
	root = insert(root, 14);
	root = insert(root, 17);
	root = insert(root, 11);
	root = insert(root, 7);
	root = insert(root, 53);
	root = insert(root, 4);
	root = insert(root, 13);
	root = insert(root, 12);
	root = insert(root, 8);
	root = insert(root, 60);
	root = insert(root, 19);
	root = insert(root, 16);
	root = insert(root, 20);
	cout<<"\nPre-order:\n";
	pre_order(root);
	cout<<"\nIn-order:\n";
	in_order(root);
	cout<<"\nPost-order:\n";
	post_order(root);
// 	int del;
// 	cout<<"\n\nEnter no. to be deleted: ";
// 	cin>>del;
	root = deleteNode(root, 8);
	root = deleteNode(root, 7);
	root = deleteNode(root, 11);
	cout<<"\n\nAfter deleting: ";
	cout<<"\nPre-order:\n";
	pre_order(root);
	cout<<"\nIn-order:\n";
	in_order(root);
	cout<<"\nPost-order:\n";
	post_order(root);
	return 0;
}
