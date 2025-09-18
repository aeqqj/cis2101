#ifndef CB_H
#define CB_H

#define MAX_CB 8

typedef struct
{
    char elem;
    int next;
} sList, HeapSpace[MAX_CB];

typedef struct
{
    HeapSpace H; // Pre-defined array
    int avail;
} VirtualHeap;

typedef int CBlist;

/* Normal Linked List (Insert First) */
int initVHeap(VirtualHeap *V);
int allocSpace(VirtualHeap *V);
void insertFirst(int *L, VirtualHeap *V, int elem);
void display(int L, VirtualHeap V);

/* Stack */

/* Queue */

/* Normal Linked List Functions */
int initVHeap(VirtualHeap *V)
{
    int L;

    V->avail = 0;

    int i;
    for (i = 0; i < MAX_CB - 1; i++)
    {
        V->H[i].next = i + 1;
    }

    V->H[i].next = -1;

    return L = -1; // Initialize head to be "NULL"
}

int allocSpace(VirtualHeap *V)
{
    int retVal = V->avail;

    if (retVal != -1)
    {
        V->avail = V->H[retVal].next;
    }

    return retVal;
}

void deallocSpace(VirtualHeap *V, int index)
{
    if (V->avail != MAX_CB)
    {
        V->H[index].next = V->avail;
        V->avail = index;
    }
}

void insertFirst(int *L, VirtualHeap *V, int elem)
{
    int temp;

    temp = allocSpace(V);

    if (temp != -1)
    { // != NULL
        V->H[temp].elem = elem;
        V->H[temp].next = (*L);
        (*L) = temp;
    }
}

void display(int L, VirtualHeap V)
{
    printf("\nCursor Based (Linked List):\n");

    while (L != -1)
    {
        if (L != 1)
        {
            printf(", ");
        }
        printf("%d", V.H[L].elem);

        L = V.H[L].next;
    }
}

/* Stack Functions */

/* Queue Functions */

#endif