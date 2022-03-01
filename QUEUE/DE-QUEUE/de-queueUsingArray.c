#include <stdio.h>
#include <stdlib.h>

// Stacck works by LIFO (Last In First Out) principle...

struct queue{
    int size, front, rear;
    int * arr;
};

int isFull(struct queue * q){
    return (q->rear == q->size-1) ? 1:0;
}

int isEmpty(struct queue * q){
    return (q->front == q->rear) ? 1:0;
}

void traverse(struct queue q){
    for(int i = q.front + 1; i <= q.rear; i++){
        printf("%d\n", q.arr[i]);
    }
    printf("\n");
}

void enqueueFront(struct queue * q, int val){
    if(isFull(q)){
        printf("Queue Overflow!\n\n");
    }
    else{
        if(q->front == -1){
            printf("Enqueue at front is not possible for this queue.\n\n");
        }
        else{
            q->front--;
            q->arr[q->front] = val;
        }
    }
}

void enqueueRear(struct queue * q, int val){
    if(isFull(q)){
        printf("Queue Overflow!\n\n");
    }
    else{
        q->rear++;
        q->arr[q->rear] = val;
    }
}

int dequeueFront(struct queue * q){
    int a = -1;
    if(isEmpty(q)){
        printf("Queue Underflow! There is no element to dequeue.\n\n");
    }
    else{
        q->front++;
        a = q->arr[q->front];
    }
    return a;
}

int dequeueRear(struct queue * q){
    int a = -1;
    if(isEmpty(q)){
        printf("Queue Underflow! There is no element to dequeue.\n\n");
    }
    else{
        q->rear--;
        a = q->arr[q->rear];
    }
    return a;
}

int main(){
    int choice, val, i;
    struct queue q;
    q.size = 50;
    q.front = q.rear = -1;
    q.arr = (int * ) malloc (q.size * sizeof(int));
    //Enqueue a few items  
    enqueueRear(&q, 5);
    enqueueRear(&q, 10);
    enqueueRear(&q, 15);
    enqueueRear(&q, 20);
    enqueueRear(&q, 25);

    while(1){
        printf("Queue operations.\nEnter 0 to Traverse the Queue.\nEnter 1 to Enqueue at front.\nEnter 2 to Enqueue at rear.\nEnter 3 to Dequeue aat front.\nEnter 4 to Dequeue at rear.\nEnter 5 to find front and rear element of queue.\nEnter 6 to exit.\nEnter your choice: ");
        scanf("%d",&choice);
        if (choice == 0){
            printf("\nTraversal\n\n");
            traverse(q);
        }

        else if(choice == 1){
            printf("\nEnqueue at front\n\nEnter the value to insert:");
            scanf("%d", &val);
            enqueueFront(&q, val);
            traverse(q);
        }

        else if(choice == 2){
            printf("\nEnqueue at rear\n\nEnter the value to insert:");
            scanf("%d", &val);
            enqueueRear(&q, val);
            traverse(q);
        }

        else if(choice == 3){
            printf("\nDequeue at front\n\n");
            dequeueFront(&q);
            traverse(q);
        }

        else if(choice == 4){
            printf("\nDequeue at rear\n\n");
            scanf("%d", &val);
            dequeueRear(&q);
            traverse(q);
        }

        else if(choice == 5){
            printf("\nFront and Rear\n\n");
            printf("The front and rear elements are: %d and %d respectively\n\n", q.arr[q.front+1],q.arr[q.rear]);
        }

        else if(choice == 6){
            break;
        }

        else{
            printf("\nInvalid input\n\n");
        }
    }
    return 0;
}