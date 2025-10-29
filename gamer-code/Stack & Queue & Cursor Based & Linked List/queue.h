#ifndef QUEUE_H
#define QUEUE_H

/*

TODO

- Update the dequeueUnique() funtion // Completed (for testing)
- Make insertSort() function // To be fixed
- make deleteValue() function

*/

// Queue implementation will be following Variation 2

#define MAX_QUEUE 11 // + 1 for the sacrificial index

typedef struct
{
  int *items; // Pointer to the dynamically allocated array.
  int front;
  int rear;
} QUEUE, *QPtr;

void initQueue(QPtr Q);
int isEmptyQ(QUEUE Q);
int isFullQ(QUEUE Q);
int front(QUEUE Q);
void enqueue(QPtr Q, int value);
int dequeue(QPtr Q);
void enqueueUnique(QPtr Q, int value);
void dequeueUnique(QPtr Q, int value);
void displayQueue(QUEUE Q);
void insertSortQ(QPtr Q);

void initQueue(QPtr Q)
{
  Q->items = (int *)malloc(sizeof(int) * MAX_QUEUE);

  if (Q->items == NULL)
  {
    printf("\nMemory allocation failed!\n");
  }
  else
  {
    Q->front = 1;
    Q->rear = 0;
    printf("\nQueue Initialized!\n");
  }
}

int isEmptyQ(QUEUE Q)
{
  return Q.front == (Q.rear + 1) % MAX_QUEUE;
}

int isFullQ(QUEUE Q)
{
  return Q.front == (Q.rear + 2) % MAX_QUEUE;
}

int front(QUEUE Q)
{
  int retVal = -1;

  if (!isEmptyQ(Q))
  {
    retVal = Q.items[Q.front];
  }
  else
  {
    printf("\nQueue is currently empty!\n");
  }

  return retVal;
}

void enqueue(QPtr Q, int value)
{
  if (!isFullQ(*Q))
  {
    Q->rear = (Q->rear + 1) % MAX_QUEUE;
    Q->items[Q->rear] = value;
    printf("\nValue enqueued!\n");
  }
  else
  {
    printf("\nCannot enqueue! Queue is full!\n");
  }
}

int dequeue(QPtr Q)
{
  int retVal = -1;

  if (!isEmptyQ(*Q))
  {
    retVal = Q->items[Q->front];
    Q->front = (Q->front + 1) % MAX_QUEUE;
  }
  else
  {
    printf("\nCannot dequeue! Queue is empty!\n");
  }

  return retVal;
}

void enqueueUnique(QPtr Q, int value)
{
  if (!isFullQ(*Q))
  {
    QUEUE temp = (*Q);

    for (; !isEmptyQ(temp) && front(temp) != value; dequeue(&temp))
    {
    }

    if (isEmptyQ(temp))
    {
      Q->rear = (Q->rear + 1) % MAX_QUEUE;
      Q->items[Q->rear] = value;
      printf("\nValue enqueued!\n");
    }
    else
    {
      printf("\nValue is not unique! Cannot enqueue!\n");
    }
  }
  else
  {
    printf("\nCannot enqueue! Queue is full!\n");
  }
}

void dequeueUnique(QPtr Q, int value) // To be continued... Should dequeue the unique value itself and shift elements
{
  if (!isEmptyQ(*Q))
  {
    QUEUE temp = (*Q);
    int count = 0;

    // Check if it exists and how many occurrences
    while (!isEmptyQ(temp))
    {
      if (front(temp) == value)
      {
        count++;
      }

      dequeue(&temp);
    }

    for (temp = (*Q); !isEmptyQ(temp) && front(temp) != value; dequeue(&temp)) // Check
    {
    }

    if (!isEmptyQ(temp) && count == 1) // If the value itself is unique and existent in the queue
    {
      int uniqueIndex = Q->front;

      while (uniqueIndex != Q->rear)
      { // Find the index of the value to be dequeued
        if (Q->items[uniqueIndex] == value)
        {
          break;
        }
        uniqueIndex = (uniqueIndex + 1) % MAX_QUEUE;
      }

      for (; uniqueIndex != Q->rear; uniqueIndex = (uniqueIndex + 1) % MAX_QUEUE)
      { // Loop and shift elements from the rear to the front
        Q->items[uniqueIndex] = Q->items[(uniqueIndex + 1) % MAX_QUEUE];
      }

      Q->rear = (Q->rear - 1 + MAX_QUEUE) % MAX_QUEUE; // Decrement the rear position

      printf("\nValue dequeued!\n");
    }
    else
    {
      printf("\nValue is not unique! Cannot dequeue!\n");
    }
  }
  else
  {
    printf("\nCannot dequeue! Queue is empty!\n");
  }
}

void displayQueue(QUEUE Q)
{
  if (!isEmptyQ(Q))
  {
    printf("\nQueue Items (Starting from front): \n");
    int first = 1;

    while (!isEmptyQ(Q))
    {
      printf("%d", front(Q));

      if (first != Q.rear)
      {
        printf(", ");
      }

      dequeue(&Q);

      first = (first + 1) % MAX_QUEUE;
    }
    printf("\n");
  }
  else
  {
    printf("\nQueue is currently empty!\n");
  }
}

void insertSortQ(QPtr Q)
{
  int temp = 0;

  for (int i = (Q->front + 1) % MAX_QUEUE; i != Q->rear; i = (i + 1) % MAX_QUEUE)
  {
    for (int j = i; j > Q->front; j = (j - 1 + MAX_QUEUE) % MAX_QUEUE)
    {
      if (Q->items[j] < Q->items[(j - 1 + MAX_QUEUE) % MAX_QUEUE])
      {
        temp = Q->items[(j - 1 + MAX_QUEUE) % MAX_QUEUE];
        Q->items[(j - 1 + MAX_QUEUE) % MAX_QUEUE] = Q->items[j];
        Q->items[j] = temp;
      }
    }
  }
}

#endif