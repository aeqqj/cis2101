#include <stdio.h>

#define MAX 10

typedef int elem_type;

typedef struct {
    elem_type data[MAX];
    int last_index;
} tree_type;

void init_tree(tree_type*);
void populate_tree(tree_type*);

void insert_tree(tree_type*, int);

void min_heapify(tree_type*, int);

int main() {

}

void init_tree(tree_type* tree) {
    int i;

    for (i = 0; i < MAX; i++) {
        tree->data[i] = -1;
    }
}

void populate_tree(tree_type* tree)
{
    int i, arr[5] = {4, 7, 1, 3, 9};

    for (i = 0; i < 5; i++) {
        tree->data[i] = arr[i];
    }
}

void insert_tree(tree_type* tree, int x)
{
    if (tree->last_index >= 0 && tree->last_index < MAX) {
        tree->data[++tree->last_index] = x;
    }
}

void min_heapify(tree_type* tree, int parent)
{
    int temp = tree->data[parent];
    int left_child = (parent * 2) + 1;
    int right_child = left_child + 1;

    int schild = (tree->data[left_child] < tree->data[right_child]) ? left_child : right_child;

    while (schild < tree->last_index && temp > tree->data[schild]) {
        tree->data[parent] = tree->data[schild];

        parent = schild;
        left_child = (parent * 2) + 1;
        right_child = left_child + 1;
        schild = (tree->data[left_child] < tree->data[right_child]) ? left_child : right_child;
    }

    tree->data[parent] = temp;
}
