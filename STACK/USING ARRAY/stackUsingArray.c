#include <stdio.h>
#include <stdlib.h>

// Stacck works by LIFO (Last In First Out) principle...

struct stack{
    int size;
    int top;
    int * arr;
};

int isEmpty(struct stack * ptr){
    if(ptr -> top == -1){
        return 1; // Stack is empty.
    }
    else{
        return 0;
    }
}

int isFull(struct stack * ptr){
    if(ptr-> top == ptr -> size-1){
        return 1; // Stack is full.
    }
    else{
        return 0;
    }
}

int peek(struct stack * ptr, int pos){
    //Time complexity of Peek operation is O(1).
    if(ptr -> top - pos +1 <0){
        printf("The position entered is Invalid.\n\n");
        return -1;
    }
    else{
        return ptr -> arr[ptr -> top - pos +1];
    }
}

void traverse(struct stack * ptr){
    //Time complexity of Traversal operation is O(n).
    // for(int i = 0; i <= ptr -> top; i++){
    //     printf("%d\n", ptr -> arr[i]);
    // }
    for(int i = 1; i <= ptr -> top +1; i++){
        printf("%d\n", peek(ptr,i));
    }
    printf("\n");
}

void push(struct stack * ptr, int val){
    //Time complexity of Push operation is O(1).
    if(isFull(ptr)){
        printf("Stack Overflow! Cannot push %d to the stack.\n\n", val);
    }
    else{
        ptr -> top++;
        ptr -> arr[ptr -> top] = val;
    }
}

void pop(struct stack * ptr){
    //Time complexity of Pop operation is O(1).
    if(isEmpty(ptr)){
        printf("Stack UnderFlow! Cannot pop from the stack.\n\n");
    }
    else{
        ptr -> top--;
    }
}

int stackTop(struct stack * ptr){
    //Time complexity of stackTop operation is O(1).
    return ptr -> arr[ptr -> top];
}

int stackBottom(struct stack * ptr){
    //Time complexity of stackBottom operation is O(1).
    return ptr -> arr[0];
}

int main(){
    int choice, val, pos;
    // struct stack s;
    // // Size of Stack is 50.
    // s.size = 50;
    // // Top is -1 as the Stack is empty.
    // s.top = -1;
    // // Assigning a memory space for the array in heap.
    // s.arr = (int *) malloc (s.size * sizeof(int));

    // Instead of s, the declaration can also be done with a pointer(*s).
    struct stack *s1 = (struct stack *) malloc (sizeof(struct stack));
    // Size of Stack is 50.
    s1 -> size = 50;
    // Top is -1 as the Stack is empty.
    s1 -> top = -1;
    // Assigning a memory space for the array in heap.
    s1 -> arr = (int *) malloc (s1 -> size * sizeof(int));

    // Pushing a few element manually.
    s1 -> arr[0] = 5;
    s1 -> top++;
    s1 -> arr[1] = 10;
    s1 -> top++;
    s1 -> arr[2] = 15;
    s1 -> top++;
    s1 -> arr[3] = 20;
    s1 -> top++;
    s1 -> arr[4] = 25;
    s1 -> top++;

    while(1){
        printf("Stack operations.\nEnter 0 to Traverse the Stack.\nEnter 1 to Push an element.\nEnter 2 to Pop an element.\nEnter 3 to Peek the stack.\nEnter 4 to find top and bottom of stack.\nEnter 5 to exit.\nEnter your choice: ");
        scanf("%d",&choice);
        if(choice ==0){
            printf("\nTraversal\n\n");
            traverse(s1);
        }

        else if(choice == 1){
            printf("\nPush\n\nEnter the value to insert:");
            scanf("%d", &val);
            push(s1, val);
            traverse(s1);
        }

        else if(choice == 2){
            printf("\nPop\n\n");
            pop(s1);
            traverse(s1);
        }

        else if(choice == 3){
            printf("\nPeek\n\nEnter the position to peek:");
            scanf("%d", &pos);
            // You can also traverse the whole stack by using a for loop in peek.
            val = peek(s1, pos);
            printf("The value at position %d is %d\n\n", pos, val);
        }

        else if(choice == 4){
            printf("The top and the bottom elewments of the stack sre %d and %d respectively.\n\n", stackTop(s1), stackBottom(s1));
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