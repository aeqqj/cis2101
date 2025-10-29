#include <stdbool.h>
#include <stdio.h>

#define MAX (sizeof(unsigned int) * 8)

typedef unsigned int set;

void display_bits(set);
void display_set(set);
bool is_member(set, int);
bool is_subset(set, set);

void insert(set*, int);
void delete(set*, int);

set Union(set, set);
set Intersection(set, set);
set Difference(set, set);

int main()
{
    set a = 0, b = 0;
    int choice, element;
    char set_choice;

    printf("=== BIT SET OPERATIONS ===\n\n");

    do {
        printf("\n--- MENU ---\n");
        printf("1. Insert element\n");
        printf("2. Delete element\n");
        printf("3. Display set (elements)\n");
        printf("4. Display set (bits)\n");
        printf("5. Check membership\n");
        printf("6. Union of sets\n");
        printf("7. Intersection of sets\n");
        printf("8. Difference of sets\n");
        printf("9. Check if subset\n");
        printf("0. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Which set? (a/b): ");
            scanf(" %c", &set_choice);
            printf("Enter element (0-31): ");
            scanf("%d", &element);
            if (set_choice == 'a')
                insert(&a, element);
            else if (set_choice == 'b')
                insert(&b, element);
            printf("Element inserted.\n");
            break;

        case 2:
            printf("Which set? (a/b): ");
            scanf(" %c", &set_choice);
            printf("Enter element (0-31): ");
            scanf("%d", &element);
            if (set_choice == 'a')
                delete(&a, element);
            else if (set_choice == 'b')
                delete(&b, element);
            printf("Element deleted.\n");
            break;

        case 3:
            printf("Set A: { ");
            display_set(a);
            printf("}\n");
            printf("Set B: { ");
            display_set(b);
            printf("}\n");
            break;

        case 4:
            printf("Set A (bits): ");
            display_bits(a);
            printf("\n");
            printf("Set B (bits): ");
            display_bits(b);
            printf("\n");
            break;

        case 5:
            printf("Which set? (a/b): ");
            scanf(" %c", &set_choice);
            printf("Enter element (0-31): ");
            scanf("%d", &element);
            if (set_choice == 'a') {
                printf("%d is %sa member of Set A\n", element,
                    is_member(a, element) ? "" : "NOT ");
            } else if (set_choice == 'b') {
                printf("%d is %sa member of Set B\n", element,
                    is_member(b, element) ? "" : "NOT ");
            }
            break;

        case 6:
            printf("A U B = { ");
            display_set(Union(a, b));
            printf("}\n");
            printf("Bits: ");
            display_bits(Union(a, b));
            printf("\n");
            break;

        case 7:
            printf("A ∩ B = { ");
            display_set(Intersection(a, b));
            printf("}\n");
            printf("Bits: ");
            display_bits(Intersection(a, b));
            printf("\n");
            break;

        case 8:
            printf("A - B = { ");
            display_set(Difference(a, b));
            printf("}\n");
            printf("B - A = { ");
            display_set(Difference(b, a));
            printf("}\n");
            break;

        case 9:
            if (is_subset(a, b)) {
                printf("Set A is a subset of Set B\n");
            } else if (is_subset(b, a)) {
                printf("Set B is a subset of Set A\n");
            } else {
                printf("Neither set is a subset of the other\n");
            }
            break;

        case 0:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice! Try again.\n");
        }

    } while (choice != 0);

    return 0;
}

void display_bits(set a)
{
    unsigned int mask;

    for (mask = 1 << ((sizeof(set) * 8) - 1); mask != 0; mask >>= 1) {
        printf("%d ", (a & mask) ? 1 : 0);
    }
}

void display_set(set a)
{
    int i;

    for (i = 0; a != 0; a >>= 1, i++) {
        if (a & 1) {
            printf("%d ", i);
        }
    }
}

bool is_member(set a, int x)
{
    return (a >> x) & 1;
}

bool is_subset(set a, set b)
{
    a = Union(a, b);

    return a == b;
}

void insert(set* a, int x)
{
    if (x >= 0 && x < sizeof(set) * 8) {
        *a |= 1 << x;
    }
}

void delete(set* a, int x)
{
    if (x >= 0 && x < sizeof(set) * 8) {
        *a &= ~(1 << x);
    }
}

set Union(set a, set b)
{
    return a | b;
}

set Intersection(set a, set b)
{
    return a & b;
}

set Difference(set a, set b)
{
    return a & ~b;
}
