#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node* lchild;
    struct node* rchild;
}* tree_type;

void init_tree(tree_type*);
void populate_tree(tree_type*);
bool is_member(tree_type, int);

void insert_tree(tree_type*, int);
void delete_tree(tree_type*, int);

int min_tree(tree_type);
int max_tree(tree_type);

int main()
{
    tree_type my_tree;
    
    // Initialize the tree
    init_tree(&my_tree);
    
    // Populate the tree with sample data
    printf("Populating tree with values: 5, 3, 6, 9, 10, 23, 1, 2, 8, 4\n\n");
    populate_tree(&my_tree);
    
    // Test is_member function
    printf("Testing is_member:\n");
    printf("Is 8 in the tree? %s\n", is_member(my_tree, 8) ? "Yes" : "No");
    printf("Is 15 in the tree? %s\n\n", is_member(my_tree, 15) ? "Yes" : "No");
    
    // Test min and max functions
    printf("Minimum value in tree: %d\n", min_tree(my_tree));
    printf("Maximum value in tree: %d\n\n", max_tree(my_tree));
    
    // Test insert function
    printf("Inserting 15 into the tree\n");
    insert_tree(&my_tree, 15);
    printf("Is 15 in the tree now? %s\n\n", is_member(my_tree, 15) ? "Yes" : "No");
    
    // Test delete function
    printf("Deleting 9 from the tree\n");
    delete_tree(&my_tree, 9);
    printf("Is 9 in the tree? %s\n\n", is_member(my_tree, 9) ? "Yes" : "No");
    
    printf("Deleting 5 (root) from the tree\n");
    delete_tree(&my_tree, 5);
    printf("Is 5 in the tree? %s\n\n", is_member(my_tree, 5) ? "Yes" : "No");
    printf("New minimum value: %d\n", min_tree(my_tree));
    printf("New maximum value: %d\n", max_tree(my_tree));
    
    return 0;
}

void init_tree(tree_type* tree)
{
    *tree = NULL;
}

void populate_tree(tree_type* tree)
{
    int arr[10] = {5, 3, 6, 9, 10, 23, 1, 2, 8, 4};
    int i;

    for (i = 0; i < 10; i++) {
        insert_tree(tree, arr[i]);
    }
}

bool is_member(tree_type tree, int x)
{
    tree_type ptr;

    for (ptr = tree; ptr != NULL && x != ptr->data;) {
        if (x < ptr->data) {
            ptr = ptr->lchild;
        } else if (x > ptr->data) {
            ptr = ptr->rchild;
        }
    }

    return (ptr != NULL) ? true : false;
}

void insert_tree(tree_type* tree, int x)
{
    tree_type* ptr;

    for (ptr = tree; *ptr != NULL;) {
        if (x < (*ptr)->data) {
            ptr = &(*ptr)->lchild;
        } else if (x > (*ptr)->data) {
            ptr = &(*ptr)->rchild;
        }
    }

    tree_type new_node = (tree_type)malloc(sizeof(struct node));

    if (new_node != NULL) {
        new_node->data = x;
        new_node->lchild = NULL;
        new_node->rchild = NULL;

        *ptr = new_node;
    }
}

// left subtree oriented
void delete_tree(tree_type* tree, int x)
{
    tree_type temp;
    tree_type* ptr;

    for (ptr = tree; *ptr != NULL && x != (*ptr)->data;) {
        if (x < (*ptr)->data) {
            ptr = &(*ptr)->lchild;
        } else if (x > (*ptr)->data) {
            ptr = &(*ptr)->rchild;
        }
    }

    if (*ptr != NULL) {
        if ((*ptr)->lchild == NULL) {
            temp = *ptr;
            *ptr = (*ptr)->rchild;
        } else {
            tree_type* rptr;

            for (rptr = &(*ptr)->lchild; (*rptr)->rchild != NULL; rptr = &(*rptr)->rchild) { } 

            (*ptr)->data = (*rptr)->data;
            temp = *rptr;
            *rptr = (*rptr)->lchild;
        }

        free(temp);
    }
}

int min_tree(tree_type tree)
{
    tree_type ptr;
    
    for (ptr = tree; ptr->lchild != NULL; ptr = ptr->lchild) { }

    return ptr->data;
}

int max_tree(tree_type tree)
{
    tree_type ptr;

    for (ptr = tree; ptr->rchild != NULL; ptr = ptr->rchild) { }

    return ptr->data;
}
