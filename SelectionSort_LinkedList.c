#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct Node{
    int data;
    struct Node* next;
};

void selectionSort(struct Node* head)
{
    struct Node* temp = head;
    while(temp->next)
    {
        struct Node* minimum = temp;
        struct Node* r = temp->next;
        while(r)
        {
            if(minimum->data > r->data)
            {
                minimum=r;
            }
            r=r->next;
        }
        int x = temp->data;
        temp->data = minimum->data;
        minimum->data = x;
        temp = temp->next;
    }
}

void insert(int item, struct Node** root)
{
    struct Node* tmp = malloc(sizeof(struct Node));
    struct Node* ptr = malloc(sizeof(struct Node));
    tmp->data=item;
    tmp->next=NULL;
    if(*root==NULL)
    {
        *root=tmp;
    }
    else{
        ptr=*root;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=tmp;

    }

}

struct Node *arrayToLL(int arr[],int n)
{
    struct Node* root = malloc(sizeof(struct Node));
    root->data=arr[0];
    root->next=NULL;
    for(int i=1;i<n;i++)
    {
        insert(arr[i],&root);
    }
    return root;
}

void display(struct Node* root,int n)
{
    int i =0;
    while(root!=NULL)
    {
        if(i!=n)
        printf("%d --> ", root->data);
        root=root->next;
        i++;
        if(i==n)
        printf("NULL");
    }
}

int main()
{
    int n;
    printf("Enter number of elements in array:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter %d elements of the array: \n", n);
    for(int i =0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    struct Node* root = arrayToLL(arr,n);
    selectionSort(root);
    display(root,n);
    return 0;
}   