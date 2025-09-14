#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef char elem_type;

typedef struct node {
    elem_type* data;
    int count;
}* al_type;

void init_list(al_type);
void read_list(al_type);
int locate_elem(al_type, elem_type);
bool is_member(al_type, elem_type);
void make_null(al_type);

bool is_full(al_type);
bool is_empty(al_type);

void insert_first(al_type, elem_type);
void insert_last(al_type, elem_type);
void insert_pos(al_type, elem_type, int);
void insert_sorted(al_type, elem_type);
void insert_sorted_unique(al_type, elem_type);

void delete_first(al_type);
void delete_last(al_type);
void delete_elem(al_type, elem_type);
void delete_all_occur(al_type, elem_type);

int main()
{
}

void init_list(al_type list)
{
    list->data = (elem_type*)malloc(MAX * sizeof(elem_type));

    if (list->data != NULL) {
        list->count = 0;
    }
}

void read_list(al_type list)
{
    int i;

    for (i = 0; i < list->count; i++) {
        printf("%c ", list->data[i]);
    }
}

int locate_elem(al_type list, elem_type x)
{
    int i;

    for (i = 0; i < list->count && x != list->data[i]; i++) { }

    return (i < list->count) ? i : -1;
}

bool is_member(al_type list, elem_type x)
{
    int i;

    for (i = 0; i < list->count && x != list->data[i]; i++) { }

    return (i < list->count) ? true : false;
}

void make_null(al_type list)
{
    free(list->data);
    list->data = NULL;
    list->count = 0;
}

bool is_full(al_type list)
{
    return (list->count == MAX) ? true : false;
}

bool is_empty(al_type list)
{
    return (list->count == 0) ? true : false;
}

void insert_first(al_type list, elem_type x)
{
    if (!is_full(list)) {
        int i;

        for (i = list->count; i > 0; i--) {
            list->data[i] = list->data[i - 1];
        }
        list->data[0] = x;
        list->count++;
    }
}

void insert_last(al_type list, elem_type x)
{
    if (!is_full(list)) {
        list->data[list->count] = x;
        list->count++;
    }
}

void insert_pos(al_type list, elem_type x, int pos)
{
    if (pos >= 0 && !is_full(list) && pos <= list->count) {
        int i;

        for (i = list->count; i > pos; i--) {
            list->data[i] = list->data[i - 1];
        }
        list->data[pos] = x;
        list->count++;
    }
}

void insert_sorted(al_type list, elem_type x)
{
    if (!is_full(list)) {
        int i, j;

        for (i = 0; i < list->count && x > list->data[i]; i++) { }

        for (j = list->count; j > i; j--) {
            list->data[j] = list->data[j - 1];
        }
        list->data[i] = x;
        list->count++;
    }
}

void insert_sorted_unique(al_type list, elem_type x)
{
    if (!is_full(list)) {
        int i, j;

        for (i = 0; i < list->count && x > list->data[i]; i++) { }

        if (i == list->count || x != list->data[i]) {
            for (j = list->count; j > i; j--) {
                list->data[j] = list->data[j - 1];
            }
            list->data[i] = x;
            list->count++;
        }
    }
}

void delete_first(al_type list)
{
    if (!is_empty(list)) {
        int i;
        list->count--;

        for (i = 0; i < list->count; i++) {
            list->data[i] = list->data[i + 1];
        }
    }
}

void delete_last(al_type list)
{
    if (!is_empty(list)) {
        list->count--;
    }
}

void delete_elem(al_type list, elem_type x)
{
    int i;

    for (i = 0; i < list->count && x != list->data[i]; i++) { }

    if (i < list->count) {
        list->count--;

        for (; i < list->count; i++) {
            list->data[i] = list->data[i + 1];
        }
    }
}

void delete_all_occur(al_type list, elem_type x)
{
    int i, j;

    for (i = 0; i < list->count;) {
        if (x == list->data[i]) {
            list->count--;

            for (j = i; j < list->count; j++) {
                list->data[j] = list->data[j + 1];
            }
        } else {
            i++;
        }
    }
}
