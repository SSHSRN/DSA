#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

void traverse(struct Node * ptr){
    //Time complexity of Traversal is O(n).
    printf("The elements of the Linked list are:\n");
    while (ptr != NULL)
    {
        printf("%d\n", ptr -> data);
        ptr = ptr -> next;
    }
    printf("\nTraversal Successful!");
}

struct Node * insertAtFirst(struct Node * head, int val){
    //Time complexity of Insertion at first is O(1).
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr ->data = val;
    ptr ->next = head;
    head = ptr;
    printf("\nInsertion Successful!\n\n");
    return head;
}

struct Node * insertAtIndex(struct Node * head, int val, int index){
    //Time complexity of Insertion at index is O(n).
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
    printf("\nInsertion Successful!\n\n");
    return head;
}

struct Node * insertAtEnd(struct Node * head, int val){
    //Time complexity of Insertion at end is O(n).
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node * p = head;
    ptr ->data = val;
    while((p -> next) != NULL){
        p = p -> next;
    }
    p -> next = ptr;
    ptr -> next = NULL;
    printf("\nInsertion Successful!\n\n");
    return head;
}

struct Node * insertAfterNode(struct Node * head, struct Node * prevNode,int val){
    //Time complexity of Insertion after a given node is O(1).
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr ->data = val;
    ptr -> next = prevNode -> next;
    prevNode -> next = ptr;
    printf("\nInsertion Successful!\n\n");
    return head;
}

struct Node * deleteFirst(struct Node * head){
    //Time complexity of Deleting the first node is O(1).
    struct Node * ptr = head;
    head = head -> next;
    free(ptr);
    printf("\nDeletion Successful!\n\n");
    return head;
}

struct Node * deleteAtIndex(struct Node * head, int index){
    //Time complexity of Deletion at index is O(n).
    struct Node * p = head;
    int i = 0;
    while(i != (index - 1)){
        p = p -> next;
        i+=1;
    }
    struct Node * ptr = p -> next;
    p -> next = ptr -> next;
    free(ptr);
    printf("\nDeletion Successful!\n\n");
    return head;
}

struct Node * deleteLast(struct Node * head){
    //Time complexity of Deletion at last is O(n).
    struct Node * p = head;
    struct Node * ptr = p -> next;
    while((ptr->next)!=NULL){
        p = p -> next;
        ptr = ptr -> next;
    }
    p -> next = NULL;
    free(ptr);
    return head;
}

struct Node * deleteByValue(struct Node * head, int val){
    //Time complexity of Deletion by value is O(n).
    struct Node * p = head;
    struct Node * ptr = p -> next;
    if(p -> data ==val){
        head = deleteFirst(head);
        return head;
    }
    else{
        while(ptr -> data != val && ptr -> next!= NULL){
            ptr = ptr -> next;
            p = p-> next;
        }
        if(ptr->data == val){
            p -> next = ptr -> next;
            free(ptr);
            printf("\nDeletion Successful!\n\n");
            return head;
        }
        else{
            printf("\nDeletion Unuccessful as the given value %d is not found in the Linked list!\n\n", val);
            return head;
        }
    }
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

    while(1){
        printf("Linked list operations.\nEnter 0 to Traverse the Linked list.\nEnter 1 to Insert an element.\nEnter 2 to Delete an element.\nEnter 3 to exit.\nEnter your choice: ");
        scanf("%d",&choice);
        if(choice == 0){
            printf("\nTraversal\n\n");
            traverse(head);
        }
        else if(choice ==1){
            printf("\nInsertion\n\n");
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
        else if(choice ==2){
            printf("\nDeletion\n\n");
            printf("Enter 0 to delete the first node.\nEnter 1 to delete the node at a given index.\nEnter 2 to delete the last node.\nEnter 3 to delete a node by value.\nEnter your choice: ");
            scanf("%d",&choice);
            if(choice == 0){
                printf("\nDeletion of first node\n\n");
                head = deleteFirst(head);
                traverse(head);
            }
            else if(choice ==1){
                printf("\nDeletion at a given Index\n\nEnter the index to delete: ");
                scanf("%d", &index);
                head = deleteAtIndex(head,index);
                traverse(head);
            }
            if(choice == 2){
                head = deleteLast(head);
                traverse(head);
            }
            if(choice == 3){
                printf("\nDeletion by Value\n\nEnter the value to delete: ");
                scanf("%d", &val);
                head = deleteByValue(head,val);
                traverse(head);
            }
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