#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "queue.h"
#include "cb.h"
#include "ll.h"

int main()
{
  char data;
  STACK S;
  QUEUE Q;
  VirtualHeap VH; // Optional: Cursor-based
  CBlist L;
  StackLL SLL;
  QueueLL QLL;

  initStack(&S);
  initQueue(&Q);

  // Array and Linked List
  pushUnique(&S, 1); // Push if unique
  pushUnique(&S, 9);
  pushUnique(&S, 3);
  pushUnique(&S, 2);
  pushUnique(&S, 5);
  pushUnique(&S, 20);
  enqueueUnique(&Q, 1); // Enqueue if unique
  enqueueUnique(&Q, 4);
  enqueueUnique(&Q, 9);
  enqueueUnique(&Q, 3);

  displayStack(S);
  displayQueue(Q);

  popUnique(&S, 2);
  popUnique(&S, 3);
  dequeueUnique(&Q, 1);
  dequeueUnique(&Q, 2);

  displayStack(S);
  displayQueue(Q);

  insertSortS(&S);
  insertSortQ(&Q);

  displayStack(S);
  displayQueue(Q);

  printf("\n=====================================\n");

  initLLStack(&SLL);
  initLLQueue(&QLL);

  pushLL(&SLL, 2);
  pushLL(&SLL, 5);
  pushLL(&SLL, 9);
  enqueueLL(&QLL, 2);
  enqueueLL(&QLL, 5);
  enqueueLL(&QLL, 9);
  popLL(&SLL);
  dequeueLL(&QLL);

  displayLLStack(SLL);
  displayLLQueue(QLL);

  printf("\n=======================\n");
  /*
// Cursor-based
L = initVHeap(&VH);

CBinitStack(S);
CBinitQueue(Q);

CBpushUnique(VH, L, data);
CBenqueueUnique(VH, L, data);

CBpopUnique(VH, L, data);
CBdequeueUnique(VH, L, data);

CBdisplayStack(S);
CBdisplayQueue(Q);

printf("\n=====================================\n");
*/

  printf("\nFreeing Stack Heap Memory...\n");
  free(S.items);
  printf("\nFreeing Queue Heap Memory...\n");
  free(Q.items);

  if (!isEmptyLLStack(SLL))
  {
    printf("\nFreeing Linked List Stack Heap Memory...\n");
    NodePtr current = SLL.top;

    while (current != NULL)
    {
      NodePtr next = current->next;
      free(current);
      current = next;
    }
  }

  if (!isEmptyLLQueue(QLL))
  {
    printf("\nFreeing Linked List Queue Heap Memory...\n");
    NodePtr current = QLL.front;

    while (current != NULL)
    {
      NodePtr next = current->next;
      free(current);
      current = next;
    }
  }
}