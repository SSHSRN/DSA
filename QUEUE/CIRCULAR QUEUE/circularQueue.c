#include <stdio.h>
#include <stdlib.h>

// Stacck works by LIFO (Last In First Out) principle...

struct cqueue{
    int size, front, rear;
    int * arr;
};

int isFull(struct cqueue * q){
    return ((q->rear+1) % q -> size == q -> front) ? 1:0;
}

int isEmpty(struct cqueue * q){
    return (q->front == q->rear) ? 1:0;
}

void traverse(struct cqueue q){
    for(int i = q.front + 1; i <= q.rear; i++){
        printf("%d\n", q.arr[i]);
    }
    printf("\n");
}

void enqueue(struct cqueue * q, int val){
    if(isFull(q)){
        printf("Queue Overflow!\n\n");
    }
    else{
        q->rear = (q->rear + 1) % q->size;
        q->arr[q->rear] = val;
    }
}

int dequeue(struct cqueue * q){
    int a = -1;
    if(isEmpty(q)){
        printf("Queue Underflow! There is no element to dequeue.\n\n");
    }
    else{
        q->front = (q->front + 1) % q->size;
        a = q->arr[q->front];
    }
    return a;
}


int main(){
    int choice, val, i;
    struct cqueue q;
    q.size = 50; // this is a circular queue, it can only have (size - 1) elements.[Here, 49.]
    q.front = q.rear = 0; // In circular queue, the front and rear are initially set to 0 and not -1.
    q.arr = (int * ) malloc (q.size * sizeof(int));
    //Enqueue a few items  
    enqueue(&q, 5);
    enqueue(&q, 10);
    enqueue(&q, 15);
    enqueue(&q, 20);
    enqueue(&q, 25);

    while(1){
        printf("Circular Queue operations.\nEnter 0 to Traverse the Queue.\nEnter 1 to Enqueue.\nEnter 2 to Dequeue.\nEnter 3 to find front and rear element of queue.\nEnter 4 to exit.\nEnter your choice: ");
        scanf("%d",&choice);
        if (choice == 0){
            printf("\nTraversal\n\n");
            traverse(q);
        }

        else if(choice == 1){
            printf("\nEnqueue\n\nEnter the value to insert:");
            scanf("%d", &val);
            enqueue(&q, val);
            traverse(q);
        }

        else if(choice == 2){
            printf("\nDequeue\n\n");
            dequeue(&q);
            traverse(q);
        }
        else if(choice == 3){
            printf("\nFront and Rear\n\n");
            printf("The front and rear elements are: %d and %d respectively\n\n", q.arr[q.front+1],q.arr[q.rear]);
        }

        else if(choice == 4){
            break;
        }
        else{
            printf("\nInvalid input\n\n");
        }
    }
    return 0;
}