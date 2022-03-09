#include <stdio.h>

void traverse(int arr[], int size){
    for (int i = 0; i < size; i++){
        printf("%d\n", arr[i]);
    }
}

void merge(int A[], int mid, int low, int high){
    int i, j, k, B[100];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high){
        if (A[i] < A[j]){
            B[k] = A[i];
            i++;
            k++;
        }
        else{
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while (i <= mid){
        B[k] = A[i];
        k++;
        i++;
    }
    while (j <= high){
        B[k] = A[j];
        k++;
        j++;
    }
    for (int i = low; i <= high; i++){
        A[i] = B[i];
    }
    
}

void mergeSort(int A[], int low, int high){
    int mid; 
    if(low<high){
        mid = (low + high) /2;
        mergeSort(A, low, mid);
        mergeSort(A, mid+1, high);
        merge(A, mid, low, high);
    }
}

int main(){
    int arr[] = {15, 25, 10, 30, 20, 5};
    int size = sizeof(arr)/sizeof(int);
    printf("\nArray before Sorting:\n\n");
    traverse(arr, size); // Array before sorting
    mergeSort(arr, 0, size-1); // Sorting the array
    printf("\nArray after Sorting:\n\n");
    traverse(arr, size); // Array after sorting
    return 0;
}