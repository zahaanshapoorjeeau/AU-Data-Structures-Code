#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


void swap(int* x, int* y)
{
    int temp = *x;
 
    *x = *y;
 
    *y = temp;
}
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2*i +1; //The left node is at index 2i+1
    int r = 2*i +2; //The right node is at indext 2i+2

    if(arr[l]>arr[largest] && l<n)
        largest=l;
    if(arr[r]>arr[largest] && r<n)
        largest=r;
    if(largest!=i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for(int i =(n/2)-1;i>=0;i--){
        heapify(arr, n, i);
    }
     for (int i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int n)
{

    for (int i = 0; i < n-1; i++)
        printf("%d, ", arr[i]);
    printf("%d", arr[n-1]);
}
int main()
{
    int n;
    printf("Enter node of elements in heap: \n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter node of heap: \n");
    for(int i =0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    heapSort(arr, n);
    printf("Sorted heap is: \n");
    printArray(arr, n);
}