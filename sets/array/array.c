#include <stdbool.h>
#include <stdio.h>

#define MAX 10

typedef int elem_type;

typedef struct {
    elem_type data[MAX];
    int size;
} s_type;

void init_set(s_type*);
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
    s_type a;
    s_type b;
    elem_type data;

    init_set(&a);
    init_set(&b);

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
    while (a->size < MAX / 2) {
        int data;

        printf("Element %d: ", a->size);
        scanf("%d", &data);

        insert(a, data);
    }
}

void read_set(s_type a)
{
    int i;

    for (i = 0; i < a.size; i++) {
        printf("%d ", a.data[i]);
    }
    printf("\n");
}

bool is_member(s_type a, elem_type x)
{
    int i;

    for (i = 0; i < a.size && x != a.data[i]; i++) { }

    return (i < a.size) ? true : false;
}

void make_null(s_type* a)
{
    a->size = 0;
}

void insert(s_type* a, elem_type x)
{
    if (a->size != MAX) {
        int i;

        for (i = 0; i < a->size && x != a->data[i]; i++) { }

        if (i == a->size) {
            a->data[a->size++] = x;
        }
    }
}

void delete(s_type* a, elem_type x)
{
    int i;

    for (i = 0; i < a->size && x != a->data[i]; i++) { }

    if (i < a->size) {
        if (a->size > 0) {
            a->data[i] = a->data[--a->size];
        }
    }
}

s_type Union(s_type a, s_type b)
{
    s_type c = a;
    int i, j;

    for (i = 0; i < b.size; i++) {
        for (j = 0; j < c.size && b.data[i] != c.data[j]; j++) { }

        if (j == c.size) {
            insert(&c, b.data[i]);
        }
    }

    return c;
}

s_type Intersection(s_type a, s_type b)
{
    s_type c = { {}, 0 };
    int i, j;

    for (i = 0; i < a.size; i++) {
        for (j = 0; j < b.size && a.data[i] != b.data[j]; j++) { }

        if (j < b.size) {
            insert(&c, a.data[i]);
        }
    }

    return c;
}

s_type Difference(s_type a, s_type b)
{
    s_type c = { {}, 0 };
    int i, j;

    for (i = 0; i < a.size; i++) {
        for (j = 0; j < b.size && a.data[i] != b.data[j]; j++) { }

        if (j == b.size) {
            insert(&c, a.data[i]);
        }
    }

    return c;
}
