#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct node
{
    int data;
    int L; 
    struct node **next;
};
typedef struct node *node_Pointer;
void selection_Sort(int arr[],int n)
{
    int min;
    for(int i = 0;i<n-1;i++)
    {
        min=i;
        for(int j = i+1;j<n;j++)
        {
            if(arr[j]<arr[min])
            min=j;
        }
        int tmp = arr[min];
        arr[min]=arr[i];
        arr[i]=tmp;
    }
}

node_Pointer SkipListBuilder(node_Pointer root) 
{
    node_Pointer expressNode = root;
    while (expressNode)
    {
        if (expressNode->L == 2) // Checking whether node we are iterating through is level 2...
        {
           if(expressNode->next!=NULL){
           node_Pointer ptr= expressNode->next[0];
           while(ptr->L==1 && ptr->next!=NULL) ptr=ptr->next[0];
           expressNode->next[1]=ptr;
           expressNode=expressNode->next[0];
           }
           else break;
        }
        else{
            if(expressNode->next!=NULL) expressNode = expressNode->next[0];
            else break;
        }
    }
    return root;
}
node_Pointer array_To_Skip_List(int *a, int n)
{
    node_Pointer root = malloc(sizeof(struct node));
    root->L = 2; // We begin with the root node at level 2 for convenience
    root->next = malloc(2 * sizeof(struct node *));
    root->data = a[0];
    int coinflip;
    node_Pointer tmp = root;
    for (int i = 1; i < n-1; i++)
    {
                tmp->next[0] = malloc(sizeof(struct node));
                tmp = tmp->next[0];
                coinflip = rand() % 100; // Biased Coinflip to decide the level of the node
                if (coinflip > 75) //I give a 25% chance that it is part of the second level of the skip list..
                {         
                    tmp->L = 2;
                }
                else
                {
                    tmp->L = 1;
                }
                tmp->next = malloc(tmp->L * sizeof(struct node *));
                tmp->data = a[i];
                
    }
    tmp->next[0] = malloc(sizeof(struct node));
    tmp = tmp->next[0];
    tmp->data = a[n-1];
    tmp->next=NULL;
    coinflip=rand()%100;
    if(coinflip>75) tmp->L=2;
    else tmp->L=1;
    root = SkipListBuilder(root); 
    return root;
}

void node_Finder(node_Pointer tmp, int data_To_Find)
{
    int checker = 0;
    if (tmp == NULL) //BASE CASE
    {
        puts("Error...");
        return;
    }
    while (tmp->next[1] && data_To_Find > tmp->next[1]->data) tmp = tmp->next[1];
    while (tmp) 
    {
        if (data_To_Find < tmp->data) break;
        if (data_To_Find == tmp->data)
        {
            printf("Node with value %d Found",data_To_Find);
            checker = 1;
        }
        tmp = tmp->next[0];
    }
    if (checker == 0) printf("No node with value %d Found",data_To_Find);
}

int main()
{
    srand(time(NULL));
    int n;
    puts("Enter the number of nodes you want in the skip list:");
    scanf("%d",&n);
    int arr[n];
    printf("Now enter the nodes you want in the skip list: \n");
    for (int i = 0; i < n; i++)scanf("%d",&arr[i]);
    selection_Sort(arr,n);
    node_Pointer root = array_To_Skip_List(arr, n);
    puts("Skiplist Initialized...");
    node_Pointer tmp = root;
    puts("Level 1 Lane:");
    while (tmp)
    {
        printf("%d->", tmp->data);
        if(tmp->next!=NULL)tmp = tmp->next[0];
        else break;
    }
    tmp = root;
    puts("NULL");
    puts("Level 2 Lane:");
    while (tmp)
    {
        printf("%d->", tmp->data);
        if(tmp->next!=NULL)tmp = tmp->next[1];
        else break;
    }
    puts("NULL");
    printf("Enter search node value: \n");
    int find;
    scanf("%d", &find);
    node_Finder(root, find);
}