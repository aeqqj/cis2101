#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef int set[MAX];

void populate_set(set);
void read_set(set);

void insert(set, int);
void delete(set, int);

set* Union(set, set);
set* Intersection(set, set);
set* Difference(set, set);

int main() // ai generated again >>
{
    set a = { 0 }, b = { 0 };
    set* result;
    int choice, element;

    printf("=== Set Operations Program ===\n\n");

    // Populate first set
    printf("Enter elements for Set A (values 0-%d):\n", MAX - 1);
    populate_set(a);

    // Populate second set
    printf("Enter elements for Set B (values 0-%d):\n", MAX - 1);
    populate_set(b);

    // Display the sets
    printf("\nSet A: ");
    read_set(a);
    printf("\nSet B: ");
    read_set(b);
    printf("\n");

    // Menu
    do {
        printf("\n--- Menu ---\n");
        printf("1. Insert element into Set A\n");
        printf("2. Delete element from Set A\n");
        printf("3. Union (A U B)\n");
        printf("4. Intersection (A ∩ B)\n");
        printf("5. Difference (A - B)\n");
        printf("6. Display Sets\n");
        printf("0. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter element to insert (0-%d): ", MAX - 1);
            scanf("%d", &element);
            insert(a, element);
            printf("Set A: ");
            read_set(a);
            printf("\n");
            break;

        case 2:
            printf("Enter element to delete (0-%d): ", MAX - 1);
            scanf("%d", &element);
            delete(a, element);
            printf("Set A: ");
            read_set(a);
            printf("\n");
            break;

        case 3:
            result = Union(a, b);
            if (result != NULL) {
                printf("Union: ");
                read_set(*result);
                printf("\n");
                free(result);
            }
            break;

        case 4:
            result = Intersection(a, b);
            if (result != NULL) {
                printf("Intersection: ");
                read_set(*result);
                printf("\n");
                free(result);
            }
            break;

        case 5:
            result = Difference(a, b);
            if (result != NULL) {
                printf("Difference (A - B): ");
                read_set(*result);
                printf("\n");
                free(result);
            }
            break;

        case 6:
            printf("Set A: ");
            read_set(a);
            printf("\nSet B: ");
            read_set(b);
            printf("\n");
            break;

        case 0:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 0);

    return 0;
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

void insert(set a, int x)
{
    a[x] = 1;
    if (x < MAX) {
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
    set* c;

    return c;
}
