#include "linked_list.h"
#include "stack.h"
#include <stdlib.h>

struct Stack
{
	int top;
	LIST data;
};

Stack *newStack()
{
	Stack *s = (Stack *)malloc(sizeof(Stack));
	if(s != NULL)
		s->top = -1;
	s->data = createNewList();
	return s;
}

bool push(Stack *s, Element e)
{
	NODE n = createNewNode(e);
	insertNodeIntoList(n,s->data);
	(s->top)++;
	return true;
}
bool pop(Stack *s)
{
	if(s->top == -1)
	{
		return false;
	}

	removeFirstNode(s->data);

	(s->top)--;
	return true;
}

bool isEmpty(Stack *s)
{
	if(s->top == -1)
	{
		return true;
	}
	return false;
}

Element *top(Stack *s)
{
	return &(s->data->head->data);
}

void freeStack(Stack *s)
{
	free(s);
}