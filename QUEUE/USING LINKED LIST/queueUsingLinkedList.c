#include <stdio.h>
#include <stdlib.h>

// Declaring front and rear as global variables.
struct Node * front = NULL;
struct Node * rear = NULL;

struct Node{
    int data;
    struct Node * next;
};

void traverse(struct Node * ptr){
    while(ptr != NULL){
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

void enqueue(int val){
    struct Node * n = (struct Node *)malloc(sizeof(struct Node));
    if(n == NULL){
        printf("The queue is already full.\n\n");
    }
    else{
        n->data = val;
        n->next = NULL;
        if(front == NULL){
            front = rear = n;
        }
        else{
            rear->next = n;
            rear = n;
        }
    }
}

int dequeue(){
    int val = -1;
    struct Node * ptr = front;
    if(front == NULL){
        printf("The queue is empty.\n\n");
    }
    else{
        front = front->next;
        val = ptr->data;
        free(ptr);
    }
    return val;
}

int main(){
    int choice, val;
    //Enqueue a few items  
    enqueue(5);
    enqueue(10);
    enqueue(15);
    enqueue(20);

    while(1){
        printf("Queue operations.\nEnter 0 to Traverse the Queue.\nEnter 1 to Enqueue.\nEnter 2 to Dequeue.\nEnter 3 to exit.\nEnter your choice: ");
        scanf("%d",&choice);
        if (choice == 0){
            printf("\nTraversal\n\n");
            traverse(front);
        }

        else if(choice == 1){
            printf("\nEnqueue\n\nEnter the value to insert:");
            scanf("%d", &val);
            enqueue(val);
            traverse(front);
        }

        else if(choice == 2){
            printf("\nDequeue\n\n");
            dequeue();
            traverse(front);
        }

        else if(choice == 3){
            break;
        }
        else{
            printf("\nInvalid input\n\n");
        }
    }
    return 0;
}