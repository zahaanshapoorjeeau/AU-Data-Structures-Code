#include <stdio.h>
#include <stdlib.h>
struct Node {
  int data;
  struct Node *left;
  struct Node *right;
  int height;
};
int height(struct Node *N) {
  if (N == NULL)
    return 0;
  return N->height;
}

int max(int a, int b) {
  return (a > b) ? a : b;
}
struct Node *create_Node(int data) {
  struct Node *Node = (struct Node *)
    malloc(sizeof(struct Node));
  Node->data = data;
  Node->left = NULL;
  Node->right = NULL;
  Node->height = 1;
  return (Node);
}
struct Node *rr(struct Node *y) {
  struct Node *x = y->left;
  struct Node *tmp = x->right;

  x->right = y;
  y->left = tmp;

  y->height = max(height(y->left), height(y->right)) + 1;
  x->height = max(height(x->left), height(x->right)) + 1;

  return x;
}

struct Node *LL(struct Node *x) {
  struct Node *y = x->right;
  struct Node *tmp = y->left;

  y->left = x;
  x->right = tmp;

  x->height = max(height(x->left), height(x->right)) + 1;
  y->height = max(height(y->left), height(y->right)) + 1;

  return y;
}

int get_bfactor(struct Node *N) {
  if (N == NULL)
    return 0;
  return height(N->left) - height(N->right);
}

struct Node *insertNode(struct Node *Node, int data) {

  if (Node == NULL)
    return (create_Node(data));

  if (data < Node->data)
    Node->left = insertNode(Node->left, data);
  else if (data > Node->data)
    Node->right = insertNode(Node->right, data);
  else
    return Node;

  
  Node->height = 1 + max(height(Node->left),
               height(Node->right));

  int balance = get_bfactor(Node);
  if (balance > 1 && data < Node->left->data)
    return rr(Node);

  if (balance < -1 && data > Node->right->data)
    return LL(Node);

  if (balance > 1 && data > Node->left->data) {
    Node->left = LL(Node->left);
    return rr(Node);
  }

  if (balance < -1 && data < Node->right->data) {
    Node->right = rr(Node->right);
    return LL(Node);
  }

  return Node;
}

struct Node *minValueNode(struct Node *Node) {
  struct Node *current = Node;

  while (current->left != NULL)
    current = current->left;

  return current;
}

struct Node *deleteNode(struct Node *root, int data) {

  if (root == NULL)
    return root;

  if (data < root->data)
    root->left = deleteNode(root->left, data);

  else if (data > root->data)
    root->right = deleteNode(root->right, data);

  else {
    if ((root->left == NULL) || (root->right == NULL)) {
      struct Node *temp = root->left ? root->left : root->right;

      if (temp == NULL) {
        temp = root;
        root = NULL;
      } else
        *root = *temp;
      free(temp);
    } else {
      struct Node *temp = minValueNode(root->right);

      root->data = temp->data;

      root->right = deleteNode(root->right, temp->data);
    }
  }

  if (root == NULL)
    return root;
  root->height = 1 + max(height(root->left),
               height(root->right));

  int balance = get_bfactor(root);
  if (balance > 1 && get_bfactor(root->left) >= 0)
    return rr(root);

  if (balance > 1 && get_bfactor(root->left) < 0) {
    root->left = LL(root->left);
    return rr(root);
  }

  if (balance < -1 && get_bfactor(root->right) <= 0)
    return LL(root);

  if (balance < -1 && get_bfactor(root->right) > 0) {
    root->right = rr(root->right);
    return LL(root);
  }

  return root;
}

void print_AVL_PO(struct Node *root) {
  if (root != NULL) {
    printf("%d ", root->data);
    print_AVL_PO(root->left);
    print_AVL_PO(root->right);
  }
}

int main() {
  struct Node *root = NULL;

  root = insertNode(root, 2);
  root = insertNode(root, 6);
  root = insertNode(root, 69);
  root = insertNode(root, 9);
  root = insertNode(root, 699);
  root = insertNode(root, 690);
  root = insertNode(root, 696);

  puts("Before Deleting:");
  print_AVL_PO(root);

  root = deleteNode(root, 3);
  puts("\n");
  puts("After deleting: ");
  print_AVL_PO(root);

  return 0;
}