#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct Node{
    int data;
    struct Node* next;
};

void sortedListPush(struct Node* node, struct Node* head)
{
    struct Node* current = NULL;
    if(head==NULL || head->data>node->data)
    {
        node->next=head; 
        head=node;
    }
    while(current->next!=NULL && node->data>=current->next->data)
    {
        current=current->next;
    }
    node->next=current->next;
    current->next=node->next;
}
void InsertionSort(struct Node* head)
{
    struct Node* sortedList = malloc(sizeof(struct Node));
    struct Node* current = malloc(sizeof(struct Node));
    current=head;
    while(current!=NULL)
    {
        printf("INSERTInoNNgn");
        struct Node* next = current->next;
        sortedListPush(current,sortedList);
        current=next;
    }
    
    head=current;
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
    printf("ARRAY TO LL");
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
    printf("Enter %d elements of the array:", n);
    for(int i =0;i<n;i++)
    {

        scanf("%d",&arr[i]);
    }
    
    struct Node* root = arrayToLL(arr,n);
    printf("InsertionSorted Linked List: \n");
    InsertionSort(root);
    display(root,n);
    return 0;
}   