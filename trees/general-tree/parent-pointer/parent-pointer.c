#include <stdio.h>
#define MAX 10

typedef enum {
    ROOT = -1,
    EMPTY = -2,
} status;

typedef int tree_type[MAX];

void init_tree(tree_type);
int label(tree_type, int);
int root(tree_type);
void make_null(tree_type);

int parent(tree_type, int);
int left_child(tree_type, int);
int right_sibling(tree_type, int);

void insert_tree(tree_type, int, int);

int main()
{

}

void init_tree(tree_type tree)
{
    int i;

    for (i = 0; i < MAX; i++) {
        tree[i] = EMPTY;
    }
}

// this shit literally don't make sense bruh daz stoooppiidddd
int label(tree_type tree, int index)
{
    return index;
}

int root(tree_type tree)
{
    int i;

    for (i = 0; i < MAX && ROOT != tree[i]; i++) { }

    return (i < MAX) ? i : EMPTY;
}

void make_null(tree_type tree)
{
    int i;

    for (i = 0; i < MAX; i++) {
        tree[i] = EMPTY;
    }
}

void insert_tree(tree_type tree, int parent, int data)
{
    if (tree[parent] != EMPTY && data >= 0 && data < MAX) {
        tree[data] = parent;
    }
}

int left_child(tree_type tree, int parent)
{
    int i = -1;

    if (tree[parent] != EMPTY) {
        for (i = 0; i < MAX && parent != tree[i]; i++) { }
    }

    return (i != -1) ? i : EMPTY;
}

int right_sibling(tree_type tree, int child)
{
    int i;

    for (i = child; i < MAX && tree[i] != child; i++) { }

    return (i < MAX) ? i : EMPTY;
}

int parent(tree_type tree, int child)
{
    int parent = -2;
    
    if (child >= 0 && child < MAX) {
        parent = tree[child];
    }

    return EMPTY;
}
