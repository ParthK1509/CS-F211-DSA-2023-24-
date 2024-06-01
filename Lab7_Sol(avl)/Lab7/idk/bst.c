#include <stdio.h>
#include <stdlib.h>
#include "binary.h"
int main()
{
    BST *bst;
    bst = constructBST();
    traverse_in_order(bst->root);
    printf("\n");
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
BST *constructBST(){
	BST * root;
	root = new_bst();
	int arr[6];
	int val;
	int i = 0;
	while(i<6){
		printf("Enter value: ");
		scanf("%d",&val);
		arr[i]=val;
		i++;
	}
	int j=0;
	while(j<6){
		Node * n;
		n = new_node(arr[j]);
		insert(root,n);
		j++;
	}
	return root;
}

void traverse_in_order(Node *node)
{
if (node == NULL)
{
// printf("NULL");
return;
}
traverse_in_order(node->left);
printf("%d ", node->value);
traverse_in_order(node->right);
}

void traverse_in_order_iterative(Node *node)
{
while(node->left!=NULL){
	node->left;
}

}

void pre_order_traversal(Node *node)
{
if (node == NULL)
{
return;
}
// printf("NULL");
printf("%d ", node->value); 
traverse_in_order(node->left);
traverse_in_order(node->right);
}

void post_order_traversal(Node *node)
{
if (node == NULL)
{
return;
}
// printf("NULL");
traverse_in_order(node->left);
traverse_in_order(node->right);
printf("%d ", node->value);
}
void insert(BST *bst, Node* node)
{
	if (bst->root == NULL)
	{
	bst->root = node;
	return;
	}
	Node *current = bst->root;
	while (current != NULL)
	{
	if (node->value < current->value)
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

int height(BST *bst){
	Node *node=bst->root;
	int height;
	if(bst->root==NULL){
		height = 0;
	}
	
}

bool checktree(BST *bst)
{
	if (bst->root == NULL)
	{
	return true;
	}

	Node *current = bst->root;
	bool  a = check(bst->root);
	return a;
}

bool check(Node* node)
{
	if (node == NULL)
	{
	return true;
	}
	if (node->left->value== NULL)
	{
	return true;
	}
	if (node->right->value == NULL)
	{
	return true;
	}

	if(!(node->left->value<node->value) && !(node->right->value>node->value)){
		return false;
	}
	return check(node->left);
	return check(node->right);
}

bool checktree(BST *bst)
{
	if (bst->root == NULL)
	{
	return true;
	}

	Node *current = bst->root;
	while(current!=NULL){
		bool a = check(current->left);
		bool b = check(current->right);
		if(b=false || a=false){
			break;
			printf("value is false");
		}
		else{
			current=current->left;
		}

	}
	Node *current = bst->root;
	while(current!=NULL){
		bool a = check(current->left);
		bool b = check(current->right);
		if(b=false || a=false){
			break;
			printf("value is false");
		}
		else{
			current=current->right;
		}

	}
	
}


bool check(Node* node){
	if (node == NULL)
	{
	return true;
	}
	if (node->left->value== NULL)
	{
	return true;
	}
	if (node->right->value == NULL)
	{
	return true;
	}

	if(!(node->left->value<node->value) && !(node->right->value>node->value)){
		return false;
	}
}