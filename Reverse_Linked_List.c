#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

struct Node{
int data;
struct Node* next;
};

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

static void reverse(struct Node** head)
{
    struct Node* current = *head;
    struct Node* previous = NULL;
    struct Node* next = NULL;

    while(current!=NULL)
    {
        next=current->next; //Storing next node at next of current
        current->next=previous;//Reversing the next pointer of the current node to the previous node

        previous=current;//Incrementing pointer to "next" node
        current=next;
    }
    *head=previous;
}

int main()
{
    int n;
    printf("Enter number of elements in linked list you want to create: \n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements of linked list: \n");
    for(int i =0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    struct Node* root = arrayToLL(arr,n);
    printf("ORIGINAL LINKED LIST: \n");
    display(root,n);
    reverse(&root);
    printf("\n");
    printf("REVERSED LINKED LIST: \n");
    display(root,n);
    return 0;
}