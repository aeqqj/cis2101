#include <stdbool.h>
#include <stdio.h>

#define Q_MAX 9
#define MAX (Q_MAX + 1)

typedef char elem_type;

typedef struct {
    elem_type data[MAX];
    int front;
    int rear;
} q_type;

void init_queue(q_type*);
void read_queue(q_type);
bool is_member(q_type, elem_type);
void make_null(q_type*);
int stop(int);

bool is_full(q_type);
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
    enqueue(&queue, '2');
    enqueue(&queue, '4');
    enqueue(&queue, '5');
    enqueue_sorted(&queue, '3');
    enqueue_sorted_unique(&queue, '0');
    enqueue_sorted_unique(&queue, '3');

    printf("Insert result: ");
    read_queue(queue);
}

void init_queue(q_type* queue)
{
    queue->front = 0;
    queue->rear = Q_MAX;
}

void read_queue(q_type queue)
{
    if (!is_empty(queue)) {
        int q_stop = stop(queue.rear);
        elem_type temp;

        for (; q_stop != queue.front; dequeue(&queue)) {
            printf("%c ", queue.data[queue.front]);
        }
    }
}

bool is_member(q_type queue, elem_type x)
{
    int q_stop = stop(queue.rear);
    if (!is_empty(queue)) {
        elem_type temp;

        for (; q_stop != queue.front && x != queue.data[queue.front]; dequeue(&queue)) { }
    }
    return (q_stop != queue.front) ? true : false;
}

void make_null(q_type* queue)
{
    queue->front = 0;
    queue->rear = Q_MAX;
}

int stop(int rear)
{
    return (rear + 1) % MAX;
}

bool is_full(q_type queue)
{
    return (queue.rear + 2) % MAX == queue.front;
}

bool is_empty(q_type queue)
{
    return (queue.rear + 1) % MAX == queue.front;
}

void enqueue(q_type* queue, elem_type x)
{
    if (!is_full(*queue)) {
        queue->rear = (queue->rear + 1) % MAX;
        queue->data[queue->rear] = x;
    }
}

void enqueue_sorted(q_type* queue, elem_type x)
{
    if (!is_full(*queue)) {
        int q_stop = stop(queue->rear);
        elem_type temp;

        for (; q_stop != queue->front && x > queue->data[queue->front]; enqueue(queue, temp)) {
            temp = queue->data[queue->front];
            dequeue(queue);
        }

        enqueue(queue, x);

        for (; q_stop != queue->front; enqueue(queue, temp)) {
            temp = queue->data[queue->front];
            dequeue(queue);
        }
    }
}
void enqueue_sorted_unique(q_type* queue, elem_type x)
{
    if (!is_full(*queue)) {
        int q_stop = stop(queue->rear);
        elem_type temp;

        for (; q_stop != queue->front && x > queue->data[queue->front]; enqueue(queue, temp)) {
            temp = queue->data[queue->front];
            dequeue(queue);
        }

        if (q_stop == queue->front || x != queue->data[queue->front]) {
            enqueue(queue, x);
        }

        for (; q_stop != queue->front; enqueue(queue, temp)) {
            temp = queue->data[queue->front];
            dequeue(queue);
        }
    }
}

void dequeue(q_type* queue)
{
    if (!is_empty(*queue)) {
        queue->front = (queue->front + 1) % MAX;
    }
}

elem_type front(q_type queue)
{
    return (!is_empty(queue)) ? queue.data[queue.front] : '\0';
}
