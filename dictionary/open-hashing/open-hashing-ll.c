#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define max 10

typedef struct node {
    int data;
    struct node* link;
}* node_type;

typedef node_type dictionary[max];

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

    printf("=== hash table dictionary demo ===\n\n");

    // insert some values
    printf("inserting values: 5, 15, 25, 7, 17, 3, 13\n");
    insert(d, 5);
    insert(d, 15);
    insert(d, 25);
    insert(d, 7);
    insert(d, 17);
    insert(d, 3);
    insert(d, 13);

    printf("\ndictionary contents:\n");
    read_dict(d);

    // test membership
    printf("\ntesting membership:\n");
    printf("is 15 in dictionary? %s\n", is_member(d, 15) ? "yes" : "no");
    printf("is 20 in dictionary? %s\n", is_member(d, 20) ? "yes" : "no");

    // delete a value
    printf("\ndeleting 15...\n");
    delete(d, 15);

    printf("\ndictionary contents after deletion:\n");
    read_dict(d);

    printf("\nis 15 in dictionary? %s\n", is_member(d, 15) ? "yes" : "no");

    return 0;
}

void init_dict(dictionary d)
{
    int i;

    for (i = 0; i < max; i++) {
        d[i] = null;
    }
}

void read_dict(dictionary d)
{
    int i;

    for (i = 0; i < max; i++) {
        printf("row %d: ", i);

        node_type* ptr;

        for (ptr = &d[i]; *ptr != null; ptr = &(*ptr)->link) {
            printf("%d ", (*ptr)->data);
        }

        printf("\n");
    }
}

bool is_member(dictionary d, int x)
{
    int index = hash(x);

    node_type* ptr;

    for (ptr = &d[index]; *ptr != null && x != (*ptr)->data; ptr = &(*ptr)->link) { }

    return *ptr != null;
}

void insert(dictionary d, int x)
{
    int index = hash(x);

    node_type* ptr;

    for (ptr = &d[index]; *ptr != null && x != (*ptr)->data; ptr = &(*ptr)->link) { }

    if (*ptr == null) {
        node_type new_node = (node_type)malloc(sizeof(struct node));

        if (new_node != null) {
            new_node->link = null;
            new_node->data = x;
            *ptr = new_node;
        }
    }
}

void delete(dictionary d, int x)
{
    int index = hash(x);

    node_type* ptr;

    for (ptr = &d[index]; *ptr != null && x != (*ptr)->data; ptr = &(*ptr)->link) { }

    if (*ptr != null) {
        node_type temp = *ptr;
        *ptr = temp->link;
        free(temp);
    }
}

int hash(int x)
{
    return x % max;
}
