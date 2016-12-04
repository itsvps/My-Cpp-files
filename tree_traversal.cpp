#include<iostream>
using namespace std;

struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
};

struct Node* newNode(int ch)
{
	Node *temp = new Node;
	temp->data = ch;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void preOrderTraversal(Node *root)
{
	if(root == NULL)
		return;
	cout<<root->data<<" ";
	preOrderTraversal(root->left);
	preOrderTraversal(root->right);
}

void inOrderTraversal(Node *root)
{
	if(root == NULL)
		return;
	inOrderTraversal(root->left);
	cout<<root->data<<" ";
	inOrderTraversal(root->right);
}

void postOrderTraversal(Node *root)
{
	if(root == NULL)
		return;
	postOrderTraversal(root->left);
	postOrderTraversal(root->right);
	cout<<root->data<<" ";
}

int main()
{
	cout<<"Tree traversal:\n";
	Node *tree = newNode(5);
	tree->left = newNode(2);
	tree->right = newNode(3);
	tree->left->left = newNode(4);
	tree->left->right = newNode(7);
	tree->right->left = newNode(6);
	tree->right->right = newNode(8);

	cout<<"\nPreOrder Traversal :\n";
	preOrderTraversal(tree);
	cout<<"\nInOrder Traversal :\n";
	inOrderTraversal(tree);
	cout<<"\nPostOrder Traversal :\n";
	postOrderTraversal(tree);
	return 0;
}