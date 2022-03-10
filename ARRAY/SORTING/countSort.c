#include <stdio.h>
#include <stdlib.h>

void traverse(int arr[], int size){
    for (int i = 0; i < size; i++){
        printf("%d\n", arr[i]);
    }
}

void countSort(int arr[], int size){
    int i,j;
    // Find the max element in the array.
    int maxVal = 0;
    for(i =0; i < size; i++){
        if(arr[i] > maxVal){
            maxVal = arr[i];
        }
    }

    // Create the count array
    int * count = (int *)malloc((maxVal+1)*sizeof(int));
    // Initialize the array elements to 0
    for (i = 0; i < maxVal+1; i++){
        count[i] = 0;
    }

    // Incrementing the corresponding index in the count array.
    for (i = 0; i < size; i++){
        count[arr[i]] += 1;
    }

    i = 0; // Counter for count array
    j = 0; // Counter for main array

    while(i < maxVal+1){
        if(count[i] > 0){
            arr[j] = i;
            count[i] -= 1;
            j++;
        }
        else{
            i++;
        }
    }
}

int main(){
    int arr[] = {15, 25, 10, 30, 20, 5};
    int size = sizeof(arr)/sizeof(int);
    printf("\nArray before Sorting:\n\n");
    traverse(arr, size); // Array before sorting
    countSort(arr, size); // Sorting the array
    printf("\nArray after Sorting:\n\n");
    traverse(arr, size); // Array after sorting
    return 0;
}