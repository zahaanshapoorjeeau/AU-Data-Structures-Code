#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

void swap(int* a, int* b) //Swaps element at pointer a and b.
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low-1; //Incremented each time element smaller than pivot is found to find the rank of pivot element.
    for(int j=low;j<high;j++) 
    {
        if(arr[j]<=pivot)
        {
            i++;
            swap(&arr[j],&arr[i]);
        }
    }   
    swap(&arr[i+1],&arr[high]); //Swapping pivot to its correct index.
    return (i+1); //Returning partition index.
}
void quickSort(int arr[], int low, int high)
{
    if(low<high)
    {
        int p = partition(arr,low,high);
        quickSort(arr,low,p-1);
        quickSort(arr,p+1,high);
    }
}

void printArray(int arr[], int n)
{
    for(int i =0;i<n-1;i++)
    {
        printf("%d, ",arr[i]);
    }
    printf("%d \n",arr[n-1]);
    
}
int main()
{
    int n;
    printf("Enter number of elements in array to be quicksorted: \n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements of array to be quicksorted: \n");
    for(int i =0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("ORIGINAL ARRAY: ");
    printArray(arr,n);
    quickSort(arr, 0, n - 1);
    printf("QUICKSORTED ARRAY: ");
    printArray(arr,n);
    return 0;
}