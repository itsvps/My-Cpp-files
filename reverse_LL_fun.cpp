/* Linked List Node structure
   struct Node  {
     int data;
     struct Node *next;
  }
*/

// Should reverse list and return new head.
struct Node* reverse(struct Node *head)
{
  // Your code here
  if(head != NULL && head->next != NULL)
  {
      struct Node *nxtPtr, *pvPtr;
      nxtPtr = head;
      pvPtr = NULL;
      while(1)
      {
          nxtPtr = head->next;
          head->next = pvPtr;
          pvPtr = head;
          if(!nxtPtr)
             break;
          head = nxtPtr;
      }
  }
  return head;
}