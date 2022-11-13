#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct Node
{
    int data;
    struct Node* next;
};

static void insert(struct Node** root, int item)
{
    struct Node* temp = malloc(sizeof(struct Node));
    struct Node* ptr = malloc(sizeof(struct Node));
    temp->data=item;
    temp->next=NULL;
    if(*root==NULL)
    {
    *root=temp;
    }
    else{
        ptr=*root;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=temp;
    }

}
struct Node* array_To_Linked_List(int arr[], int n)
{
    struct Node* root = malloc(sizeof(struct Node));
    root->data=arr[0];
    root->next=NULL;
    for(int i=1;i<n;i++)
    {
        insert(&root,arr[i]);
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

static void chunk_Reverse(int k, struct Node** head)
{
    struct Node* current = *head; //This becomes the tail in the end.
    struct Node* orighead = *head; //This remains the Head which we point to the rest of the linked list we do not want to reverse.
    struct Node* previous = NULL;
    struct Node* next = NULL;
    int i=1;
    while(current!=NULL && i<=k)
    {
        next=current->next;//Storing the next node pointer.
        current->next=previous;//Reversing the pointer to the previous node.

        previous=current;
        current=next;
        if(i==k)
        {
            orighead->next=current;
        }
        i++;
    }
    *head=previous;
}
int main()
{
    int i,n,k;
    printf("Enter number of elements in linked list: \n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements of linked list: \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter chunk K to reverse of linked list: \n");
    scanf("%d",&k);
    struct Node* root = array_To_Linked_List(arr,n);
    printf("ORIGINAL LINKED LIST: \n");
    display(root,n);
    chunk_Reverse(k,&root);
    printf("\n");
    printf("CHUNK REVERSED LINKED LIST: \n");
    display(root,n);
    return 0;
    
}