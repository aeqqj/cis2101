#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef int elem_type;

typedef struct node {
    elem_type data;
    struct node* link;
}* s_type;

void populate_set(s_type*);
void read_set(s_type);

bool is_member(s_type, elem_type);
void make_null(s_type*);

void insert(s_type*, elem_type);
void delete(s_type*, elem_type);

// UID
s_type Union(s_type, s_type);
s_type Intersection(s_type, s_type);
s_type Difference(s_type, s_type);

int main()
{
    s_type a = NULL;
    s_type b = NULL;
    elem_type data;

    printf("Populate set A: \n");
    populate_set(&a);

    printf("Populate set B: \n");
    populate_set(&b);

    printf("Set A: ");
    read_set(a);

    printf("Set B: ");
    read_set(b);

    printf("Insert in set A: ");
    scanf("%d", &data);
    insert(&a, data);

    printf("Insert in set B: ");
    scanf("%d", &data);
    insert(&b, data);

    printf("Set A (post-insertion): ");
    read_set(a);

    printf("Set B (post-insertion): ");
    read_set(b);

    printf("Delete in set A: ");
    scanf("%d", &data);
    delete(&a, data);

    printf("Delete in set B: ");
    scanf("%d", &data);
    delete(&b, data);

    printf("Set A (post-deletion): ");
    read_set(a);

    printf("Set B (post-deletion): ");
    read_set(b);

    s_type c = Union(a, b);
    printf("Union of A and B: ");
    read_set(c);

    c = Intersection(a, b);
    printf("Intersection of A and B: ");
    read_set(c);

    c = Difference(a, b);
    printf("Difference of A and B: ");
    read_set(c);

    c = Difference(b, a);
    printf("Difference of B and A: ");
    read_set(c);

    return 0;
}

void populate_set(s_type* a)
{
    int i, size;

    printf("Enter size: ");
    scanf("%d", &size);

    for (i = 0; i < size; i++) {
        int data;

        printf("Element %d: ", i);
        scanf("%d", &data);

        insert(a, data);
    }
}

void read_set(s_type a)
{
    s_type ptr;

    for (ptr = a; ptr != NULL; ptr = ptr->link) {
        printf("%d ", ptr->data);
    }
    printf("\n");
}

bool is_member(s_type a, elem_type x)
{
    s_type ptr;

    for (ptr = a; ptr != NULL && x != ptr->data; ptr = ptr->link) { }

    return (ptr != NULL) ? true : false;
}

void make_null(s_type* a)
{
    *a = NULL;
}

void insert(s_type* a, elem_type x)
{
    s_type new_node = (s_type)malloc(sizeof(struct node));

    if (new_node != NULL) {
        new_node->data = x;

        s_type ptr;

        for (ptr = *a; ptr != NULL && x != ptr->data; ptr = ptr->link) { }

        if (ptr == NULL) {
            new_node->link = *a;
            *a = new_node;
        } else {
            free(new_node);
        }
    }
}

void delete(s_type* a, elem_type x)
{
    s_type* ptr;

    for (ptr = a; *ptr != NULL && x != (*ptr)->data; ptr = &(*ptr)->link) { }

    if (*ptr != NULL) {
        s_type temp = *ptr;
        *ptr = (*ptr)->link;
        free(temp);
    }
}

s_type Union(s_type a, s_type b)
{
    s_type c = NULL;
    s_type aptr, bptr;

    for (aptr = a; aptr != NULL; aptr = aptr->link) {
        insert(&c, aptr->data);
    }

    for (bptr = b; bptr != NULL; bptr = bptr->link) {
        insert(&c, bptr->data);
    }

    return c;
}

s_type Intersection(s_type a, s_type b)
{
    s_type c = NULL;
    s_type* ptr = &c;
    s_type aptr, bptr;

    for (aptr = a; aptr != NULL; aptr = aptr->link) {
        for (bptr = b; bptr != NULL && aptr->data != bptr->data; bptr = bptr->link) { }

        if (bptr != NULL) {
            s_type new_node = (s_type)malloc(sizeof(struct node));

            if (new_node != NULL) {
                new_node->data = aptr->data;
                new_node->link = c;
                *ptr = new_node;
                ptr = &(*ptr)->link;
            }
        }
    }

    return c;
}

s_type Difference(s_type a, s_type b)
{
    s_type c = NULL;
    s_type* ptr = &c;
    s_type aptr, bptr;

    for (aptr = a; aptr != NULL; aptr = aptr->link) {
        for (bptr = b; bptr != NULL && aptr->data != bptr->data; bptr = bptr->link) { }

        if (bptr == NULL) {
            s_type new_node = (s_type)malloc(sizeof(struct node));

            if (new_node != NULL) {
                new_node->data = aptr->data;
                new_node->link = c;
                *ptr = new_node;
                ptr = &(*ptr)->link;
            }
        }
    }

    return c;
}
