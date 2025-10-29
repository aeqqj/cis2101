#include <stdbool.h>
#include <stdio.h>

#define MAX 20

#define HASH_MAX 10

typedef enum {
    EMPTY = -1,
    DELETED = -2
} status;

typedef struct {
    int data;
    int link;
} node_type;

typedef struct {
    node_type table[MAX];
    int avail;
} dictionary;

void init_dict(dictionary*);
void read_dict(dictionary*);
bool is_member(dictionary*, int);

void insert(dictionary*, int);
void delete(dictionary*, int);

int hash(int);

int main()
{
    dictionary d;
    init_dict(&d);

    printf("Inserting: 5, 15, 25, 7, 17\n");
    insert(&d, 5);
    insert(&d, 15);
    insert(&d, 25);
    insert(&d, 7);
    insert(&d, 17);

    printf("\nDictionary contents:\n");
    read_dict(&d);

    printf("\n\nChecking membership:\n");
    printf("is_member(5): %s\n", is_member(&d, 5) ? "true" : "false");
    printf("is_member(15): %s\n", is_member(&d, 15) ? "true" : "false");
    printf("is_member(99): %s\n", is_member(&d, 99) ? "true" : "false");

    printf("\nDeleting 15 and 25\n");
    delete(&d, 15);
    delete(&d, 25);

    printf("\nDictionary contents after deletion:\n");
    read_dict(&d);

    printf("\n\nChecking membership after deletion:\n");
    printf("is_member(5): %s\n", is_member(&d, 5) ? "true" : "false");
    printf("is_member(15): %s\n", is_member(&d, 15) ? "true" : "false");
    printf("is_member(25): %s\n", is_member(&d, 25) ? "true" : "false");

    printf("\nInserting 35 (reuses deleted space)\n");
    insert(&d, 35);

    printf("\nFinal dictionary contents:\n");
    read_dict(&d);
    printf("\n");

    return 0;
}

void init_dict(dictionary* d)
{
    int i;

    for (i = 0; i < HASH_MAX; i++) {
        d->table[i].data = EMPTY;
        d->table[i].link = -1;
    }

    for (i = HASH_MAX + 1; i < MAX; i++) {
        d->table[i - 1].link = i;
    }

    d->table[MAX - 1].link = -1;
    d->avail = HASH_MAX;
}

void read_dict(dictionary* d)
{
    int i;

    for (i = 0; i < MAX; i++) {
        printf("%d ", d->table[i].data);
    }
}

bool is_member(dictionary* d, int x)
{
    int index = hash(x);
    bool check = false;
    int* i;

    if (x == d->table[index].data) {
        check = true;
    }

    for (i = &d->table[index].link; *i != -1 && x != d->table[*i].data; i = &d->table[*i].link) { }

    if (*i != -1) {
        check = true;
    }

    return check;
}

void insert(dictionary* d, int x)
{
    int index = hash(x);

    if (EMPTY == d->table[index].data || DELETED == d->table[index].data) {
        d->table[index].data = x;
    } else {
        int new_node = d->avail;

        if (new_node != -1) {
            d->avail = d->table[new_node].link;
            d->table[new_node].data = x;
            d->table[new_node].link = d->table[index].link;
            d->table[index].link = new_node;
        }
    }
}

void delete(dictionary* d, int x)
{
    int index = hash(x);

    if (x == d->table[index].data) {
        d->table[index].data = DELETED;
    } else {
        int* i;

        for (i = &d->table[index].link; *i != -1 && x != d->table[*i].data; i = &d->table[*i].link) { }

        if (*i != -1) {
            int temp = *i;
            *i = d->table[*i].link;
            d->table[temp].link = d->avail;
            d->avail = temp;
        }
    }
}

int hash(int x)
{
    return x % HASH_MAX;
}
