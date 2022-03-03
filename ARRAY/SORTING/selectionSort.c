#include <stdio.h>

void traverse(int arr[], int size){
    for (int i = 0; i < size; i++){
        printf("%d\n", arr[i]);
    }
}

void selectionSort(int arr[], int size){
    int minidx, temp;
    for (int i = 0; i < size - 1; i++){
        minidx = i;
        for (int j = i+1; j < size; j++){
            if (arr[j] < arr[minidx]){
                minidx = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[minidx];
        arr[minidx] = temp;
    }
    
}

int main(){
    int arr[] = {15, 25, 10, 30, 20, 5};
    int size = sizeof(arr)/sizeof(int);
    printf("\nArray before Sorting:\n\n");
    traverse(arr, size); // Array before sorting
    selectionSort(arr, size); // Sorting the array
    // Selection sort has a time complexity of O(n^2) for unsorted array and O(n) for sorted array. 
    printf("\nArray after Sorting:\n\n");
    traverse(arr, size); // Array after sorting
    return 0;
}