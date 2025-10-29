#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct node {
    int data;
    struct node* link;
}* node_type;

typedef node_type dictionary[MAX];

void init_dict(dictionary);
void read_dict(dictionary);
bool is_member(dictionary, int);

void insert(dictionary, int);
void delete(dictionary, int);

int hash(int);

int main() // written in ai looooool
{
    dictionary d;
    init_dict(d);

    printf("=== Hash Table Dictionary Demo ===\n\n");

    // Insert some values
    printf("Inserting values: 5, 15, 25, 7, 17, 3, 13\n");
    insert(d, 5);
    insert(d, 15);
    insert(d, 25);
    insert(d, 7);
    insert(d, 17);
    insert(d, 3);
    insert(d, 13);

    printf("\nDictionary contents:\n");
    read_dict(d);

    // Test membership
    printf("\nTesting membership:\n");
    printf("Is 15 in dictionary? %s\n", is_member(d, 15) ? "Yes" : "No");
    printf("Is 20 in dictionary? %s\n", is_member(d, 20) ? "Yes" : "No");

    // Delete a value
    printf("\nDeleting 15...\n");
    delete(d, 15);

    printf("\nDictionary contents after deletion:\n");
    read_dict(d);

    printf("\nIs 15 in dictionary? %s\n", is_member(d, 15) ? "Yes" : "No");

    return 0;
}

void init_dict(dictionary d)
{
    int i;

    for (i = 0; i < MAX; i++) {
        d[i] = NULL;
    }
}

void read_dict(dictionary d)
{
    int i;

    for (i = 0; i < MAX; i++) {
        printf("Row %d: ", i);

        node_type* ptr;

        for (ptr = &d[i]; *ptr != NULL; ptr = &(*ptr)->link) {
            printf("%d ", (*ptr)->data);
        }

        printf("\n");
    }
}

bool is_member(dictionary d, int x)
{
    int index = hash(x);

    node_type* ptr;

    for (ptr = &d[index]; *ptr != NULL && x != (*ptr)->data; ptr = &(*ptr)->link) { }

    return *ptr != NULL;
}

void insert(dictionary d, int x)
{
    int index = hash(x);

    node_type* ptr;

    for (ptr = &d[index]; *ptr != NULL && x != (*ptr)->data; ptr = &(*ptr)->link) { }

    if (*ptr == NULL) {
        node_type new_node = (node_type)malloc(sizeof(struct node));

        if (new_node != NULL) {
            new_node->link = NULL;
            new_node->data = x;
            *ptr = new_node;
        }
    }
}

void delete(dictionary d, int x)
{
    int index = hash(x);

    node_type* ptr;

    for (ptr = &d[index]; *ptr != NULL && x != (*ptr)->data; ptr = &(*ptr)->link) { }

    if (*ptr != NULL) {
        node_type temp = *ptr;
        *ptr = temp->link;
        free(temp);
    }
}

int hash(int x)
{
    return x % MAX;
}
