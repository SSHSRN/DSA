#include <stdio.h>
#include <stdlib.h>

/*A disadvantage of using doubly linked list is that it's not space efficient.
While singly linked list needs 2 fields for each node, doubly linked list requires 3...

Doubly linked list is useful when you have to traverse in both forward and reverse directions.*/
struct Node{
    int data;
    struct Node * prev;
    struct Node * next;
};

void traverseForward(struct Node * head){
    struct Node * ptr = head;
    printf("The elements of the Linked list are:\n");
    while (ptr != NULL){
        printf("%d\n", ptr -> data);
        ptr = ptr -> next;
    }
    printf("\nTraversal Successful!\n\n");
}

void traverseBackward(struct Node * tail){
    struct Node * ptr = tail;
    printf("The elements of the Linked list are:\n");
    while (ptr != NULL){
        printf("%d\n", ptr -> data);
        ptr = ptr -> prev;
    }
    printf("\nTraversal Successful!\n\n");
}


int main(){
    //This is a simple demonstration of doubly linked list with 4 elements.
    int choice;
    struct Node * head;
    struct Node * tail;
    // Declare and Allocate memory for nodes in the linked list in Heap.
    struct Node * N1 = (struct Node *)malloc(sizeof(struct Node));
    struct Node * N2 = (struct Node *)malloc(sizeof(struct Node));
    struct Node * N3 = (struct Node *)malloc(sizeof(struct Node));
    struct Node * N4 = (struct Node *)malloc(sizeof(struct Node));
    N1 -> prev = NULL;
    N1 -> data = 2;
    N1 -> next = N2;
    N2 -> prev = N1;
    N2 -> data = 4;
    N2 -> next = N3;
    N3 -> prev = N2;
    N3 -> data = 6;
    N3 -> next = N4;
    N4 -> prev = N3;
    N4 -> data = 8;
    N4 -> next = NULL;
    head = N1;
    tail = N4;
    while(1){
        printf("Doubly Linked list operations.\nEnter 0 to Traverse the Linked list.\nEnter 1 to Insert an element.\nEnter 2 to Delete an element.\nEnter 3 to exit.\nEnter your choice: ");
        scanf("%d",&choice);
        if(choice == 0){
            printf("\nTraversal\n\n");
            printf("Enter 0 to traverse from head.\nEnter 1 to traverse from tail.\nEnter your choice: ");
            scanf("%d",&choice);
            if(choice == 0){
                traverseForward(head);
            }
            else if (choice == 1){
                traverseBackward(tail);
            }
        }
    }
}