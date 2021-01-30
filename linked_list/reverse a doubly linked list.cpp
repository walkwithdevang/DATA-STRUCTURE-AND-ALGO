// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }

};

Node *newNode(int data)
{
    Node *temp=new Node(data);

    return temp;
}




void displayList(Node *head)
{
    //Head to Tail
    while(head->next)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<head->data;



}


int getLength(Node * head)
{
    Node *temp=head;

    int count=0;
    while(temp->next!=head)
    {
        count++;
        temp=temp->next;
    }
    return count+1;
}




bool verify(Node* head)
{
    int fl=0;
    int bl=0;

    Node *temp=head;

    while(temp->next)
    {
        temp=temp->next;
        fl++;
    }

    while(temp->prev)
    {
        temp=temp->prev;
        bl++;
    }

    return fl==bl;
}


 // } Driver Code Ends




/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }

};
*/
Node* reverseDLL(Node * head)
{
    //Your code here
    if(head->next==NULL)
    {
        return head;
    }
    int count;
    struct Node*p;
    struct Node*q;
    struct Node*temp;
    while(head->next!=NULL)
    {
        head=head->next;
        count++;
    }
    p=head;
    q=p->prev;
    while(count!=0)
    {
        struct Node*ptr=new Node(q->data);
        p->next=ptr;
        ptr->prev=p;
        ptr->next=NULL;
        temp=q;
        q=q->prev;
        delete(temp);
        p=p->next;
        count--;
    }
    head->prev=NULL;
    return head;

}

/*Better solution:
Node* reverseDLL(Node * head)
{
  if(head->next==NULL)
  {
      return;
  }
  struct Node*current=head;
  struct Node*temp;
  while(current!=NULL)
  {
      temp=current->prev;
      current->prev=current->next;
      current->next=temp;
      current=current->prev;
  }
  return head;
}
*/

// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    Node *head=NULL, *tail=NULL;
        int x;
	    cin>>x;
	    head = newNode(x);
	    tail = head;

	    for(int i=0;i<n - 1;i++)
	    {
	        cin>>x;
	        Node* temp=newNode(x);
	        tail->next=temp;
	        temp->prev= tail;
	        tail = temp;
	    }
	    head=reverseDLL(head);


	    if(verify(head))
	    displayList(head);
	    else
	    cout<<"Your pointers are not correctly connected";

	    cout<<endl;
	}
	return 0;
}

