#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Stacck works by LIFO (Last In First Out) principle...

struct stack{
    int size;
    int top;
    char * arr;
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

int parenthesesMatch(char * exp, int e_size){
    // Create and initialise the stack
    struct stack * sp;
    sp -> size = e_size;
    sp -> top = -1;
    sp -> arr = (char *) malloc (sp -> size * sizeof(char));
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if(exp[i] == '('){
            push(sp, '(');
        }
        else if(exp[i] == ')'){
            if(isEmpty(sp)){
                return 0;
            }
            pop(sp);
        }
    }
    if(isEmpty(sp)){
        return 1;
    }
    else{
        return 0;
    }
    
}

int main(){
    char * exp = "(a*b())";
    int expSize = strlen(exp);

    // Check if parentheses is balanced.
    if(parenthesesMatch(exp, expSize)){
        printf("\nThe parenthesis in the expression is balanced");
    }
    else{
        printf("\nThe parenthesis in the expression is not balanced");
    }
    return 0;
}