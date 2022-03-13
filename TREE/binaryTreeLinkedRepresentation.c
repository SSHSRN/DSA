#include <stdio.h>
#include <malloc.h>

struct node{
    int data;
    struct node * left;
    struct node * right;
};

struct node * createNode(int value){
    struct node * p; // Creating a node pointer
    p = (struct node *) malloc (sizeof(struct node)); // Allocating memory in the heap
    p -> data = value; // Setting the data of the node
    p -> left = NULL; // Setting the left child to NULL
    p -> right = NULL; // Setting the right child to NULL
    return p; // Returning the node
}

int main(){
    // Constructing the root node using function
    struct node * p = createNode(5);

    struct node * p1 = createNode(10);
    struct node * p2 = createNode(15);

    // Linking the root node with left and right children.
    p -> left = p1;
    p -> right = p2;
    return 0;
}