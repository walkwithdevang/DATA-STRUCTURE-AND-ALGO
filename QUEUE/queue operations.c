#include<stdio.h>
#include<stdlib.h>

/*front points to start of the part of array which marks start of queue. In queue array implementation,
one part of array is taken as queue marked with front and rear markers.*/
/*capacity is the total size of array.*/

struct Queue{
int front,rear,size;
unsigned capacity;
int *array;
};

struct Queue* create_queue(unsigned capacity)
{
    struct Queue* queue=(struct Queue*)malloc(sizeof(struct Queue));
    queue->front=queue->size=0;
    queue->capacity=capacity;

    queue->rear=capacity-1;  /* Note: rear points to last array element in the beginning.*/
    queue->array=(int*)malloc(queue->capacity*sizeof(int));
    return queue;
}

int isFull(struct Queue*queue)
{
    return(queue->size==queue->capacity);
}

int isEmpty(struct Queue*queue)
{
    return(queue->size==0);
}

void enqueue(struct Queue*queue,int data)
{
    if(isFull(queue))
        printf("Queue full\n");

    queue->rear=(queue->rear+1)%(queue->capacity); /*This formula is basically used to return from end of a circular queue to the beginning.
                                                     But here it is used to point rear from (capacity-1) end to the front in enqueue op.*/
    queue->array[queue->rear]=data;
    queue->size=queue->size+1;
    printf("enqueued %d to queue.\n",data);
}

int dequeue(struct Queue*queue)
{
    if(isEmpty(queue))
        printf("Empty queue\n");
    int item;
    item=queue->array[queue->front];
    queue->front=(queue->front+1)%(queue->capacity);/* say capacity=5 so 1%5=1 */
    queue->size=queue->size-1;
    return item;
}
int front(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->front];
}

int rear(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->rear];
}

int main()
{
     struct Queue* queue = create_queue(1000);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    printf("%d dequeued from queue\n\n",
           dequeue(queue));

    printf("Front item is %d\n", front(queue));
    printf("Rear item is %d\n", rear(queue));

    return 0;
}

