#include <stdbool.h>
#include <stdio.h>

#define MAX 10

typedef int elem_type;

typedef struct {
    elem_type data[MAX];
    int last_index;
} tree_type;

void init_tree(tree_type*);
void populate_tree(tree_type*);
void read_tree(tree_type);
void make_null(tree_type);

void insert_tree(tree_type*, elem_type);
elem_type delete_max(tree_type*);

int main()
{
    printf("bruh");
}

void init_tree(tree_type* tree)
{
    tree->last_index = -1;
}

void populate_tree(tree_type* tree)
{
    int i;

    for (i = 0; i < 5; i++) {
        insert_tree(tree, i);
    }
}

void read_tree(tree_type tree)
{
    int i;

    while ((i = delete_max(&tree)) != -1) {
        printf("%d ", i);
    }
}

void make_null(tree_type tree)
{
    int i;

    while ((i = delete_max(&tree)) != -1) { }
}

void insert_tree(tree_type* tree, elem_type x)
{
    if (tree->last_index + 1 != MAX) {
        int child = ++tree->last_index;
        int parent = (child - 1) / 2;

        while (child >= 0 && x > tree->data[parent]) {
            tree->data[child] = tree->data[parent];

            child = parent;
            parent = (child - 1) / 2;
        }

        tree->data[child] = x;
    }
}

elem_type delete_max(tree_type* tree)
{
    int data = -1;
    if (tree->last_index != -1) {
        data = tree->data[0];
        int temp = tree->data[tree->last_index--];

        int parent = 0;
        int lchild = (parent * 2) + 1;
        int rchild = lchild + 1;

        int schild = (tree->data[lchild] > tree->data[rchild]) ? lchild : rchild;

        while (schild <= tree->last_index && temp < tree->data[schild]) {
            tree->data[parent] = tree->data[schild];

            parent = schild;
            lchild = (parent * 2) + 1;
            rchild = lchild + 1;

            schild = (tree->data[lchild] > tree->data[rchild]) ? lchild : rchild;
        }

        tree->data[parent] = temp;
    }

    return data;
}
