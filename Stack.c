#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node *NodeAddress;
NodeAddress pop(NodeAddress tail, NodeAddress root)
{
    
    NodeAddress previous = NULL;
    NodeAddress current = root;
    while (current != tail && current)
    {
        previous = current; // trailing pointer that ends up 1 position behind the previous tail
        current = current->next;
    }
    printf("%d\n", tail->data); 
    free(tail);

    return previous; // Returning modified tail
}
int isEmpty(NodeAddress tail)
{
    return tail==NULL? 0:1;
}
NodeAddress push(NodeAddress tail) // Function to add node to the stack
{
    puts("Enter the value you want to push: ");
    int n;
    scanf("%d",&n);
    tail->next = malloc(sizeof(struct node));
    tail = tail->next;
    tail->data = n;
    return tail;
}
int main()
{
    NodeAddress root = malloc(sizeof(struct node));
    NodeAddress tail = root;
    int choice;
    puts("Enter data of first node of stack: ");
    int n;
    scanf("%d",&n);
    tail->data=n;
    int joemama = 1;
    while(joemama==1)
    {
        puts("Enter your choice: ");
        puts("1. Push");
        puts("2. Pop");
        puts("3. Exit");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            tail = push(tail);
            break;
        case 2:
            if(isEmpty(tail)) tail = pop(tail,root);
            else puts("You cannot Pop an empty stack...");
            break;
        case 3:
            joemama=69;
            break;
        default:
            puts("Input Error, please enter a numerical value indicating your choice...");
            break;
        }
    }

}