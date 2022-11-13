#include <stdio.h>
#include <stdlib.h>

void display(int arr[], int n)
{
    for(int i =0;i<n-1;i++)
    {
        printf("%d, ",arr[i]);
    }
    printf("%d",arr[n-1]);
}

void selection_Sort(int arr[],int n)
{
    int min_index;
    for(int i = 0;i<n-1;i++)
    {
        min_index=i;
        for(int j = i+1;j<n;j++)
        {
            if(arr[j]<arr[min_index])
            min_index=j;
        }
        int temp = arr[min_index];
        arr[min_index]=arr[i];
        arr[i]=temp;
    }
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
    selection_Sort(arr,n);
    printf("Array after selection sort: ");
    display(arr,n);
}