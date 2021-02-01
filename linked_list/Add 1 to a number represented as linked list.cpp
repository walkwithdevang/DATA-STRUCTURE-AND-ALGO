// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node)
{
    while (node != NULL) {
        cout << node->data;
        node = node->next;
    }
    cout<<"\n";
}

Node* addOne(Node *head);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;

        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }

        head = addOne(head);
        printList(head);
    }
    return 0;
}
// } Driver Code Ends


//User function template for C++

/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

Node* addOne(Node *head)
{
    // Your Code here
    // return head of list after adding one
    struct Node*curr=head;
    struct Node*prev=NULL;
    struct Node*temp=NULL;
    while(curr!=NULL)
    {
        temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
    head=prev;
    struct Node*p=head;
    if(p->data==9)
    {
    while(p->data==9 )
    {
        p->data=0;
        if(p->next==NULL)
        {
            p->data=10;
            break;
        }
        p=p->next;
    }
    if(p->data!=10)
    {
    p->data=p->data+1;
    }
    }
    else{
        p->data=p->data+1;
    }
    curr=head;
    prev=NULL;
    temp=NULL;
    while(curr!=NULL)
    {
        temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
    head=prev;


    return head;
}
