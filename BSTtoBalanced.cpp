#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

node *newNode(int ch)
{
	node *temp = new node;
	temp->data = ch;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void inOrderTraversal(node *root, int *array)
{
	if(root == NULL)
		return;
	else
	{
		inOrderTraversal(root->left, array);
		cout<<root->data<<" ";
		*array = root->data;
		array++;
		inOrderTraversal(root->right, array);
	}
}

int main()
{
	node *tree = newNode(4);
	tree->left = newNode(2);
	tree->left->left = newNode(1);
	tree->left->right = newNode(3);
	tree->right = newNode(6);
	tree->right->left = newNode(5);
	tree->right->right = newNode(7);

	int *arr = (int*)malloc(sizeof(int)*10);
	inOrderTraversal(tree,arr);
    while(arr != NULL)
    {
    	cout<<*arr;
    	arr++;
    }
	return 0;
}