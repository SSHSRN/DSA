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

void insert(struct node * root, int value){
    struct node * prev = NULL;
    while(root != NULL){
        prev = root;
        if(value == root -> data){
            return;
        }
        else if(value < root -> data){
            root = root -> left;
        }
        else{
            root = root -> right;
        }
    }
    struct node * new = createNode(value);
    if(value < prev -> data){
        prev -> left = new;
    }
    else{
        prev -> right = new;
    }
}

int isBST(struct node * root){
    static struct node * prev = NULL;
    // We use static variable so that the value of the variable does not change with each recursive call of the function.
    if(root != NULL){
        if(!isBST(root -> left)){
            return 0;
        }
        if(prev != NULL && root -> data <= prev -> data){
            return 0;
        }
        prev = root;
        return isBST(root -> right);

    }
    else{
        return 1;
    }
}


int main(){
    // Constructing the root node using function
    struct node * p = createNode(10);

    struct node * p1 = createNode(5);
    struct node * p2 = createNode(15);

    // Linking the root node with left and right children.
    p -> left = p1;
    p -> right = p2;

    insert(p, 25);
    insert(p, 20);

    // printf("%d", isBST(p));
    if(isBST(p)){
        printf("The given Binary tree is a Binary Search Tree.");
    }
    else{
        printf("The given Binary tree is not a Binary Search Tree.");
    }
    return 0;
}