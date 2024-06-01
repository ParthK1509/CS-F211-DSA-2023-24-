#include <stdio.h>
#include <stdlib.h>

struct heap {
    int *data;
    int size;
    int capacity;
    int depth;
};

typedef struct heap* Heap;

// Function to maintain heap property upwards
void heapify_up(Heap h, int index) {
    int parent = (index - 1) / 2;
    while (index > 0 && h->data[parent] < h->data[index]) {
        // Swap parent and child
        int temp = h->data[parent];
        h->data[parent] = h->data[index];
        h->data[index] = temp;
        index = parent;
        parent = (index - 1) / 2;
    }
}


// Function to add an element to the heap
void add_to_heap(Heap h, int value) {
    if (h->size == h->capacity) {
        printf("Heap overflow!\n");
        return;
    }
    h->data[h->size] = value;
    h->size++;
    heapify_up(h, h->size - 1);
}

// Function to maintain heap property downwards
void heapify_down(Heap h, int index) {
    int largest = index;
    int left_child = 2 * index + 1;
    int right_child = 2 * index + 2;

    // Compare with left child
    if (left_child < h->size && h->data[left_child] > h->data[largest])
        largest = left_child;

    // Compare with right child
    if (right_child < h->size && h->data[right_child] > h->data[largest])
        largest = right_child;

    if (largest != index) {
        // Swap with the largest child
        int temp = h->data[index];
        h->data[index] = h->data[largest];
        h->data[largest] = temp;

        // Recursively heapify down the affected subtree
        heapify_down(h, largest);
    }
}

// Function to insert an element into the priority queue
void insert(Heap h, int value) {
    add_to_heap(h, value);
}

// Function to get the maximum element from the priority queue
int maximum(Heap h) {
    if (h->size == 0)
        return -1; // -1 denotes that the heap is empty
    else
        return h->data[0];
}

// Function to extract the maximum element from the priority queue
int extract_maximum(Heap h) {
    if (h->size == 0)
        return -1; // -1 denotes that the heap is empty

    int max = h->data[0];
    h->data[0] = h->data[h->size - 1];
    h->size--;
    heapify_down(h, 0);
    return max;
}

// Function to increase the key of an element in the priority queue
void increase_key(Heap h, int x, int k) {
    if (k < h->data[x]) {
        printf("New key is smaller than current key!\n");
        return;
    }
    h->data[x] = k;
    heapify_up(h, x);
}

// Function to create a new heap
Heap create_heap(int capacity) {
    Heap h = (Heap)malloc(sizeof(struct heap));
    h->data = (int*)malloc(capacity * sizeof(int));
    h->size = 0;
    h->capacity = capacity;
    h->depth = 0;
    return h;
}

// Function to destroy a heap and free memory
void destroy_heap(Heap h) {
    free(h->data);
    free(h);
}

int main() {
    // Example usage
    Heap h = create_heap(10);
    insert(h, 5);
    insert(h, 10);
    insert(h, 3);
    insert(h, 8);

    printf("Maximum element: %d\n", maximum(h));

    increase_key(h, 2, 15);

    printf("Extracted maximum element: %d\n", extract_maximum(h));
    printf("Extracted maximum element: %d\n", extract_maximum(h));

    destroy_heap(h);
    return 0;
}
