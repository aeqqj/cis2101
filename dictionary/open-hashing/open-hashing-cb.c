#include <stdbool.h>
#include <stdio.h>

#define MAX 10

typedef struct {
    int data;
    int link;
} node_type;

typedef struct {
    node_type vh_node[MAX];
    int avail;
} vh_type;

typedef int list;

typedef list dictionary[MAX];

void init_dict(dictionary);
void read_dict(dictionary, vh_type);
bool is_member(dictionary, vh_type, int);

void insert(dictionary, vh_type*, int);
void delete(dictionary, vh_type*, int);

int hash(int);

void init_vh(vh_type*);
int malloc_vh(vh_type*);
void free_vh(vh_type*, int);

int main()
{
    dictionary d;
    vh_type vh;

    init_vh(&vh);
    init_dict(d);

    printf("=== Virtual Heap Hash Table Dictionary Demo ===\n\n");

    // Insert some values
    printf("Inserting values: 5, 15, 25, 7, 17, 3, 13\n");
    insert(d, &vh, 5);
    insert(d, &vh, 15);
    insert(d, &vh, 25);
    insert(d, &vh, 7);
    insert(d, &vh, 17);
    insert(d, &vh, 3);
    insert(d, &vh, 13);

    printf("\nDictionary contents:\n");
    read_dict(d, vh);

    // Test membership
    printf("\nTesting membership:\n");
    printf("Is 15 in dictionary? %s\n", is_member(d, vh, 15) ? "Yes" : "No");
    printf("Is 20 in dictionary? %s\n", is_member(d, vh, 20) ? "Yes" : "No");

    // Delete a value
    printf("\nDeleting 15...\n");
    delete(d, &vh, 15);

    printf("\nDictionary contents after deletion:\n");
    read_dict(d, vh);

    printf("\nIs 15 in dictionary? %s\n", is_member(d, vh, 15) ? "Yes" : "No");

    // Show available nodes
    printf("\nAvailable node index: %d\n", vh.avail);

    return 0;
}

void init_dict(dictionary d)
{
    int i;

    for (i = 0; i < MAX; i++) {
        d[i] = -1;
    }
}

void read_dict(dictionary d, vh_type vh)
{
    int i;

    for (i = 0; i < MAX; i++) {
        printf("Row %d: ", i);

        int* j;
        for (j = &d[i]; *j != -1; j = &vh.vh_node[*j].link) {
            printf("%d ", vh.vh_node[*j].data);
        }
        printf("\n");
    }
}

bool is_member(dictionary d, vh_type vh, int x)
{
    int index = hash(x);

    int* i;

    for (i = &d[index]; *i != -1 && x != vh.vh_node[*i].data; i = &vh.vh_node[*i].link) { }

    return *i != -1;
}

void insert(dictionary d, vh_type* vh, int x)
{
    int new_node = malloc_vh(vh);

    if (new_node != -1) {
        int index = hash(x);
        int* i;

        for (i = &d[index]; *i != -1 && x != vh->vh_node[*i].data; i = &vh->vh_node[*i].link) { }

        if (*i == -1) {
            vh->vh_node[new_node].data = x;
            vh->vh_node[new_node].link = -1;
            *i = new_node;
        }
    }
}

void delete(dictionary d, vh_type* vh, int x)
{
    int index = hash(x);

    int* i;

    for (i = &d[index]; *i != -1 && x != vh->vh_node[*i].data; i = &vh->vh_node[*i].link) { }

    if (*i != -1) {
        int temp = *i;
        *i = vh->vh_node[*i].link;
        free_vh(vh, temp);
    }
}

int hash(int x)
{
    return x % MAX;
}

void init_vh(vh_type* vh)
{
    vh->avail = 0;

    int i;

    for (i = 1; i < MAX; i++) {
        vh->vh_node[i - 1].link = i;
    }

    vh->vh_node[MAX - 1].link = -1;
}

int malloc_vh(vh_type* vh)
{
    int avail = vh->avail;

    if (avail != -1) {
        vh->avail = vh->vh_node[avail].link;
    }

    return avail;
}

void free_vh(vh_type* vh, int index)
{
    if (index >= 0 && index < MAX) {
        vh->vh_node[index].link = vh->avail;
        vh->avail = index;
    }
}
