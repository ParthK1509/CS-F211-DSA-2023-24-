#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
        // printf("%s ", "NULL");
        return;
    }
    traverse_in_order(node->left);
    printf("%d ", node->value);
    traverse_in_order(node->right);
}
void traverse_pre_order(Node *node)
{
    if (node == NULL)
    {
        printf("%s ", "NULL");
        return;
    }
    printf("%d ", node->value);
    traverse_pre_order(node->left);
    traverse_pre_order(node->right);
}
void traverse_post_order(Node *node)
{
    if (node == NULL)
    {
        printf("%s ", "NULL");
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

int find_min(BST *bst)
{
    Node *current = bst->root;
    while (current->left != NULL) 
    {
        current = current->left;
    }
    return current->value;
}

int find_max(BST *bst)
{
    Node *current = bst->root;
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

BST* constructBST(int* arr,int n)
{
    BST* newBst = new_bst();
    for (int i = 0; i < n; ++i)
    {
        insert(newBst,arr[i]);
    }
    return newBst;
}

bool isgoodtest(Node* node)
{

    BST* left = new_bst();
    BST* right = new_bst();

    left->root = node->left?node->left:NULL;
    right->root = node->right?node->right:NULL;
    int max = -1,min = -1;
    
    if(left!=NULL)
    max = find_max(left);
    if(right!=NULL)
    min = find_min(right);
    if((max <= node->value || max == -1) && (min >= node->value || min == -1))
    {
        return true;
    }
    return false;
}
bool isBinTreeRec(BST* bst,Node* node)
{
    if(node == NULL)return true;
    if(!isgoodtest(node))return false;
    
    bool a = isBinTreeRec(bst,node->left);
    bool b = isBinTreeRec(bst,node->right);
    if(a&b)
    {
        return true;
    }
    return false;
}

int height(Node* node)
{
    if(node == NULL)
    {
        return 0;
    }
    int a,b;
    a = height(node->right);
    b = height(node->left);
    if(a>b)
    {
        return a+1;
    }
    else
    {
        return b+1;
    }
}
// bool isBinTreeIter(BST* bst,Node* node)
// {
//     // if(!isgoodtest(node))return false;
//     // while(node != null)
// }
void removeHalfNodes(BST* bst,Node* node)
{
    if(node == NULL)return;
    if((node->left == NULL && node->right != NULL) || (node->left != NULL && node->right == NULL))
    {
        node = NULL;
    }
    return;
}

// Driver program to test the above functions (feel free to play around with this)
int main()
{
    FILE *fp;
    fp = fopen("n_integers.txt", "r");
    BST *bstArr[1000];
    for(int j = 0; j < 1000; j++){
        int n;
        fscanf(fp, "%d,[", &n);
        int arr[n];
        for(int i = 0; i < n; i++){
            fscanf(fp, "%d ", &arr[i]);
        }
        fscanf(fp, "]\n");
        BST *bst = constructBST(arr, n);
        bstArr[j] = bst;
    }
    fclose(fp);
    for(int i = 0; i < 10; i++){
        printf("BST #%d:\n", i + 1);
        printf("Height: %d\n", height(bstArr[i]->root));
        printf("Max: %d\n", find_max(bstArr[i]));
        printf("Min: %d\n", find_min(bstArr[i]));
        // removeHalfNodes(bstArr[i],bstArr[i]->root);
        // printf("Nodes Removed.\n");
        // printf("Height: %d\n", height(bstArr[i]->root));
        // printf("Max: %d\n", find_max(bstArr[i]));
        // printf("Min: %d\n", find_min(bstArr[i]));

        printf("is Binary tree?: %d",isBinTreeRec(bstArr[i],bstArr[i]->root));
        printf("\n");
    }
    // BST *bst = new_bst();
    // insert(bst, 2);
    // insert(bst, 1);
    // insert(bst, 3);
    // insert(bst, 4);
    // insert(bst, 5);
    // insert(bst, 6);
    // insert(bst, 7);
    // insert(bst, 8);
    // traverse_in_order(bst->root);
    // printf("\n");
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
    // return 0;
}