#include <stdio.h>

#define MAX 10

typedef int elem_type;

typedef struct {
    elem_type data[MAX];
    int last_index;
} tree_type;

void init_tree(tree_type*);
void populate_tree(tree_type*);

void insert(tree_type*, int);
int delete_min(tree_type*);

void heap_sort(tree_type*, int);
void heapify(tree_type*, int);

int main()
{
}

void init_tree(tree_type* tree)
{
    int i;

    for (i = 0; i < MAX; i++) {
        tree->data[i] = -1;
    }

    tree->last_index = -1;
}

void populate_tree(tree_type* tree)
{
    int i, arr[5] = { 4, 7, 1, 3, 9 };

    for (i = 0; i < 5; i++) {
        insert(tree, arr[i]);
    }
}

void insert(tree_type* tree, int x)
{
    if (tree->last_index >= -1 && tree->last_index < MAX) {
        tree->data[++tree->last_index] = x;
    }
}

int delete_min(tree_type* tree)
{
    int temp = tree->data[0];
    tree->data[0] = tree->data[tree->last_index--];

    if (tree->last_index > 0) {
        heapify(tree, 0);
    }

    return temp;
}

void min_heapify(tree_type* tree, int parent)
{
    int smallest = parent;
    int left_child = (parent * 2) + 1;
    int right_child = left_child + 1;

    if (left_child < tree->last_index && tree->data[left_child] < tree->data[smallest]) {
        smallest = left_child;
    } else if (right_child < tree->last_index && tree->data[right_child] < tree->data[smallest]) {
        smallest = right_child;
    }

    if (parent != smallest) {
        int temp = tree->data[smallest];
        tree->data[smallest] = tree->data[parent];
        tree->data[parent] = temp;

        min_heapify(tree, smallest);
    }
}

void heap_sort(tree_type* tree, int size)
{
    int parent = (tree->last_index - 1) / 2;
    int i;

    for (;parent > 0; parent--) {
        min_heapify(tree, parent);
    }

    int last_index = size - 1;
    while (size > -1) {
        int temp = tree->data[0];
        tree->data[0] = tree->data[last_index];
        tree->data[last_index] = temp;

        min_heapify(tree, last_index--);
    }
}
