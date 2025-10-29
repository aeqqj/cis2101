#ifndef STACK_H
#define STACK_H

/*

TODO

- Update the popUnique() funtion // Completed (for testing)
- make deleteValue() function

*/

// Implementation of Stack will be following Variation 1

#define MAX_STACK 10

typedef struct
{
  int *items;
  int top;
} STACK, *SPtr;

void initStack(SPtr S);
int isFullS(STACK temp);
int isEmptyS(STACK temp);
void push(SPtr S, int value);
void pop(SPtr tempPtr);
int peek(STACK temp);
void pushUnique(SPtr S, int value);
void popUnique(SPtr S, int value);
void displayStack(STACK S);
void insertSortS(SPtr S);

void initStack(SPtr S)
{
  S->top = -1;
  S->items = (int *)malloc(sizeof(int) * MAX_STACK);

  if (S->items == NULL)
  {
    printf("Memory allocation failed!");
  }
  else
  {
    for (int i = 0; i < MAX_STACK; i++)
    {
      S->items[i] = 0;
    }

    printf("\nStack Initialized!\n");
  }
}

int isFullS(STACK S)
{
  return S.top == MAX_STACK - 1;
}

int isEmptyS(STACK S)
{
  return S.top == -1;
}

void push(SPtr S, int value)
{
  if (!isFullS(*S))
  {
    S->top++;
    S->items[S->top] = value;
    printf("\nValue pushed!\n");
  }
  else
  {
    printf("\nCannot push! Stack is already full!\n");
  }
}

void pop(SPtr S)
{
  if (!isEmptyS(*S))
  {
    S->top--;
  }
  else
  {
    printf("\nCannot pop! Stack is empty!\n");
  }
}

int peek(STACK temp)
{
  if (!isEmptyS(temp))
  {
    return temp.items[temp.top];
  }
  else
  {
    printf("\nCannot peek! Stack is empty!\n");
  }
}

void pushUnique(SPtr S, int value)
{
  if (!isFullS(*S))
  {
    STACK temp;

    for (temp = (*S); !isEmptyS(temp) && peek(temp) != value; pop(&temp))
    {
    }

    if (isEmptyS(temp))
    { // Value is unique if the temp is empty
      S->top++;
      S->items[S->top] = value;
      printf("\nValue pushed!\n");
    }
    else
    {
      printf("\nValue is not unique! Not pushed!\n");
    }
  }
  else
  {
    printf("\nCannot push! Stack is already full!\n");
  }
}

void popUnique(SPtr S, int value)
{
  if (!isEmptyS(*S))
  {
    STACK temp = (*S); // Copy beforehand so top can be modified before the loop starts
    int count = 0;

    while (!isEmptyS(temp))
    {
      if (peek(temp) == value)
      {
        count++;
      }

      pop(&temp);
    }

    for (temp = (*S); !isEmptyS(temp) && peek(temp) != value; pop(&temp))
    {
    }

    if (!isEmptyS(temp) && count == 1)
    {
      int uniqueIndex = 0;

      while (uniqueIndex != S->top)
      {
        if (S->items[uniqueIndex] == value)
        {
          break;
        }
        uniqueIndex++;
      }

      for (; uniqueIndex < S->top; uniqueIndex++)
      {
        S->items[uniqueIndex] = S->items[uniqueIndex + 1];
      }

      S->top--;

      printf("\nValue popped!\n");
    }
    else
    {
      printf("\nValue is not unique! Not popped!\n");
    }
  }
  else
  {
    printf("\nCannot pop! Stack is empty!\n");
  }
}

void displayStack(STACK S)
{
  if (S.top != -1)
  {
    printf("\nStack Items (Bottom-Top):\n");
    for (int i = 0; i <= S.top; i++)
    {
      printf("%d", S.items[i]);
      if (i != S.top)
      {
        printf(", ");
      }
    }
    printf("\n");
  }
  else
  {
    printf("\nStack is empty!\n");
  }
}

void insertSortS(SPtr S)
{
  int temp = 0;

  for (int i = 1; i <= S->top; i++)
  {
    for (int j = i; j > 0; j--)
    {
      if (S->items[j] < S->items[j - 1])
      {
        temp = S->items[j - 1];
        S->items[j - 1] = S->items[j];
        S->items[j] = temp;
      }
    }
  }
}

#endif
