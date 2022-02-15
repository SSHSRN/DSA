#include <stdio.h>
#include <stdlib.h>

// Stacck works by LIFO (Last In First Out) principle...

struct Node{
    int data;
    struct Node * next;
};

struct stack{
    int size;
    int top;
    struct Node * l;
};

int isEmpty(struct Node * top){
    if(top == NULL){
        return 1; // Stack is empty.
    }
    else{
        return 0;
    }
}

int isFull(struct Node * top){
    struct Node * p = (struct Node *) malloc (sizeof(struct Node));
    if(p == NULL){
        return 1; // Stack is full.
    }
    else{
        return 0;
    }
}

void traverse(struct Node * p){
    //Time complexity of Traversal is O(n).
    printf("The elements of the Linked list are:\n");
    while (p != NULL)
    {
        printf("%d\n", p -> data);
        p = p -> next;
    }
    printf("\nTraversal Successful!");
}

int peek(struct Node * top, int pos){
    //Time complexity of Peek operation is O(n).
    // struct Node * p = top;
    // int i = 0;
    // while(i != (pos - 1)){
    //     p = p -> next;
    //     i+=1;
    // }
    // int val = p -> data;
    // return val;

    // Another approach:
    struct Node * ptr = top;
    for(int i=0; (i < pos - 1 && ptr != NULL); i++){
        ptr = ptr -> next;
    }
    return ptr -> data;
}

struct Node * push(struct Node * top, int val){
    //Time complexity of Push operation is O(1).
    if(isFull(top)){
        printf("Stack Overflow! Cannot push %d to the stack.\n\n", val);
        return top;
    }
    else{
        struct Node * n = (struct Node * ) malloc (sizeof(struct Node));
        n -> data = val;
        n -> next = top;
        top = n;
        return top;
    }
}

struct Node * pop(struct Node * top){
    //Time complexity of Pop operation is O(1).
    if(isEmpty(top)){
        printf("Stack UnderFlow! Cannot pop from the stack.\n\n");
        return top;
    }
    else{
        struct Node * n = top;
        top = top -> next;
        free(n);
        return top;
    }
}

int stackTop(struct Node * top){
    //Time complexity of stackTop operation is O(1).
    return top -> data;
}

int stackBottom(struct Node * top){
    //Time complexity of stackBottom operation is O(1).
    struct Node * p = top;
    while(p -> next != NULL){
        p = p -> next;
    }
    return p -> data;
}

int main(){
    int choice, val, pos;

    struct Node * top = NULL;

    top = push(top, 5);
    top = push(top, 10);
    top = push(top, 15);
    top = push(top, 20);
    top = push(top, 25);

    while(1){
        printf("Stack operations.\nEnter 0 to Traverse the Stack.\nEnter 1 to Push an element.\nEnter 2 to Pop an element.\nEnter 3 to Peek the stack.\nEnter 4 to find top and bottom of stack.\nEnter 5 to exit.\nEnter your choice: ");
        scanf("%d",&choice);
        if(choice ==0){
            printf("\nTraversal\n\n");
            traverse(top);
        }

        else if(choice == 1){
            printf("\nPush\n\nEnter the value to insert:");
            scanf("%d", &val);
            top = push(top, val);
            traverse(top);
        }

        else if(choice == 2){
            printf("\nPop\n\n");
            top = pop(top);
            traverse(top);
        }

        else if(choice == 3){
            printf("\nPeek\n\nEnter the position to peek:");
            scanf("%d", &pos);
            // You can also traverse the whole stack by using a for loop in peek.
            val = peek(top, pos);
            printf("The value at position %d is %d\n\n", pos, val);
        }

        else if(choice == 4){
            printf("The top and the bottom elewments of the stack sre %d and %d respectively.\n\n", stackTop(top), stackBottom(top));
        }

        else if(choice == 5){
            break;
        }
        else{
            printf("\nInvalid input\n");
        }
    }
    return 0;
}