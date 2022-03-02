#include <stdio.h>

void traverse(int arr[], int size){
    for (int i = 0; i < size; i++){
        printf("%d\n", arr[i]);
    }
}

void bubbleSort(int arr[], int size){
    int temp;
    int isSorted = 0;
    for (int i = 0; i < size - 1; i++){ // Loop for number of passes.
        isSorted = 1;
        printf("\nPass - %d\n", i + 1);
        for(int j = 0; j < size - i - 1; j++){ // Loop for number of comparisions in each pass.
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                isSorted = 0;
            }
        }
        if(isSorted){
            return;
        }
    }
    
}

int main(){
    int arr[] = {15, 25, 10, 30, 20, 5};
    int size = sizeof(arr)/sizeof(int);
    printf("\nArray before Sorting:\n\n");
    traverse(arr, size); // Array before sorting
    bubbleSort(arr, size); // Sorting the array
    // Bubble sort has a time complexity of O(n^2) for unsorted array and O(n) for sorted array(if made Adaptive.). 
    // Else, the time complexity will be O(n^2) for both cases.
    printf("\nArray after Sorting:\n\n");
    traverse(arr, size); // Array after sorting
    return 0;
}