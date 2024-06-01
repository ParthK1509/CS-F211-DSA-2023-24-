#include <stdio.h>

typedef struct node {
int value;
struct node *left;
struct node *right;
} Node;


typedef struct bst {
Node *root;
} BST;

BST *new_bst();
Node *new_node(int value);
BST *constructBST();
void traverse_in_order(Node *node);
void traverse_in_order_iterative(Node *node);
void pre_order_traversal(Node *node);
void post_order_traversal(Node *node);
void insert(BST *bst, Node* node);