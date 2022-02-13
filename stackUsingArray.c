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

void traverse(struct stack * ptr){
    for(int i = 0; i <= ptr -> top; i++){
        printf("%d\n", ptr -> arr[i]);
    }
}

void push(struct stack * ptr, int val){
    if(isFull(ptr)){
        printf("Stack Overflow! Cannot push %d to the stack.\n\n", val);
    }
    else{
        ptr -> top++;
        ptr -> arr[ptr -> top] = val;
    }
}

void pop(struct stack * ptr){
    if(isEmpty(ptr)){
        printf("Stack UnderFlow! Cannot pop from the stack.\n\n");
    }
    else{
        ptr -> top--;
    }
}

int main(){
    int choice, val;
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
        printf("Stack operations.\nEnter 0 to Traverse the Stack.\nEnter 1 to Push an element.\nEnter 2 to Pop an element.\nEnter your choice: ");
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
            break;
        }
        else{
            printf("\nInvalid input\n");
        }
    }
    return 0;
}