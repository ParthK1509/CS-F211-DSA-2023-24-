#include <stdio.h>
#include <stdlib.h>

struct heap {
    int *data;
    int size;
    int capacity;
    int depth;
};

typedef struct heap* Heap;

Heap heap_create()
{
    Heap h = malloc(sizeof(struct heap));

    h->data = malloc(sizeof(int));
    h->size = 0;
    h->capacity = 1;
    h->depth = 0;
    return h;
}

add_to_tree()
{
    
}

void insert(Heap h, int value)
{
    add_to_heap(h, value);
    // Complete the function here
    return;
}

int maximum(Heap h)
{
    if (h->size == 0)
        return -1;    // -1 denotes that the heap is empty
    else
        return h->data[0];
}

int extract_maximum(Heap h)
{
    int max = maximum(h);
    // Complete the function here
    return max;
}

void increase_key(Heap h, int x, int k)
{
    h->data[x] = k;
    // Complete the function here
    return;
}