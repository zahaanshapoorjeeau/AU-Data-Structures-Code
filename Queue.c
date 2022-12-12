#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node *Node_Address;
Node_Address dequeue(Node_Address root, Node_Address front) //FUNCTION TO DEQUEUE
{
    if (root == NULL)
    {
        puts("Empty Queue");
        return NULL;
    }

    Node_Address newroot = root->next;
    printf("Dequeued %d\n", root->data);
    if (root == front)
        return NULL;
    return newroot; 
}
Node_Address enqueue(Node_Address front, int x) //FUNCTION TO ADD NODE TO QUEUE
{
    front->next = malloc(sizeof(struct node));
    front = front->next;
    front->data = x;
    return front;
}
int main()
{
    Node_Address root = malloc(sizeof(struct node));
    root->data = 609;
    Node_Address front = root;
    front = enqueue(front, 69);
    front = enqueue(front, 690);
    front = enqueue(front, 9696);
    root = dequeue(root, front);
    root = dequeue(root, front);
    root = dequeue(root, front);
}