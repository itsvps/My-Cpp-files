#include<bits/stdc++.h>
 
using namespace std;
 
struct node
{
    int data;
    struct node* next;
};
 
typedef struct node Node;
 
Node* newNode(int data)
{
    Node* newN=new Node;
    newN->data=data;
    newN->next=NULL;
    return newN;
}
 
void push(Node* &head,int data)
{
    Node* newN=newNode(data);
    newN->next=head;
    head=newN;
}
 
void printList(Node* head)
{
    while(head)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
 
Node* SortedMerge(Node* a,Node* b)
{
    if(!a&&!b)
        return NULL;
    if(!a)
        return b;
    if(!b)
        return a;
 
    Node dummy;
    Node* tail=&dummy;
    dummy.next=NULL;
 
    while(a&&b)
    {
        if(a->data<=b->data)
        {
            tail->next=a;
            a=a->next;
        }
        else
        {
            tail->next=b;
            b=b->next;
        }
        tail=tail->next;
    }
    return dummy.next;
}
 
int main()
{
    struct node* res = NULL;
    struct node* a = NULL;
    struct node* b = NULL;
 
    /* Let us create two sorted linked lists to test
      the functions
       Created lists, a: 5->10->15,  b: 2->3->20 */
    push(a, 15);
    push(a, 10);
    push(a, 5);
 
    push(b, 20);
    push(b, 3);
    push(b, 2);
 
    /* Remove duplicates from linked list */
    res = SortedMerge(a, b);
 
    printf("Merged Linked List is: \n");
    printList(res);
    return 0;
}