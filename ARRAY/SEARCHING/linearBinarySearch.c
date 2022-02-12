#include <stdio.h>

int linearSearch(int arr[], int size, int element){
    //Linear Search works in both Sorted and Unsorted Arrays!
    //Time Complexity is O(n).
    for (int i = 0; i < size; i++)
    {
        if(arr[i]== element){
            return i;
        }
    }
    //Searching ends
    return -1;
}

int binarySearch(int arr[], int size, int element){
    //Binary Search works only in Sorted Arrays!
    //Time Complexity is O(log n). (Base of logarithm is 2).
    int low, mid, high;
    low =0; 
    high = size-1; 
    while(low<=high){
        mid = (low + high)/2;
        if(arr[mid] == element){
            return mid;
        }
        else if(arr[mid]<element){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    //Searching ends
    return -1;
}

int main(){
    int arrsize, element, res, choice, arr[100];
    printf("Searching an element in an array\nEnter 0 to perform Linear Search.\nEnter 1 to perform Binary Search.\nEnter your choce: ");
    scanf("%d", &choice);
    if(choice == 0){
        printf("\nLinear Search\nEnter the array size (<100): ");
        scanf("%d", &arrsize);
        for(int i=0;i<arrsize;i++){
            printf("Enter element %d: ", i+1);
            scanf("%d",&arr[i]);
        }
        printf("The array is:\n");
        for(int i=0;i<arrsize;i++){
            printf("%d\n",arr[i]);
        }
        printf("Enter the element to search in the array:");
        scanf("%d", &element);
        res = linearSearch(arr, arrsize, element);
        if(res == -1){
            printf("The element is not found in the given array.");
        }
        else{
            printf("The element %d is found at the index: %d of the array", element, res);
        }
    }

    else if(choice ==1){
        printf("\nBinary Search\n\nEnter the array size (<100): ");
        scanf("%d", &arrsize);
        printf("Enter the Sorted Array.\n");
        for(int i=0;i<arrsize;i++){
            printf("Enter element %d: ", i+1);
            scanf("%d",&arr[i]);
        }
        printf("The array is:\n");
        for(int i=0;i<arrsize;i++){
            printf("%d\n",arr[i]);
        }
        printf("Enter the element to search in the array:");
        scanf("%d", &element);
        res = binarySearch(arr, arrsize, element);
        if(res == -1){
            printf("The element is not found in the given array.");
        }
        else{
            printf("The element %d is found at the index: %d of the array", element, res);
        }
    }
    return 0;
}