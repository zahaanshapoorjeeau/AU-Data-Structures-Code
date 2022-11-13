#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

void insertionSort(int arr[], int n)
{
    int i;
    int j,key;
    for(i=1;i<n;i++)
    {
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>=key)
        {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
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
    int i,n;
    printf("Enter number of elements in array to be sorted: \n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements of array to be sorted: \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    insertionSort(arr,n);
    printf("Array after Insertion sort: ");
    printArray(arr,n);
}