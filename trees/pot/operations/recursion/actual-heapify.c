#include <stdio.h>

#define MAX 10

typedef int elem_type;

typedef struct {
    elem_type data[MAX];
    int last_index;
} tree_type;

void init_tree(tree_type);
void populate_tree(tree_type);

// just inserts from left to right
void insert_tree(tree_type, int);

// focus here bruh
void min_heapify(tree_type, int);

int main() {

}

void init_tree(tree_type tree) {
    int i;

    for (i = 0; i < MAX; i++) {
        tree.data[i] = -1;
    }
}

void populate_tree(tree_type tree)
{

}

// just inserts from left to right
void insert_tree(tree_type tree, int x)
{
    if (tree.last_index >= 0 && tree.last_index < MAX) {
        tree.data[++tree.last_index] = x;
    }
}

void min_heapify(tree_type tree, int parent)
{
    int smallest = parent;
    int left_child = (parent * 2) + 1;
    int right_child = left_child + 1;

    if (smallest < MAX && tree.data[left_child] < tree.data[smallest]) {
        smallest = left_child;
    }

    if (smallest < MAX && tree.data[right_child] < tree.data[smallest]) {
        smallest = right_child;
    }

    if (parent != smallest) {
        int temp = tree.data[smallest];
        tree.data[smallest] = tree.data[parent];
        tree.data[parent] = temp;

        min_heapify(tree, smallest);
    }
}
