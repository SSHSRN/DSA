#include <stdio.h>
#include <malloc.h>

// Searching in a BST is really efficient as it has a best case time complexity of O(log n).
// The worst case time complexity is O(n) and it is when we make a skew tree.

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

struct node * searchIterative(struct node * root, int key){
    while(root != NULL){
        if(key == root -> data){
            return root;
        }
        else if(key < root -> data){
            root = root -> left;
        }
        else{
            root = root -> right;
        }
    }
    return NULL;
}


int main(){
    int key;
    // Constructing the root node using function
    struct node * p = createNode(10);

    struct node * p1 = createNode(5);
    struct node * p2 = createNode(15);

    // Linking the root node with left and right children.
    p -> left = p1;
    p -> right = p2;

    printf("Enter the element to search in the Binary Search Tree: ");
    scanf("%d", &key);

    // printf("%d", isBST(p));
    if(isBST(p)){
        printf("The given Binary tree is a Binary Search Tree.\n\n");
    }
    else{
        printf("The given Binary tree is not a Binary Search Tree.\n\n");
    }

    struct node * n = searchIterative(p, key);

    if(n != NULL){
        printf("Element %d is present in the given Binary Search Tree.", n -> data);
    }

    else{
        printf("The element is not found in the given Binary Search Tree.");
    }

    return 0;
}