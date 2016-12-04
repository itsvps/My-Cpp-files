// diameter of a binary tree
#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node* lchild;
	struct node* rchild;
};
int max(int a, int b)
{
	if(a>b)
		return a;
	else
		return b;
}
int height(struct node* root)
{
	if(root == NULL)
		return 0;
	else
		return(1 + max(height(root->lchild),height(root->rchild)));
}
struct node* newNode(int newData)
{
	node *temp = new node;
	temp->data = newData;
	temp->lchild = NULL;
	temp->rchild = NULL;
	return temp;
}
int diameter(struct node* root)
{
	int lDiamtr=0,rDiamtr=0,ht=0;
	if(root == NULL)
		return 0;
	else
	{
		lDiamtr = diameter(root->lchild);
		rDiamtr = diameter(root->rchild);
		ht = 1 + height(root->lchild) + height(root->rchild);
		return(max(ht,max(lDiamtr,rDiamtr)));
	}
}
void printTree(struct node* root)
{
	if(root != NULL)
	{
		cout<<root->data<<endl;
		printTree(root->lchild);
		printTree(root->rchild);
	}
}

int main()
{
	cout<<"simple tree:\n";
	struct node* tree;
	tree = newNode(5);
	tree->lchild = newNode(3);
	tree->rchild = newNode(2);
	tree->rchild->lchild = newNode(6);
	printTree(tree);
	int ht = height(tree);
	cout<<"height = "<<ht<<endl;
	int d = diameter(tree);
	cout<<"diameter = "<<d<<endl;
	return 0;
}