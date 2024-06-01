#include "element.h"
#include "linked_list.h"
#include <stdlib.h>

// struct node
// {
// 	element data;
// 	struct node *next;
// };

// typedef struct node node;
// typedef node * NODE;

// struct linked_list
// {
// 	int count;
// 	NODE head;
// };

// typedef struct linked_list linked_list;
// typedef linked_list * LIST;

LIST createNewList()
{
	LIST myList;
	myList = (LIST) malloc(sizeof(struct linked_list));
	myList->count=0;
	myList->head=NULL;
	return myList;
}
NODE createNewNode(Element data)
{
	NODE myNode;
	myNode = (NODE) malloc(sizeof(struct node));
	myNode->data=data;
	myNode->next=NULL;
	return myNode;
}
void insertNodeIntoList(NODE node, LIST list)
{
	if(list->head==NULL)
	{
		list->head = node;
		node->next = NULL;
		list->count++;
	}
	else
	{
	list->count++;
	NODE temp = list->head;
	list->head = node;
	node->next = temp;
	}
}
void removeFirstNode(LIST list)
{
	list->count--;
	if (list->count == 0) {
		free(list->head);
		list->head = NULL;
		return;
	}

	NODE temp = list->head->next;
	free(list->head);
	list->head = temp;
}
void destroyList(LIST list)
{
	// free(list->data);
	free(list);
}
// void insertNodeAtEnd(NODE node, LIST list)
// {
// 	NODE temp = l1->head;
// 	NODE prev = temp;
// 	while(temp!=NULL)
// 	{
// 		prev = temp;
// 		temp = temp->next;
// 	}
// 	prev->next = node;
// 	node->next = NULL;
// 	list->count++;
// }