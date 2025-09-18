#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef char elem_type;

typedef struct node {
    elem_type data;
    struct node* link;
}* ll_type;

void init_list(ll_type*);
void read_list(ll_type);
int locate_elem(ll_type, elem_type);
bool is_member(ll_type, elem_type);
void make_null(ll_type*);

void insert_first(ll_type*, elem_type);
void insert_last(ll_type*, elem_type);
void insert_sorted(ll_type*, elem_type);
void insert_sorted_unique(ll_type*, elem_type);

void delete_first(ll_type*);
void delete_last(ll_type*);
void delete_elem(ll_type*, elem_type);
void delete_all_occur(ll_type*, elem_type);

int main()
{
    ll_type list;

    init_list(&list);

    insert_first(&list, '1');
    insert_last(&list, '4');
    insert_sorted(&list, '2');
    insert_sorted_unique(&list, '5');
    insert_sorted(&list, '3');

    printf("Insert result: ");
    read_list(list);

    delete_first(&list);
    delete_last(&list);
    delete_elem(&list, '2');
    delete_all_occur(&list, '4');
    delete_elem(&list, '3');

    printf("Delete result: ");
    read_list(list);

    free(list);
}

void init_list(ll_type* list)
{
    *list = NULL;
}

void read_list(ll_type list)
{
    for (; list != NULL; list = list->link) {
        printf("%c ", list->data);
    }
    printf("\n");
}

int locate_elem(ll_type list, elem_type x)
{
    int pos;

    for (pos = 0; list != NULL && x != list->data; list = list->link, pos++) { }

    return (list != NULL) ? pos : -1;
}

bool is_member(ll_type list, elem_type x)
{
    for (; list != NULL && x != list->data; list = list->link) { }

    return (list != NULL) ? true : false;
}

void make_null(ll_type* list)
{
    while (*list != NULL) {
        delete_first(list);
    }
}

void insert_first(ll_type* list, elem_type x)
{
    ll_type new_node = (ll_type)malloc(sizeof(struct node));

    if (new_node != NULL) {
        new_node->data = x;
        new_node->link = *list;
        *list = new_node;
    }
}

void insert_last(ll_type* list, elem_type x)
{
    ll_type new_node = (ll_type)malloc(sizeof(struct node));

    if (new_node != NULL) {
        ll_type* ptr;
        new_node->data = x;
        new_node->link = NULL;

        for (ptr = list; *ptr != NULL; ptr = &(*ptr)->link) { }
        *ptr = new_node;
    }
}

void insert_sorted(ll_type* list, elem_type x)
{
    ll_type new_node = (ll_type)malloc(sizeof(struct node));
    if (new_node != NULL) {
        ll_type* ptr;
        new_node->data = x;

        for (ptr = list; *ptr != NULL && x > (*ptr)->data; ptr = &(*ptr)->link) { }

        new_node->link = *ptr;
        *ptr = new_node;
    }
}

void insert_sorted_unique(ll_type* list, elem_type x)
{
    ll_type new_node = (ll_type)malloc(sizeof(struct node));

    if (new_node != NULL) {
        ll_type* ptr;
        new_node->data = x;

        for (ptr = list; *ptr != NULL && x > (*ptr)->data; ptr = &(*ptr)->link) { }

        if (*ptr == NULL || x != (*ptr)->data) {
            new_node->link = *ptr;
            *ptr = new_node;
        } else {
            free(new_node);
        }
    }
}

void delete_first(ll_type* list)
{
    if (*list != NULL) {
        ll_type temp = *list;
        *list = (*list)->link;
        free(temp);
    }
}

void delete_last(ll_type* list)
{
    if (*list != NULL) {
        ll_type* ptr;

        for (ptr = list; (*ptr)->link != NULL; ptr = &(*ptr)->link) { }
        free(*ptr);
        *ptr = NULL;
    }
}

void delete_elem(ll_type* list, elem_type x)
{
    if (*list != NULL) {
        ll_type* ptr;

        for (ptr = list; *ptr != NULL && x != (*ptr)->data; ptr = &(*ptr)->link) { }

        if (*ptr != NULL) {
            ll_type temp = *ptr;
            *ptr = (*ptr)->link;
            free(temp);
        }
    }
}
void delete_all_occur(ll_type* list, elem_type x)
{
    if (*list != NULL) {
        ll_type* ptr;

        for (ptr = list; *ptr != NULL;) {
            if (x == (*ptr)->data) {
                ll_type temp = *ptr;
                *ptr = (*ptr)->link;
                free(temp);
            } else {
                ptr = &(*ptr)->link;
            }
        }
    }
}
