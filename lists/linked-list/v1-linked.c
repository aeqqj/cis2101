#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char elem_type;

typedef struct node {
  elem_type data;
  struct node* next;
} ll_type;

// Functions
void initList(ll_type*);

void insertFirst(ll_type*);
void insertLast(ll_type*);
void insertElem(ll_type*, int pos);

void deleteFirst(ll_type*);
void deleteLast(ll_type*);
void deleteElem(ll_type*, elem_type x);
void deleteAllOccur(ll_type*, elem_type x);

bool findElem(ll_type, elem_type x);

// Utility
void printList(ll_type);

int main() {
  
}
