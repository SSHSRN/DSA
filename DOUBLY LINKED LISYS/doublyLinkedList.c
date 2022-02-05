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

struct Node * insertAtFirst(struct Node * head, int val){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr -> data = val;
    ptr -> next = head;
    ptr -> prev = NULL;
    head = ptr;
    printf("\nInsertion Successful!\n\n");
    return head;
}

struct Node * insertAtIndex(struct Node * head, int val, int index){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node * p = head;
    int i = 0;
    while(i != index-1){
        p = p -> next;
        i+=1;
    }
    ptr -> data = val;
    ptr -> next = p -> next;
    p -> next = ptr;
    ptr -> prev = p;
    (p -> next) -> prev = ptr;
    printf("\nInsertion Successful!\n\n");
    return head;
}

struct Node * insertAtEnd(struct Node * tail, int val){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr -> data = val;
    ptr -> prev = tail;
    tail -> next = ptr;
    ptr -> next = NULL;
    tail = ptr;
    printf("\nInsertion Successful!\n\n");
    return tail;
}

struct Node * insertAfterNode(struct Node * head, struct Node * node, int val){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr -> data = val;
    ptr -> prev = node;
    ptr -> next = node -> next;
    node -> next = ptr;
    (node -> next) -> prev = ptr;
    node = ptr;
    printf("\nInsertion Successful!\n\n");
    return head;
}

int main(){
    //This is a simple demonstration of doubly linked list with 4 elements.
    int choice, val, index;
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

        else if(choice == 1){
            printf("\nInsertion\n\n");
            printf("Enter 0 to insert an element at the beginning.\nEnter 1 to insert an element at a given index.\nEnter 2 to insert an element at the end.\nEnter 3 to insert an element after a particular node.\nEnter your choice: ");
            scanf("%d",&choice);
            if(choice == 0){
                printf("Insertion at the Beginning\n\nEnter the value to insert: ");
                scanf("%d", &val);
                head = insertAtFirst(head, val);
                traverseForward(head);
            }
            else if(choice == 1){
                printf("Insertion at a given Index\n\nEnter the value to insert: ");
                scanf("%d", &val);
                printf("Enter the index to insert: ");
                scanf("%d", &index);
                head = insertAtIndex(head, val, index);
                traverseForward(head);
            }
            else if(choice == 2){
                printf("Insertion at the End\n\nEnter the value to insert: ");
                scanf("%d", &val);
                tail = insertAtEnd(tail, val);
                traverseForward(head);
            }
            else if (choice == 3){
                printf("Insertion after a specific Node\n\nEnter the value to insert: ");
                scanf("%d", &val);
                head = insertAfterNode(head, N2, val);
                traverseForward(head);
            }
        }
    }
}