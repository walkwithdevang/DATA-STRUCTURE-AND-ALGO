#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node*left;
    struct node*right;
};

struct node*new_node(int data)
{
    struct node*new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=data;
    new_node->left=new_node->right=NULL;
    return new_node;
}
int getHeight(struct node*root)
{
    if(root==NULL)
    {
        return -1;
    }
    int lheight,rheight;
    lheight=getHeight(root->left);
    rheight=getHeight(root->right);
    if(lheight>rheight)
    {
        return(lheight+1);
    }
    else{
        return(rheight+1);
    }
}

int main()
{
    struct node *root = new_node(1);

    root->left = new_node(2);
    root->right = new_node(3);
    root->left->left = new_node(4);
    root->left->right = new_node(5);

    printf("Height of tree is %d", getHeight(root));

    getchar();
    return 0;
}
