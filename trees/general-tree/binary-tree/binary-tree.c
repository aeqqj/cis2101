// my implementation for array binary trees
// parents are the indices btw

#include <stdio.h>

#define MAX 10

typedef enum {
    ROOT = -1,
    EMPTY = -2,
} status;

typedef struct node {
    int left_child;
    int right_child;
} node_type;

typedef struct {
    node_type data[MAX];
    int root;
} tree_type;

void init_tree(tree_type*);
int label(tree_type, int);
int root(tree_type);
void make_null(tree_type*);

int parent(tree_type, int);
int left_child(tree_type, int);
int right_sibling(node_type);

void insert_tree(tree_type, int, int);

int main()
{
}

void init_tree(tree_type* tree)
{
    int i;

    for (i = 0; i < MAX; i++) {
        tree->data[i].left_child = EMPTY;
        tree->data[i].right_child = EMPTY;
    }
}

// garbooj
int label(tree_type tree, int x)
{
    return x;
}

int root(tree_type tree)
{
    return tree.root;
}

void make_null(tree_type* tree)
{
    int i;

    for (i = 0; i < MAX; i++) {
        tree->data[i].left_child = EMPTY;
        tree->data[i].right_child = EMPTY;
    }
}

int parent(tree_type tree, int x)
{
    int i;

    for (i = 0; i < MAX && x != tree.data[i].left_child && x != tree.data[i].right_child; i++) { }

    return (i < MAX) ? i : EMPTY;
}

int left_child(tree_type tree, int parent)
{
    return tree.data[parent].left_child;
}

// looks stupid ngl
int right_sibling(node_type child)
{
    return child.right_child;
}

void insert_tree(tree_type tree, int parent, int x)
{
    if (parent >= 0 && parent < MAX) {
        if (tree.data[parent].left_child != EMPTY) {
            tree.data[parent].left_child = x;
        }
        tree.data[parent].right_child = x;
    }
}
