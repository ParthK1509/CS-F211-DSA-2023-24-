#include <stdio.h>
#include <stdlib.h>

typedef struct node *NODE;
struct node
{
    int ele;
    NODE next;
};
typedef struct linked_list *LIST;
struct linked_list
{
    int count;
    NODE head;
};
LIST createNewList()
{
    LIST myList;
    myList = (LIST)malloc(sizeof(struct linked_list));
    myList->count = 0;
    myList->head = NULL;
    return myList;
}
NODE createNewNode(int value)
{
    NODE myNode;
    myNode = (NODE)malloc(sizeof(struct node));
    myNode->ele = value;
    myNode->next = NULL;
    return myNode;
}