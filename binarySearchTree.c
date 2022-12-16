#include <stdio.h>
#include <stdlib.h>
 
struct Node {
    int value;
    struct Node *ln, *rn;
};
 
struct Node* create_Node(int x)
{
    struct Node* tmp
        = (struct Node*)malloc(sizeof(struct Node));
    tmp->value = x;
    tmp->ln = tmp->rn = NULL;
    return tmp;
}
void inorder(struct Node* head)
{
    if (head != NULL) {
        inorder(head->ln);
        printf("%d ", head->value);
        inorder(head->rn);
    }
}

struct Node* insert(struct Node* Node, int value)
{
    if (Node == NULL) return create_Node(value);
    if (value < Node->value) Node->ln = insert(Node->ln, value);
    else Node->rn = insert(Node->rn, value);    
    return Node;
}
struct Node* min_Node(struct Node* Node)
{
    struct Node* current = Node;
    while (current && current->ln != NULL)
        current = current->ln;
 
    return current;
}

struct Node* delete_Node(struct Node* head, int value)
{
    if (head == NULL)return head;
    if (value < head->value)head->ln = delete_Node(head->ln, value);
    else if (value > head->value)head->rn = delete_Node(head->rn, value);
    else {
        if (head->ln == NULL) {
            struct Node* tmp = head->rn;
            free(head);
            return tmp;
        }
        else if (head->rn == NULL) {
            struct Node* tmp = head->ln;
            free(head);
            return tmp;
        }
        struct Node* tmp = min_Node(head->rn);
        head->value = tmp->value;
        head->rn = delete_Node(head->rn, tmp->value);
    }
    return head;
}
 
int main()
{
    int n;
    puts("Enter number of Nodes in BST: ");
    scanf("%d",&n);
    struct Node* head = NULL;
    puts("Enter elements of BST: ");
    for(int i =0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        head=insert(head,a);
    } 
    puts("Inorder traversal: ");
    inorder(head);
    int del;
    puts("Enter element you would like to delete:");
    scanf("%d",&del);
    head = delete_Node(head, del);
    puts("Inorder traversal after deletion");
    inorder(head);
    return 0;
}