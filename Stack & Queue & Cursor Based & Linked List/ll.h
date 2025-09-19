#ifndef LL_H
#define LL_H

#include <stdlib.h>

typedef struct Node
{
    int item;
    struct Node *next;
} Node, *NodePtr;

// Link List Stack
typedef struct Stack
{
    NodePtr top;
} StackLL;

// Link List Queue
typedef struct Queue
{
    NodePtr front;
    NodePtr rear;
} QueueLL;

// Link List Stack Function Headers
void initLLStack(StackLL *SLL);
int isEmptyLLStack(StackLL SLL);
int isFullLLStack(StackLL SLL);
void pushLL(StackLL *SLL, int value);
void popLL(StackLL *SLL);
int peekLL(StackLL LL);
void displayLLStack(StackLL LL);

// Link List Queue Function Headers
void initLLQueue(QueueLL *QLL);
int isEmptyLLQueue(QueueLL QLl);
int isFullLLQueue(QueueLL QLL);
void enqueueLL(QueueLL *QLL, int value);
void dequeueLL(QueueLL *QLL);
int frontLL(QueueLL QLL);
void displayLLQueue(QueueLL QLL);

// Link list Stack Function Definitions
void initLLStack(StackLL *SLL)
{
    SLL->top = NULL;
    printf("\nLinked List Stack Initialized!\n");
}

int isEmptyLLStack(StackLL SLL)
{
    return SLL.top == NULL;
}

int isFullLLStack(StackLL SLL)
{
    return 0; // LOL!
}

void pushLL(StackLL *SLL, int value)
{
    NodePtr *topPtr = &SLL->top;
    NodePtr temp = (NodePtr)malloc(sizeof(Node));

    if (temp == NULL)
    {
        printf("\nMemory Allocation Failed!\n");
        exit(0);
    }

    temp->item = value;
    temp->next = SLL->top;
    SLL->top = temp;
    printf("\nValue Pushed!\n");
}

void popLL(StackLL *SLL)
{
    if (!isEmptyLLStack(*SLL))
    {
        NodePtr next = SLL->top->next;
        free(SLL->top);
        SLL->top = next;
        printf("\nValue Popped!\n");
    }
    else
    {
        printf("\nCannot pop! List Stack is empty!\n");
    }
}

int peekLL(StackLL SLL)
{
    int retVal = -1;

    if (!isEmptyLLStack(SLL))
    {
        retVal = SLL.top->item;
    }
    else
    {
        printf("\nList Stack is currently empty!\n");
    }

    return retVal;
}

void displayLLStack(StackLL SLL)
{
    if (!isEmptyLLStack(SLL))
    {
        NodePtr temp = SLL.top;

        printf("\nContents of the Linked List Stack:\n");
        while (temp != NULL)
        {
            printf("%d", temp->item);

            if (temp->next != NULL)
            {
                printf(", ");
            }

            temp = temp->next;
        }

        printf("\n");
    }
    else
    {
        printf("\nLinked List Stack is currently empty!\n");
    }
}

// Link List Queue Function Definitions
void initLLQueue(QueueLL *QLL)
{
    QLL->front = NULL;
    QLL->rear = NULL;
    printf("\nLinked List Queue Initialized!\n");
}

int isEmptyLLQueue(QueueLL QLL)
{
    return QLL.front == NULL;
}

int isFullLLQueue(QueueLL QLL)
{
    return 0;
}

void enqueueLL(QueueLL *QLL, int value)
{
    NodePtr temp = (NodePtr)malloc(sizeof(Node));

    if (temp == NULL)
    {
        printf("Memory Allocation Failed!");
        exit(0);
    }

    temp->item = value;
    temp->next = NULL;

    if (!isEmptyLLQueue(*QLL))
    {
        QLL->rear->next = temp;
        QLL->rear = temp;
    }
    else
    {
        QLL->front = temp;
        QLL->rear = temp;
    }
}

void dequeueLL(QueueLL *QLL)
{
    if (!isEmptyLLQueue(*QLL))
    {
        NodePtr temp = QLL->front;
        QLL->front = QLL->front->next;
        free(temp);
        printf("\nValue Dequeued!\n");
    }
    else
    {
        printf("\nCannot dequeue Linked List Queue! Queue is empty!\n");
    }
}

int frontLL(QueueLL QLL)
{
    int retVal = -1;

    if (!isEmptyLLQueue(QLL))
    {
        retVal = QLL.front->item;
    }
    else
    {
        printf("\nLinked List Queue is currently empty!\n");
    }

    return retVal;
}

void displayLLQueue(QueueLL QLL)
{
    if (!isEmptyLLQueue(QLL))
    {
        NodePtr temp = QLL.front;

        printf("\nContents of the Linked List Queue:\n");
        while (temp != NULL)
        {
            printf("%d", temp->item);

            if (temp->next != NULL)
            {
                printf(", ");
            }

            temp = temp->next;
        }

        printf("\n");
    }
    else
    {
        printf("\nLinked List Queue is currently empty!\n");
    }
}
#endif