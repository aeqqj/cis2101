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

void max_heapify(tree_type*, int);
void heap_sort(tree_type*);

int main()
{
}

void init_tree(tree_type* tree)
{
    tree->last_index = -1;
}

void populate_tree(tree_type* tree)
{
    int i, arr[5] = { 4, 7, 1, 3, 9 };

    for (i = 0; i < MAX; i++) {
        insert_tree(tree, arr[i]);
    }
}

// just inserts from left to right
void insert_tree(tree_type* tree, int x)
{
    if (tree->last_index >= 0 && tree->last_index < MAX) {
        tree->data[++tree->last_index] = x;
    }
}

void max_heapify(tree_type* tree, int parent)
{
    int data = tree->data[0];
    int lchild = (parent * 2) + 1;
    int rchild = lchild + 1;

    int schild = (tree->data[lchild] > tree->data[rchild]) ? lchild : rchild;

    while (schild <= tree->last_index && tree->data[schild] > tree->data[parent]) {
        tree->data[parent] = tree->data[schild];

        int parent = schild;
        int left_child = (parent * 2) + 1;
        int right_child = left_child + 1;

        int schild = (tree->data[left_child] > tree->data[right_child]) ? left_child : right_child;
    }

    tree->data[schild] = data;
}

void heap_sort(tree_type* tree)
{
    int parent = (tree->last_index - 1) / 2;

    for (; parent >= 0; parent--) {
        max_heapify(tree, parent);
    }

    while (tree->last_index != -1) {
        tree->data[0] = tree->data[tree->last_index--];

        max_heapify(tree, 0);
    }
}
