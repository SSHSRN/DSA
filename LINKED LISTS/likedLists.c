#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

void linkedListTraversal(struct Node * ptr){
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr -> data);
        ptr = ptr -> next;
    }
}

int main(){
    //This is a simple demonstration of linked list with 3 elements.
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
    linkedListTraversal(head);
    return 0;
}