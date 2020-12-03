#include<stdio.h>
#include<stdlib.h>

struct qnode
{
    int key;
    struct qnode*next;
};

struct Queue
{
    struct linkedlist*front;
    struct linkedlist*rear;
};

struct qnode* newnode(int data)
{
    struct qnode*new_node=(struct qnode*)malloc(sizeof(struct qnode));
    new_node->key=data;
    new_node->next=NULL;
    return new_node;
}

struct Queue* createqueue()
{
    struct Queue*new_queue=(struct Queue*)malloc(sizeof(struct queue));
    new_queue->front=new_queue->rear=NULL;
    return new_queue;
}

void enqueue(struct Queue*queue,int data)
{
    struct qnode*node=newnode(data);
    if(queue->rear==NULL)
    {
        queue->front=queue->rear=node;
        return;
    }
    queue->rear->next=node;
    queue->rear=newnode;
}

struct

