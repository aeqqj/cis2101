#include <stdio.h>
#include <stdlib.h>

#define size 100

int* initSet();
void insertMember(int* set, int elem);
void deleteMember(int* set, int elem);
int* setUnion(int* setA, int* setB);
int* setIntersection(int* setA, int* setB);
int* setDifference(int* setA, int* setB); 
void displaySet(int* set);

int main() {
  int* setA = initSet(); 
  int* setB = initSet();

  insertMember(setA, 5);
  insertMember(setA, 10);
  insertMember(setA, 15);

  insertMember(setB, 2);
  insertMember(setB, 10);
  insertMember(setB, 9);
  insertMember(setB, 15);
  insertMember(setB, 20);

  printf("\nSet A: ");
  displaySet(setA);
  printf("\nSet B: ");
  displaySet(setB);

  int* setC = setUnion(setA, setB);
  int* setD = setIntersection(setA, setB);
  int* setE = setDifference(setA, setB);
  int* setF = setDifference(setB, setA);

  printf("\nA union B: "); 
  displaySet(setC);
  printf("\nA intersection B: ");
  displaySet(setD);
  printf("\nA difference B: ");
  displaySet(setE);
  printf("\nB difference A: ");
  displaySet(setF);

  printf("\n");
  return 0;
}

int* initSet() {
  int* newSet = calloc(size, sizeof(int));
  return newSet;
}

void insertMember(int* set, int elem) {
  set[elem] = 1;
}

void deleteMember(int* set, int elem) {
  set[elem] = 0;
}

int* setUnion(int* setA, int* setB) {
  int* newSet = calloc(size, sizeof(int));

  for(int i = 0; i < size; i++) {
    newSet[i] = setA[i] | setB[i];
  }

  return newSet;
}

int* setIntersection(int* setA, int* setB) {
  int* newSet = calloc(size, sizeof(int));

  for (int i = 0; i < size; i++) {
    newSet[i] = setA[i] & setB[i];
  }

  return newSet;
}

int* setDifference(int* setA, int* setB) {
  int* newSet = calloc(size, sizeof(int));

  for (int i = 0; i < size; i++) {
    newSet[i] = setA[i] & ~setB[i];
  }

  return newSet;
}

void displaySet(int* set) {
  printf("{ ");
  for (int i = 0; i < size; i++) {
    if (set[i] == 1) {
      printf("%d, ", i);
    }
  }
  printf(" }");
}
