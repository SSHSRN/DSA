#include <stdio.h>

void traverse(int arr[], int size){
    for (int i = 0; i < size; i++){
        printf("%d\n", arr[i]);
    }
}

void insertionSort(int arr[], int size){
    int key, j;
    for (int i = 1; i <= size - 1; i++){ // Loop for passes.
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key){ // Loop for each pass.
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main(){
    int arr[] = {15, 25, 10, 30, 20, 5};
    int size = sizeof(arr)/sizeof(int);
    printf("\nArray before Sorting:\n\n");
    traverse(arr, size); // Array before sorting
    insertionSort(arr, size); // Sorting the array
    // Insertion sort has a time complexity of O(n^2) for unsorted array and O(n) for sorted array. 
    printf("\nArray after Sorting:\n\n");
    traverse(arr, size); // Array after sorting
    return 0;
}