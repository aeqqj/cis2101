#include <stdbool.h>
#include <stdio.h>

#define MAX 10

typedef enum {
    EMPTY = -1,
    DELETED = -2
} status;

typedef int dictionary[MAX];

void init_dict(dictionary);
void read_dict(dictionary);
bool is_member(dictionary, int);

void insert(dictionary, int);
void delete(dictionary, int);

int hash(int);

int main()
{
    dictionary d;
    init_dict(d);

    printf("=== Open Addressing Hash Table Demo ===\n\n");

    printf("Inserting: 5, 15, 25, 35, 45\n");
    insert(d, 5);
    insert(d, 15);
    insert(d, 25);
    insert(d, 35);
    insert(d, 45);

    printf("Dictionary: ");
    read_dict(d);
    printf("\n\n");

    printf("Deleting 15...\n");
    delete(d, 15);
    printf("Dictionary: ");
    read_dict(d);
    printf("\n\n");

    printf("Inserting 55 (will find EMPTY at index 0, NOT use DELETED slot)...\n");
    insert(d, 55);
    printf("Dictionary: ");
    read_dict(d);
    printf("\n\n");

    // Now fill remaining slots
    printf("Filling: 1, 2, 3, 4\n");
    insert(d, 1);
    insert(d, 2);
    insert(d, 3);
    insert(d, 4);
    printf("Dictionary: ");
    read_dict(d);
    printf("\n\n");

    printf("Inserting 65 (NOW it will reuse DELETED slot as last resort)...\n");
    insert(d, 65);
    printf("Dictionary: ");
    read_dict(d);
    printf("\n\n");

    return 0;
}

void init_dict(dictionary d)
{
    int i;

    for (i = 0; i < MAX; i++) {
        d[i] = EMPTY;
    }
}

void read_dict(dictionary d)
{
    int i;

    for (i = 0; i < MAX; i++) {
        if (d[i] == EMPTY) {
            printf("EMPTY ");
        } else if (d[i] == DELETED) {
            printf("DELETED ");
        } else {
            printf("%d ", d[i]);
        }
    }
}

bool is_member(dictionary d, int x)
{
    int index = hash(x);
    int stop = (index + MAX - 1) % MAX;

    for (; index != stop && x != d[index] && EMPTY != d[index]; index = (index + 1) % MAX) { }

    return x == d[index];
}

void insert(dictionary d, int x)
{
    int index;
    int avail = -1;
    int stop = (index + MAX - 1) % MAX;

    for (index = hash(x); index != stop && x != d[index] && EMPTY != d[index]; index = (index + 1) % MAX) {
        if (avail == -1 && DELETED == d[index]) {
            avail = index;
        }
    }

    if (EMPTY == d[index] || avail != -1) {
        d[(avail == -1) ? index : avail] = x;
    }
}

void delete(dictionary d, int x)
{
    int index = hash(x);
    int stop = (index + MAX - 1) % MAX;

    for (; index != stop && EMPTY != d[index] && x != d[index]; index = (index + 1) % MAX) { }

    if (x == d[index]) {
        d[index] = DELETED;
    }
}

int hash(int x)
{
    return x % MAX;
}
