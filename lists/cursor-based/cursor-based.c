#include <stdbool.h>
#include <stdio.h>

#define VHSIZE 10

typedef int elem_type;

typedef struct node {
    elem_type data;
    int link;
} node_type;

typedef struct {
    node_type vh_node[VHSIZE];
    int avail;
} vh_type;

typedef int l_type;

void init_list(l_type*);
void read_list(l_type, vh_type);
int locate_elem(l_type, vh_type, elem_type);
bool is_member(l_type, vh_type, elem_type);
void make_null(l_type*, vh_type*);

bool is_empty(l_type);

void insert_first(l_type*, vh_type*, elem_type);
void insert_last(l_type*, vh_type*, elem_type);
void insert_pos(l_type*, vh_type*, elem_type, int);
void insert_sorted(l_type*, vh_type*, elem_type);
void insert_sorted_unique(l_type*, vh_type*, elem_type);

void delete_first(l_type*, vh_type*);
void delete_last(l_type*, vh_type*);
void delete_pos(l_type*, vh_type*, int);
void delete_elem(l_type*, vh_type*, elem_type);
void delete_all_occur(l_type*, vh_type*, elem_type);

void init_vh(vh_type*);
int malloc_vh(vh_type*);
void free_vh(vh_type*, int);

int main() // ts written in ai I got too lazy LMAO
{
    vh_type vh;
    l_type list;

    printf("\033[H\033[J"); // Clear screen

    init_vh(&vh);
    init_list(&list);

    printf("=== Testing Insert Operations ===\n");

    // Test insert_first
    printf("\nInserting 5, 3, 7 at first:\n");
    insert_first(&list, &vh, 5);
    insert_first(&list, &vh, 3);
    insert_first(&list, &vh, 7);
    read_list(list, vh);

    // Test insert_last
    printf("\nInserting 10, 12 at last:\n");
    insert_last(&list, &vh, 10);
    insert_last(&list, &vh, 12);
    read_list(list, vh);

    // Test insert_sorted
    printf("\nInserting 8, 4, 5, 2 in sorted order:\n");
    make_null(&list, &vh);
    insert_sorted(&list, &vh, 5);
    insert_sorted(&list, &vh, 8);
    insert_sorted(&list, &vh, 2);
    insert_sorted(&list, &vh, 4);
    read_list(list, vh);

    // Test insert_sorted_unique
    printf("\nInserting 3 (unique) and 5 (duplicate):\n");
    insert_sorted_unique(&list, &vh, 3);
    insert_sorted_unique(&list, &vh, 5); // Should not insert
    read_list(list, vh);

    printf("\n=== Testing Search Operations ===\n");

    // Test is_member
    printf("\nIs 4 a member? %s\n", is_member(list, vh, 4) ? "TRUE" : "FALSE");
    printf("Is 9 a member? %s\n", is_member(list, vh, 9) ? "TRUE" : "FALSE");

    // Test locate_elem
    printf("\nLocation of 5: %d\n", locate_elem(list, vh, 5));
    printf("Location of 99: %d\n", locate_elem(list, vh, 99));

    printf("\n=== Testing Delete Operations ===\n");

    // Test delete_first
    printf("\nDeleting first element:\n");
    delete_first(&list, &vh);
    read_list(list, vh);

    // Test delete_last
    printf("\nDeleting last element:\n");
    delete_last(&list, &vh);
    read_list(list, vh);

    // Test delete_elem
    printf("\nDeleting element 4:\n");
    delete_elem(&list, &vh, 4);
    read_list(list, vh);

    // Test delete_all_occur with duplicates
    printf("\nAdding duplicates of 5:\n");
    insert_last(&list, &vh, 5);
    insert_last(&list, &vh, 5);
    read_list(list, vh);

    printf("\nDeleting all occurrences of 5:\n");
    delete_all_occur(&list, &vh, 5);
    read_list(list, vh);

    // Test insert_pos
    printf("\nInserting 99 at position 1:\n");
    insert_pos(&list, &vh, 99, 1);
    read_list(list, vh);

    // Test delete_pos
    printf("\nDeleting element at position 1:\n");
    delete_pos(&list, &vh, 1);
    read_list(list, vh);

    // Test make_null
    printf("\nMaking list null:\n");
    make_null(&list, &vh);
    read_list(list, vh);

    printf("\nIs list empty? %s\n", is_empty(list) ? "TRUE" : "FALSE");

    return 0;
}

void init_list(l_type* list)
{
    *list = -1;
}

void read_list(l_type list, vh_type vh)
{
    int i;

    for (i = list; i != -1; i = vh.vh_node[i].link) {
        printf("%d ", vh.vh_node[i].data);
    }

    if (list == -1) {
        printf("List is Empty");
    }
}

int locate_elem(l_type list, vh_type vh, elem_type x)
{
    int i;

    for (i = list; i != -1 && x != vh.vh_node[i].data; i = vh.vh_node[i].link) { }

    return i;
}

bool is_member(l_type list, vh_type vh, elem_type x)
{
    int i;

    for (i = list; i != -1 && x != vh.vh_node[i].data; i = vh.vh_node[i].link) { }

    return (i != -1) ? true : false;
}

void make_null(l_type* list, vh_type* vh)
{
    while (*list != -1) {
        int temp = *list;
        *list = vh->vh_node[temp].link;
        free_vh(vh, temp);
    }
}

bool is_empty(l_type list)
{
    return (list == -1) ? true : false;
}

void insert_first(l_type* list, vh_type* vh, elem_type x)
{
    if (vh->avail != -1) {
        int avail = malloc_vh(vh);

        if (avail != -1) {
            vh->vh_node[avail].data = x;
            vh->vh_node[avail].link = *list;
            *list = avail;
        }
    }
}

void insert_last(l_type* list, vh_type* vh, elem_type x)
{
    if (vh->avail != -1) {
        int avail = malloc_vh(vh);

        if (avail != -1) {
            int* i;

            for (i = list; *i != -1; i = &vh->vh_node[*i].link) { }

            vh->vh_node[avail].data = x;
            vh->vh_node[avail].link = *i;

            *i = avail;
        }
    }
}

void insert_pos(l_type* list, vh_type* vh, elem_type x, int pos)
{
    if (vh->avail != -1) {
        int avail = malloc_vh(vh);

        if (avail != -1) {
            int* i;
            int count;

            for (i = list, count = 0; *i != -1 && count <= pos; i = &vh->vh_node[*i].link, count++) { }

            if (pos <= count) {
                vh->vh_node[avail].data = x;
                vh->vh_node[avail].link = *i;

                *i = avail;
            }
        }
    }
}

void insert_sorted(l_type* list, vh_type* vh, elem_type x)
{
    if (vh->avail != -1) {
        int avail = malloc_vh(vh);

        if (avail != -1) {
            int* i;

            for (i = list; *i != -1 && x > vh->vh_node[*i].data; i = &vh->vh_node[*i].link) { }

            vh->vh_node[avail].data = x;
            vh->vh_node[avail].link = *i;

            *i = avail;
        }
    }
}

void insert_sorted_unique(l_type* list, vh_type* vh, elem_type x)
{
    if (vh->avail != -1) {
        int avail = malloc_vh(vh);
        if (avail != -1) {
            int* i;

            for (i = list; *i != -1 && x > vh->vh_node[*i].data; i = &vh->vh_node[*i].link) { }

            if (*i == -1 || x != vh->vh_node[*i].data) {
                vh->vh_node[avail].data = x;
                vh->vh_node[avail].link = *i;

                *i = avail;
            } else {
                free_vh(vh, avail);
            }
        }
    }
}

void delete_first(l_type* list, vh_type* vh)
{
    if (vh->avail != -1 && *list != -1) {
        int temp = *list;
        *list = vh->vh_node[temp].link;
        free_vh(vh, temp);
    }
}

void delete_last(l_type* list, vh_type* vh)
{
    if (vh->avail != -1 && *list != -1) {
        int* i;

        for (i = list; vh->vh_node[*i].link != -1; i = &vh->vh_node[*i].link) { }

        int temp = *i;
        *i = vh->vh_node[*i].link;
        free_vh(vh, temp);
    }
}

void delete_pos(l_type* list, vh_type* vh, int pos)
{
    if (vh->avail != -1 && *list != -1) {
        int* i;
        int count;

        for (i = list, count = 0; vh->vh_node[*i].link != -1 && count < pos; i = &vh->vh_node[*i].link, count++) { }

        if (*i != -1 && pos <= count) {
            int temp = *i;
            *i = vh->vh_node[*i].link;
            free_vh(vh, temp);
        }
    }
}

void delete_elem(l_type* list, vh_type* vh, elem_type x)
{
    if (vh->avail != -1 && *list != -1) {
        int* i;

        for (i = list; *i != -1 && x != vh->vh_node[*i].data; i = &vh->vh_node[*i].link) { }

        if (*i != -1) {
            int temp = *i;
            *i = vh->vh_node[*i].link;
            free_vh(vh, temp);
        }
    }
}

void delete_all_occur(l_type* list, vh_type* vh, elem_type x)
{
    if (vh->avail != -1 && *list != -1) {
        int* i;

        for (i = list; *i != -1;) {
            if (x == vh->vh_node[*i].data) {
                int temp = *i;
                *i = vh->vh_node[*i].link;
                free_vh(vh, temp);
            } else {
                i = &vh->vh_node[*i].link;
            }
        }
    }
}

void init_vh(vh_type* vh)
{
    int i;

    vh->avail = 0;

    for (i = 1; i < VHSIZE; i++) {
        vh->vh_node[i - 1].link = i;
    }

    vh->vh_node[VHSIZE - 1].link = -1;
}

int malloc_vh(vh_type* vh)
{
    int temp = vh->avail;

    if (temp != -1) {
        vh->avail = vh->vh_node[temp].link;
    }

    return temp;
}

void free_vh(vh_type* vh, int pos)
{
    if (pos >= 0 && pos < VHSIZE) {
        vh->vh_node[pos].link = vh->avail;
        vh->avail = pos;
    }
}
