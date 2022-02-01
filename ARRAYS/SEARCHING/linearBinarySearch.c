#include <stdio.h>

int linearSearch(int arr[], int size, int element){
    for (int i = 0; i < size; i++)
    {
        if(arr[i]== element){
            return i;
        }
    }
    return -1;
}
int main(){
    int arrsize, element, res, arr[100];
    printf("Enter the array size (<100): ");
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
        printf("The element is found at the index: %d of the array",res);
    }
    return 0;
}