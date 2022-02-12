#include <stdio.h>
#include <stdlib.h>

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

int main(){
    // struct stack s;
    // // Size of Stack is 50.
    // s.size = 50;
    // // Top is -1 as the Stack is empty.
    // s.top = -1;
    // // Assigning a memory space for the array in heap.
    // s.arr = (int *) malloc (s.size * sizeof(int));

    // Instead of s, the declaration can also be done with a pointer(*s).
    struct stack *s1;
    // Size of Stack is 50.
    s1 -> size = 50;
    // Top is -1 as the Stack is empty.
    s1 -> top = -1;
    // Assigning a memory space for the array in heap.
    s1 -> arr = (int *) malloc (s1 -> size * sizeof(int));

    // Pushing an element manually.
    // s1 -> arr[0] = 5;
    // s1 -> top++;

    // Check if stack is empty.
    if(isEmpty(s1)){
        printf("\nStack is Empty!\n\n");
    }
    else{
        printf("\nStack is not Empty!\n\n");
    }

    // Check if stack is full.
    if(isFull(s1)){
        printf("\nStack is Full!\n\n");
    }
    else{
        printf("\nStack is not Full!\n\n");
    }
    return 0;
}