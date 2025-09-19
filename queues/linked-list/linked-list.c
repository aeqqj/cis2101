#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef char elem_type;

typedef struct node {
    elem_type data;
    struct node* link;
}* ll_type;

typedef struct {
    ll_type front;
    ll_type rear;
    int count;
} q_type;

void init_queue(q_type*);
void read_queue(q_type*);
void make_null(q_type*);

bool is_empty(q_type);

void enqueue(q_type*, elem_type);
void enqueue_sorted(q_type*, elem_type);
void enqueue_sorted_unique(q_type*, elem_type);
void dequeue(q_type*);

elem_type front(q_type);

int main()
{
    q_type queue;

    init_queue(&queue);

    enqueue(&queue, '1');
    enqueue(&queue, '3');
    enqueue(&queue, '4');
    enqueue_sorted(&queue, '2');

    printf("Insert result: ");
    read_queue(&queue);
}

void init_queue(q_type* queue)
{
    queue->front = NULL;
    queue->rear = NULL;
    queue->count = 0;
}

void read_queue(q_type* queue)
{
    if (!is_empty(*queue)) {
        int i = 0;

        for (i = 0; i < queue->count; i++) {
            elem_type temp = queue->front->data;
            printf("%c ", queue->front->data);
            dequeue(queue);
            enqueue(queue, temp);
        }
    }
}

void make_null(q_type* queue)
{
    while (queue->front != NULL) {
        dequeue(queue);
    }
    queue->rear = NULL;
}

bool is_empty(q_type queue)
{
    return (queue.front == NULL) ? true : false;
}

void enqueue(q_type* queue, elem_type x)
{
    ll_type new_node = (ll_type)malloc(sizeof(struct node));

    if (new_node != NULL) {
        new_node->data = x;
        new_node->link = NULL;

        if (queue->front == NULL) {
            queue->front = new_node;
        } else {
            queue->rear->link = new_node;
        }

        queue->rear = new_node;
        queue->count++;
    }
}

void enqueue_sorted(q_type* queue, elem_type x)
{
    int i;

    for (i = 0; i < queue->count && x > queue->front->data; i++) {
        elem_type temp = queue->front->data;
        dequeue(queue);
        enqueue(queue, temp);
    }

    enqueue(queue, x);

    for (; i < queue->count; i++) {
        elem_type temp = queue->front->data;
        dequeue(queue);
        enqueue(queue, temp);
    }
}

void enqueue_sorted_unique(q_type* queue, elem_type x)
{
    int i;

    for (i = 0; i < queue->count && x != queue->front->data; i++) {
        elem_type temp = queue->front->data;
        dequeue(queue);
        enqueue(queue, temp);
    }

    if (i == queue->count || x != queue->front->data) {
        enqueue(queue, x);
    }

    for (; i < queue->count; i++) {
        elem_type temp = queue->front->data;
        dequeue(queue);
        enqueue(queue, temp);
    }
}

void dequeue(q_type* queue)
{
    if (!is_empty(*queue)) {
        ll_type temp = queue->front;
        queue->front = queue->front->link;
        free(temp);
        queue->count--;
    }
}

elem_type front(q_type queue)
{
    return queue.front->data;
}
