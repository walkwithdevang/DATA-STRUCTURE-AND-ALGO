#include<iostream>
#include<queue>

using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
};

void levelorder(Node*root)
{
    if(root==NULL) return;
    queue<Node*>q;
    q.push(root);
    while(!q.empty())
    {
        Node*current=q.front();
        cout<<current->data<<" ";
        if(current->left)
            q.push(current->left);
        if(current->right)
            q.push(current->right);
        q.pop();

    }
}
Node* newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

int main()
{

    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);

    levelorder(root);
    return 0;
}
