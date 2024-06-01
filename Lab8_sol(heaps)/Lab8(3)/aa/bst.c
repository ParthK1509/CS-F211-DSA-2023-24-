#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *left;
    struct node *right;
} Node;

typedef struct bst {
    Node *root;
} BST;

BST *new_bst() 
{
    BST *bst = malloc(sizeof(BST));
    bst->root = NULL;
    return bst;
}

Node *new_node(int value) 
{
    Node *node = malloc(sizeof(Node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void traverse_in_order(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    traverse_in_order(node->left);
    printf("%d ", node->value);
    traverse_in_order(node->right);
}

void traverse_pre_order(Node *node)
{
    if (node == NULL){
        return;
    }

    printf("%d ", node->value);
    traverse_pre_order(node->left);
    traverse_pre_order(node->right);
}

void traverse_post_order(Node *node)
{
     if (node == NULL){
        return;
    }

    traverse_post_order(node->left);
    traverse_post_order(node->right);
    printf("%d ", node->value);
}

void insert(BST *bst, int value)
{
    Node *node = new_node(value);
    if (bst->root == NULL) 
    {
        bst->root = node;
        return;
    }
    Node *current = bst->root;
    while (current != NULL) 
    {
        if (value < current->value) 
        {
            if (current->left == NULL) 
            {
                current->left = node;
                return;
            }
            current = current->left;
        } 
        else 
        {
            if (current->right == NULL) 
            {
                current->right = node;
                return;
            }
            current = current->right;
        }
    }
}

int search(BST *bst, int key)
{
    Node *current = bst->root;
    while (current != NULL) 
    {
        if (key == current->value) 
        {
            return 1;
        } 
        else if (key < current->value) 
        {
            current = current->left;
        } 
        else 
        {
            current = current->right;
        }
    }
    return 0;
}

int find_min(Node *root)
{
    Node *current = root;
    while (current->left != NULL) 
    {
        current = current->left;
    }
    return current->value;
}

int find_max(Node *root)
{
    Node *current = root;
    while (current->right != NULL) 
    {
        current = current->right;
    }
    return current->value;
}

Node *predecessor(Node *node)
{
    if (node->left == NULL)
    {
        return NULL;
    }
    Node *current = node->left;
    while (current->right != NULL)
    {
        current = current->right;
    }
    return current;
}

Node *successor(Node *node)
{
    if (node->right == NULL)
    {
        return NULL;
    }
    Node *current = node->right;
    while (current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

void delete(BST *bst, Node *node)
{
    if (node == NULL)
        return;
    if (node->left == NULL && node->right == NULL)
    {
        // Node is a leaf
        Node* current = bst->root;
        while (current != NULL)
        {
            if (current->left == node)
            {
                current->left = NULL;
                break;
            }
            if (current->right == node)
            {
                current->right = NULL;
                break;
            }
            if (node->value < current->value)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }
        free(node);
        return;
    }
    
    if (node->left == NULL)
    {
        // Node only has right child
        Node* current = bst->root;
        if (current == node)
        {
            bst->root = node->right;
            free(node);
            return;
        }
        while (current != NULL)
        {
            if (current->left == node)
            {
                current->left = node->right;
                break;
            }
            if (current->right == node)
            {
                current->right = node->right;
                break;
            }
            if (node->value < current->value)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }
        free(node);
        return;
    }

    if (node->right == NULL)
    {
        // Node only has left child
        Node* current = bst->root;
        if (current == node)
        {
            bst->root = node->left;
            free(node);
            return;
        }
        while (current != NULL)
        {
            if (current->left == node)
            {
                current->left = node->left;
                break;
            }
            if (current->right == node)
            {
                current->right = node->left;
                break;
            }
            if (node->value < current->value)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }
        free(node);
        return;
    }

    // Node has both children
    Node *temp = successor(node);
    node->value = temp->value;
    delete(bst, temp);
    return;
}

BST *constructBST(int arr[], int n)
{
    BST *bst = new_bst();
    for(int i = 0; i < n; i++)
    {
        insert(bst, arr[i]);
    }

    return bst;
}

void check_bst(Node *root)
{
    Node *current = root;
    if(current == NULL ){
        return;
    }
    int i = 0;

    int max = current->value;

    if( (current->right == NULL || current->value <= current->right->value) && (current->left == NULL || current->value >= current->left->value) && current->right->value <= max && current->left->value <= max)
    {
        if(current->left != NULL) {
            max = current->left->value;
            check_bst(current->left);}
        if(current->right != NULL) {
            max = current->right->value;
            check_bst(current->right);}
    }

    else {printf("not a bst");
            i += 1;}

    if (i<1) {printf("it is a bst");}
    return;
}

int height_bst(Node *node)
{
   if( node ==NULL){
    return -1;
   }

   else {

    int rheight = height_bst(node->right);
    int lheight = height_bst(node->left);

    if (rheight > lheight)
        return (rheight + 1);
    
    else return (lheight + 1);

   }

}

void removeHalfNodes(Node *node)
{
    Node *current = node;

    if(current->right == NULL || current->left == NULL)
    {
        if(current->left == NULL){

        }
    }
}

// Driver program to test the above functions (feel free to play around with this)
int main()
    {
//     BST *bst = new_bst();
//     insert(bst, 2);
//     insert(bst, 1);
//     insert(bst, 3);
//     insert(bst, 4);
//     insert(bst, 5);
//     insert(bst, 6);
//     insert(bst, 7);
//     insert(bst, 8);
    
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = 8;

    BST *bst = constructBST(arr, n);

    // traverse_in_order(bst->root);
    // printf("\n");
    // traverse_pre_order(bst->root);
    // printf("\n");
    // traverse_post_order(bst->root);
    // printf("\n");

    // int max[];
    // for(int i = 0; i < n; i++)
    // {
    //     Node *current = bst->root;
    //     max[i] = find_max(current)
    //     current
    // }

    // check_bst(bst->root);

    // free(bst);

    int i = height_bst(bst->root);
    printf("%d", i);

    // printf("Max = %d\n", find_max(bst));
    // printf("Min = %d\n", find_min(bst));
    // printf("Predecessor of root = %d\n", predecessor(bst->root)->value);
    // printf("Successor of root = %d\n", successor(bst->root)->value);
    // delete(bst, bst->root->left);
    // traverse_in_order(bst->root);
    // printf("\n");
    // delete(bst, bst->root->right);
    // traverse_in_order(bst->root);
    // printf("\n");
    // delete(bst, bst->root);
    // traverse_in_order(bst->root);
    // printf("\n");
    return 0;
}