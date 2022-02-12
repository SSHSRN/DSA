#include <stdio.h>

void traverse(int array[],int arraysize){
    printf("\nElements of the array are:\n");
    for(int i=0; i<arraysize;i++){
        printf("%d\n", array[i]);
    }
}

int indInsert(int arr[], int size, int element, int capacity, int index){
    if(size>=capacity){
        return -1;
    }
    for (int i = size-1; i >= index; i--){
        arr[i+1] = arr[i];
    }
    arr[index] = element;
    return 1;
}

int indDelete(int arr[], int size, int index){
    if(index>=size){
        return -1;
    }
    for (int i = index; i < size; i++){
        arr[i] = arr[i+1];
    }
    return 1;
}

int main(){
    int arrsize, choice, ind, element, arr[100];
    printf("\nEnter the array size (<100): ");
    scanf("%d", &arrsize);
    for(int i=0;i<arrsize;i++){
        printf("\nEnter element %d: ", i+1);
        scanf("%d",&arr[i]);
    }

    printf("Array Operations\nPress 0 to Traverse the Array\nPress 1 to insert an element\nPress 2 to delete an element");
    printf("\nEnter your Choice: ");
    scanf("%d",&choice);
    
    if(choice ==0){
        /*Traversal*/
        traverse(arr,arrsize);
    }

    else if(choice ==1){
        /*Insertion*/
        printf("\nTraversal Successful!\n");
        printf("Enter the index for insertion: ");
        scanf("%d", &ind);
        printf("Enter the value to insert: ");
        scanf("%d", &element);
        int res = indInsert(arr, arrsize, element, 100, ind);
        arrsize+=1;
        if(res ==1){
            printf("Insertion was successful");
            traverse(arr,arrsize);
        }
        else{
            printf("Insertion Failed");
        }
    }

    else if(choice ==2){
        /*Deletion*/
        printf("Enter the index for deletion: ");
        scanf("%d", &ind);
        int res = indDelete(arr, arrsize, ind);
        arrsize-=1;
        if(res ==1){
            printf("Deletion was successful");
            traverse(arr,arrsize);
        }
        else{
            printf("Deletion Failed");
        }
    }
    return 0;
}
