#include <stdio.h>

void traverse(int arr[], int size){
    for (int i = 0; i < size; i++){
        printf("%d\n", arr[i]);
    }
}

int partition(int arr[], int low, int high){
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    int temp;

    do{
        while(arr[i] <= pivot){
            i++;
        }

        while(arr[j] > pivot){
            j--;
        }

        if(i < j){
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while (i < j);

    // Swapping arr[low] and arr[j].
    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j;
}

void quickSort(int arr[], int low, int high){
    int partitionIndex; // Index of pivot after partition.

    if(low < high){
        partitionIndex = partition(arr, low, high);
        quickSort(arr, low, partitionIndex-1); // Sort Left sub-array.
        quickSort(arr, partitionIndex+1, high); // Sort right sub-array.
    }
}

int main(){
    int arr[] = {15, 25, 10, 30, 20, 5};
    int size = sizeof(arr)/sizeof(int);
    printf("\nArray before Sorting:\n\n");
    traverse(arr, size); // Array before sorting
    quickSort(arr, 0, size-1); // Sorting the array
    printf("\nArray after Sorting:\n\n");
    traverse(arr, size); // Array after sorting
    return 0;
}