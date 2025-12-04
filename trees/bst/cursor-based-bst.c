#include <stdbool.h>
#include <stdio.h>

#define VHSIZE 10

typedef int elem_type;

typedef struct node {
    elem_type data;
    int lchild;
    int rchild;
} node_type;

typedef struct vh {
    node_type vh_node[VHSIZE];
    int avail;
} vh_type;

typedef int l_type;

void init_tree(l_type*);
void populate_tree(vh_type*, l_type*);
bool is_member(vh_type, l_type, int);

void insert_tree(vh_type*, l_type*, int);
void delete_tree(vh_type*, l_type*, int);

int min_tree(vh_type, l_type);
int max_tree(vh_type, l_type);

void init_vh(vh_type*);
int malloc_vh(vh_type*);
void free_vh(vh_type*, int);

int main()
{
}

void init_tree(l_type* list)
{
    *list = -1;
}

void populate_tree(vh_type* vh, l_type* list)
{
}

bool is_member(vh_type vh, l_type list, int x)
{
    int i;

    for (i = list; i != -1 && x != vh.vh_node[i].data;) { 
        if (x < vh.vh_node[i].data) {
            i = vh.vh_node[i].lchild;
        } else if (x > vh.vh_node[i].data) {
            i = vh.vh_node[i].rchild;
        }
    }

    return (i != -1) ? true : false;
}

void insert_tree(vh_type* vh, l_type* list, int x)
{
    if (vh->avail != -1) {
        int* i;

        for (i = list; *i != -1 && x != vh->vh_node[*i].data;) {
            if (x < vh->vh_node[*i].data) {
                i = &vh->vh_node[*i].lchild;
            } else if (x > vh->vh_node[*i].data) {
                i = &vh->vh_node[*i].rchild;
            }
        }

        int newNode = malloc_vh(vh);

        if (newNode != -1) {
            vh->vh_node[newNode].data = x;
            vh->vh_node[newNode].lchild = -1;
            vh->vh_node[newNode].rchild = -1;

            *i = newNode;
        }
    }
}

void delete_tree(vh_type* vh, l_type* list, int x)
{
    int* i;
    int temp;

    for (i = list; *i != -1 && x != vh->vh_node[*i].data;) {
        if (x < vh->vh_node[*i].data) {
            i = &vh->vh_node[*i].lchild;
        } else if (x > vh->vh_node[*i].data) {
            i = &vh->vh_node[*i].rchild;
        }
    }

    if (*i != -1) {
        if (vh->vh_node[*i].lchild == -1) {
            temp = *i;
            *i = vh->vh_node[*i].rchild;
        } else {
            int* li;

            for (li = &vh->vh_node[*i].lchild; *li != -1; li = &vh->vh_node[*li].rchild) { }

            vh->vh_node[*i].data = vh->vh_node[*li].data;
            temp = *li;
            *li = vh->vh_node[*li].lchild;
        }

        free_vh(vh, temp);
    }
}

int min_tree(vh_type vh, l_type list)
{
    int i;

    for (i = list; vh.vh_node[i].lchild != -1; i = vh.vh_node[i].lchild) { }

    return vh.vh_node[i].data;
}

int max_tree(vh_type vh, l_type list)
{
    int i;

    for (i = list; vh.vh_node[i].rchild != -1; i = vh.vh_node[i].rchild) { }

    return vh.vh_node[i].data;
}

void init_vh(vh_type* vh)
{
    int i;
    vh->avail = 0;

    for (i = 0; i < VHSIZE; i++) {
        vh->vh_node[i].lchild = (i < VHSIZE - 1) ? (i + 1) : -1;
        vh->vh_node[i].rchild = -1;
    }
}

int malloc_vh(vh_type* vh)
{
    int temp = vh->avail;

    if (temp != -1) {
        vh->avail = vh->vh_node[temp].lchild;
    }

    return temp;
}

void free_vh(vh_type* vh, int pos)
{
    if (pos >= 0 && pos < VHSIZE) {
        vh->vh_node[pos].lchild = vh->avail;
        vh->avail = pos;
    }
}
