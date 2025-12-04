#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5

typedef int set[MAX];

void populate_set(set);
void read_set(set);

bool is_member(set, int);
void make_null(set);

void insert(set, int);
void delete(set, int);

set* Union(set, set);
set* Intersection(set, set);
set* Difference(set, set);

int main()
{
}

void populate_set(set a)
{
    int i, data;

    for (i = 0; i < MAX; i++) {
        printf("Element %d: ", i);
        scanf("%d", &data);

        if (data >= 0 && data < MAX) {
            a[data] = 1;
        }
    }
    printf("\n");
}

void read_set(set a)
{
    int i;

    for (i = 0; i < MAX; i++) {
        if (a[i] == 1) {
            printf("%d ", i);
        }
    }
}

bool is_member(set a, int x)
{
    return (a[x] == 1) ? true : false;
}

void make_null(set a)
{
    int i;

    for (i = 0; i < MAX; i++) {
        a[i] = 0;
    }
}

void insert(set a, int x)
{
    if (x < MAX) {
        a[x] = 1;
    }
}

void delete(set a, int x)
{
    if (x < MAX) {
        a[x] = 0;
    }
}

set* Union(set a, set b)
{
    set* c = (set*)malloc(sizeof(set));

    if (c != NULL) {
        int i;

        for (i = 0; i < MAX; i++) {
            (*c)[i] = a[i] | b[i];
        }
    }

    return c;
}

set* Intersection(set a, set b)
{
    set* c = (set*)malloc(sizeof(set));

    if (c != NULL) {
        int i;

        for (i = 0; i < MAX; i++) {
            (*c)[i] = a[i] & b[i];
        }
    }

    return c;
}

set* Difference(set a, set b)
{
    set* c = (set*)calloc(MAX, sizeof(set));

    if (c != NULL) {
        int i;

        for (i = 0; i < MAX; i++) {
            (*c)[i] = a[i] & !b[i];
        }
    }

    return c;
}
