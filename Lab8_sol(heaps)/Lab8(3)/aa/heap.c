#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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


int parent(Heap h, int index)
{
    return h->data[(index-1)/2];
}
int left_child(Heap h, int index)
{
    if(2*index+1 > h->size)
    {
        printf("NoLeftChild");
        return -1;
    }
    return h->data[index*2+1];
}
int right_child(Heap h, int index)
{
    if(2*index+2 > h->size)
    {
        printf("NoRightChild");
        return -1;
    }
    return h->data[index*2+2];
}

// void heapify(Heap h,int index)
// {
//     int parent = (index - 1) / 2;
//     while (index > 0 && heap->arr[index] > heap->arr[parent]) {
//         // swap(&heap->arr[index], &heap->arr[parent]);
//         int x = heap->data[index];
//         heap->data[index] = heap->data[parent];
//         heap->data[parent] = x;
//         index = parent;
//         parent = (index - 1) / 2;
//     }
// }

void add_to_heap(Heap heap,int value)
{
    if (heap->size == 0) 
    {
        heap->data[0] = value;
        heap->size++;
        return;
    }
    if (heap->size >= heap->capacity) {
        heap->capacity *= 2;
        heap->data = (int*)realloc(heap->data, sizeof(int) * heap->capacity);
        if (heap->data == NULL) {
            printf("Memory allocation failed\n");
            exit(1);
        }
    }
    heap->data[heap->size] = value;
    heap->size++;
    heap->depth = log2(heap->size);
    // printf("YES\n");
    // heapify(heap, heap->size - 1);

    return;
}

void insert(Heap h, int value)
{
    add_to_heap(h, value);
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


int main(){
    Heap h=heap_create();

    insert(h,3);
    insert(h,4);
    insert(h,2);
    insert(h,1);

    // printf("Max element in the heap is %d\n",maximum(h));
    // printf("size: %d\n",h->size);
    // printf("depth: %d\n",h->depth);
    // printf("capacity: %d\n",h->capacity);

    printf("right_child of 3: %d\n",right_child(h,0));
    int i=0;
    while(i<h->size){
        printf("%d ",h->data[i]);
        i++;
    }
    free(h->data);
    free(h);

    return 0;
}