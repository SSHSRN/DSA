#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

void traverse(struct Node * ptr){
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr -> data);
        ptr = ptr -> next;
    }
}

struct Node * insertAtFirst(struct Node * head, int val){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr ->data = val;
    ptr ->next = head;
    head = ptr;
    printf("Insertion Successful!\n");
    return head;
}

struct Node * insertAtIndex(struct Node * head, int val, int index){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node * p = head;
    int i = 0;
    while(i != (index - 1)){
        p = p -> next;
        i+=1;
    }
    ptr -> data = val;
    ptr -> next = p -> next;
    p -> next = ptr;
    printf("Insertion Successful!\n");
    return head;
}

struct Node * insertAtEnd(struct Node * head, int val){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node * p = head;
    ptr ->data = val;
    while((p -> next) != NULL){
        p = p -> next;
    }
    p -> next = ptr;
    ptr -> next = NULL;
    printf("Insertion Successful!\n");
    return head;
}

struct Node * insertAfterNode(struct Node * head, struct Node * prevNode,int val){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr ->data = val;
    ptr -> next = prevNode -> next;
    prevNode -> next = ptr;
    printf("Insertion Successful!\n");
    return head;
}

int main(){
    //This is a simple demonstration of linked list with 3 elements.
    int choice, val, index;
    struct Node * head;
    struct Node * second;
    struct Node * third;

    //Allocate memory for nodes in the linked list in Heap.
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    head -> data = 7;
    head -> next = second;
    second -> data = 11;
    second -> next =third;
    third -> data = 22;
    third -> next = NULL;

    printf("Linked list operations.\nEnter 0 to Traverse the Linked list..\nEnter 1 to Insert an element.\nEnter your choice: ");
    scanf("%d",&choice);
    if(choice == 0){
        traverse(head);
    }
    else if(choice ==1){
        printf("Enter 0 to insert an element at the beginning.\nEnter 1 to insert an element at a given index.\nEnter 2 to insert an element at the end.\nEnter 3 to insert an element after a particular node.\nEnter your choice: ");
        scanf("%d",&choice);
        if(choice == 0){
            printf("Insertion at the Beginning\n\nEnter the value to insert: ");
            scanf("%d", &val);
            head = insertAtFirst(head, val);
            traverse(head);
        }
        else if(choice == 1){
            printf("Insertion at a given Index\n\nEnter the value to insert: ");
            scanf("%d", &val);
            printf("Enter the index to insert: ");
            scanf("%d", &index);
            head = insertAtIndex(head, val, index);
            traverse(head);
        }
        else if(choice == 2){
            printf("Insertion at the End\n\nEnter the value to insert: ");
            scanf("%d", &val);
            head = insertAtEnd(head, val);
            traverse(head);
        }
        else if(choice == 3){
            printf("Insertion after a specific Node\n\nEnter the value to insert: ");
            scanf("%d", &val);
            head = insertAfterNode(head, second, val);
            traverse(head);
        }
    }
    return 0;
}