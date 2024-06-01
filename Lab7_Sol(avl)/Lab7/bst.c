#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int value;
    int height;
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
// bool isgoodtest(Node* node)
// {

//     BST* left = new_bst();
//     BST* right = new_bst();

//     left->root = node->left?node->left:NULL;
//     right->root = node->right?node->right:NULL;
//     int max = -1,min = -1;
    
//     if(left!=NULL)
//     max = find_max(left);
//     if(right!=NULL)
//     min = find_min(right);
//     if((max <= node->value || max == -1) && (min >= node->value || min == -1))
//     {
//         return true;
//     }
//     return false;
// }
// bool isBinTreeRec(BST* bst,Node* node)
// {
//     if(node == NULL)return true;
//     if(!isgoodtest(node))return false;
    
//     bool a = isBinTreeRec(bst,node->left);
//     bool b = isBinTreeRec(bst,node->right);
//     if(a&b)
//     {
//         return true;
//     }
//     return false;
// }
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
void removeHalfNodes(BST* bst,Node* node)
{
    if(node == NULL)return;
    if((node->left == NULL && node->right != NULL) || (node->left != NULL && node->right == NULL))
    {
        node = NULL;
    }
    return;
}
struct node *rotate_left(struct node *x)
{
struct node *y = x->right;
x->right = y->left;
y->left = x;
return y;
}
struct node *rotate_right(struct node *y)
{
struct node *x = y->left;
y->left = x->right;
x->right = y;
return x;
}
void traverse_bfs(Node *node)
{
	if (node == NULL){return;}
	Node *queue[100];
	int front = 0;
	int back = 0;
	queue[back++] = node;
	while (front != back)
	{
		Node *current = queue[front++];
		printf("%d ", current->value);
		if (current->left != NULL)
		{
			queue[back++] = current->left;
		}
		if (current->right != NULL)
		{
			queue[back++] = current->right;
		}
	}
}
int is_height_balanced(struct node *n)
{
	int lh=height(n->left);
	int rh=height(n->right);
	if(lh - rh <=1 && lh-rh >=-1)
	{
		return (lh>rh?lh:rh)+1;
	}
	return -1;
}
struct node *insertAVL(struct node *node, int value)
{

		// printf("yes");
	if (node == NULL)
	{
		node = new_node(value);
	}
	else if (value < node->value)
	{
		node->left = insertAVL(node->left, value);
	}
	else
	{
		node->right = insertAVL(node->right, value);
	}
	int balance = is_height_balanced(node);
	if (balance == -1)
	{
		if (value < node->value)
		{
			if (value < node->left->value)
			{
				// LL imbalance
				node = rotate_right(node);
			}
			else
			{
				// LR imbalance
				node->left = rotate_left(node->left);
				node = rotate_right(node);
			}
		}
		else
		{
			if (value > node->right->value)
			{
				// RR imbalance
				node = rotate_left(node);
			}
			else
			{
				// RL imbalance
				node->right = rotate_right(node->right);
				node = rotate_left(node);
			}
		}
	}
	// printf("NumberAdded");
	return node;
}
int balance_factor(struct node* node)
{
	int ans = node->left->height - node->right->height;
	if(ans <= 1 && ans >=-1)
	{
		return 1;
	}
	return -1;

}
struct node *insertAVL2(struct node *node, int value)
{
	printf("trying");

	if (node == NULL)
	{
		node = new_node(value);
		node->height=1;
	}
	else if (value < node->value)
	{
		node->left = insertAVL(node->left, value);
	}
	else
	{
		node->right = insertAVL(node->right, value);
	}
	node->height = ((node->left->height)>(node->right->height)?(node->left->height):(node->right->height));
	node->height +=1;
	int balance = balance_factor(node);
	if (balance == -1)
	{
		if (value < node->value)
		{
			if (value < node->left->value)
			{
				// LL imbalance
				node = rotate_right(node);
			}
			else
			{
				// LR imbalance
				node->left = rotate_left(node->left);
				node = rotate_right(node);
			}
		}
		else
		{
			if (value > node->right->value)
			{
				// RR imbalance
				node = rotate_left(node);
			}
			else
			{
				// RL imbalance
				node->right = rotate_right(node->right);
				node = rotate_left(node);
			}
		}
	}
	printf("NodeAdded");
	return node;
}

int main()
{
	BST *bst = new_bst();
 
    bst->root = insertAVL2(bst->root, 1);
    bst->root = insertAVL2(bst->root, 2);
    bst->root = insertAVL2(bst->root, 4);
    bst->root = insertAVL2(bst->root, 5);

    bst->root = insertAVL2(bst->root, 6);
    bst->root = insertAVL2(bst->root, 3);
    traverse_bfs(bst->root);
    return 0;
}