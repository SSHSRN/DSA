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

char pop(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else{
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
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

int precedence(char ch){
    if(ch == '*' || ch == '/'){
        return 3;
    }
    else if(ch == '+' || ch == '-'){
        return 2;
    }
    else{
        return 0;
    }
}

int isOperator(char ch){
    if(ch=='+' || ch=='-' || ch=='*' || ch=='/'){
        return 1;
    }
    else{
        return 0;
    }
}

char * infix2postfix(char * infix){
    struct stack * sp = (struct stack *)malloc(sizeof(struct stack));
    sp -> size = 10;
    sp -> top = -1;
    sp -> arr = (char *) malloc (sp -> size * sizeof(char));
    char * postfix = (char *) malloc (strlen(infix + 1) * sizeof(char));
    int i = 0; // Track infix traversal.
    int j = 0; // Track postfix appending.
    while (infix[i] != '\0'){
        if(!isOperator(infix[i])){
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else{
            if (precedence(infix[i]) > precedence(stackTop(sp))){
                push(sp, infix[i]);
                i++;
            }
            else{
                postfix[j] = pop(sp);
                j++;
            }
        }
    }
    while(!isEmpty(sp)){
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

int main(){
    char * infix = "a/b*c+d*e-f";
    printf("The given infix expression is: %s", infix);
    printf("\nThe postfix equivalent of the given expression is: %s", infix2postfix(infix));
    return 0;
}