#ifndef LL_H
#define LL_H

#include <stdio.h>
#include <stdlib.h>

// Link List Stack
typedef struct Node
{
    int item;
    struct Node *next;
} Node, *NodePtr;

typedef struct Stack
{
    NodePtr top;
} StackLL;

StackLL *initLLStack(StackLL SLL);
int isFull(StackLL SLL);
int isEmpty(StackLL SLL);
void pushLL(StackLL *SLL, int value);
void popLL(StackLL *SLL, int value);
int peekLL(StackLL LL);

StackLL *initLLStack(StackLL SLL)
{
    SLL.top = NULL;

    return &SLL;
}

int isFull(StackLL SLL)
{
    return 0; // LOL!
}

int isEmpty(StackLL SLL)
{
    return SLL->top == NULL;
}

void pushLL(StackLL *SLL, int value)
{
    NodePtr *topPtr = &SLL->top;
    NodePtr temp = (NodePtr)malloc(sizeof(Node));

    if (temp == NULL)
    {
        printf("Memory Allocation Failed!");
        exit(0);
    }

    temp->item = value;
    temp->next = SLL->top;
    SLL->top = temp;
}

void popLL(StackLL *SLL)
{
    if (!isEmpty(*SLL))
    {
        NodePtr next = SLL->top->next;
        free(SLL->top);
        SLL->top = next;
    }
    else
    {
        printf("\nCannot pop! List Stack is empty!\n");
    }
}

void peekLL(StackLL SLL)
{
}

#endif