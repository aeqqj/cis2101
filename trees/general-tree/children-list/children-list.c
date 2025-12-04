#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct node {
    int data;
    struct node* link;
} *node_type;

typedef struct {
    node_type data[MAX];
    int root;
} tree_type;

void init_tree(tree_type*);
int label(tree_type, node_type);
int root(tree_type);
void make_null(tree_type*);

int parent(tree_type, int);
int left_child(tree_type, int);
int right_sibling(tree_type, int);

void insert_tree(tree_type*, int, int);

int main()
{

}

void init_tree(tree_type* tree)
{
    int i;

    for (i = 0; i < MAX; i++) {
        tree->data[i] = NULL;
    }
}

// dont really get what how this works but whatever
int label(tree_type tree, node_type node)
{
    return node->data;
}

int root(tree_type tree)
{
    return tree.root;
}

void make_null(tree_type* tree)
{
    int i;

    for (i = 0; i < MAX; i++) {
        tree->data[i] = NULL;
    }
}

void insert_tree(tree_type* tree, int parent, int data)
{
    node_type new_node = (node_type)malloc(sizeof(struct node));

    if (new_node != NULL) {
        new_node->data = data;
        new_node->link = tree->data[parent];
        tree->data[parent] = new_node;
    }
}

int left_child(tree_type tree, int parent)
{
    int data = -1;
    
    if (parent >= 0 && parent < MAX) {
        data = tree.data[parent]->data;
    }

    return data;
}

int right_sibling(tree_type tree, int child)
{
    int i;
    node_type ptr = NULL;

    for (i = 0; i < MAX && ptr == NULL; i++) {
        for (ptr = tree.data[i]; ptr != NULL && child != ptr->data; ptr = ptr->link) { }
    }

    return (i < MAX) ? ptr->link->data : -1;
}

int parent(tree_type tree, int child)
{
    int i;
    node_type ptr = NULL;

    for (i = 0; i < MAX && ptr == NULL; i++) {
        for (ptr = tree.data[i]; ptr != NULL && child != ptr->data; ptr = ptr->link);
    }

    return (ptr != NULL) ? i : -1;
}
