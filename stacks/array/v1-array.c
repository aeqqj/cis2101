#include <stdbool.h>
#include <stdio.h>

#define MAX 20

typedef char elem_type;

typedef struct {
    elem_type data[MAX];
    int top;
} s_type;

void init_stack(s_type*);
void read_stack(s_type);
bool is_member(s_type, elem_type);
void make_null(s_type*);

bool is_full(s_type);
bool is_empty(s_type);

void push(s_type*, elem_type);
void push_sorted(s_type*, elem_type);
void push_sorted_unique(s_type*, elem_type);
void pop(s_type*);
void insert_bottom(s_type*, elem_type);

elem_type top(s_type);

int main()
{
    s_type stack;
    int i;

    init_stack(&stack);

    push(&stack, '1');
    push(&stack, '2');
    push(&stack, '3');
    push(&stack, '4');
    push(&stack, '5');
    insert_bottom(&stack, '0');

    printf("Insert result: ");
    read_stack(stack);

    pop(&stack);
    pop(&stack);
    pop(&stack);
    pop(&stack);
    pop(&stack);
    pop(&stack);

    printf("Delete result: ");
    read_stack(stack);
}

void init_stack(s_type* stack)
{
    stack->top = -1;
}

void read_stack(s_type stack)
{
    while (!is_empty(stack)) {
        printf("%c ", stack.data[stack.top]);
        pop(&stack);
    }
    printf("\n");
}

bool is_member(s_type stack, elem_type x)
{
    bool flag = false;
    if (!is_empty(stack)) {
        if (stack.data[stack.top] == x) {
            flag = true;
        }
        pop(&stack);
    }
    return flag;
}

void make_null(s_type* stack)
{
    if (!is_empty(*stack)) {
        stack->top = -1;
    }
}

bool is_full(s_type stack)
{
    return (stack.top == MAX - 1) ? true : false;
}

bool is_empty(s_type stack)
{
    return (stack.top == -1) ? true : false;
}

void push(s_type* stack, elem_type x)
{
    if (!is_full(*stack)) {
        stack->data[++stack->top] = x;
    }
}

void push_sorted(s_type* stack, elem_type x)
{
    if (!is_full(*stack)) {
        s_type temp_stack;

        init_stack(&temp_stack);

        while (!is_empty(*stack) && x > stack->data[stack->top]) {
            push(&temp_stack, stack->data[stack->top]);
            pop(stack);
        }

        push(stack, x);

        while (!is_empty(temp_stack)) {
            push(stack, temp_stack.data[temp_stack.top]);
            pop(&temp_stack);
        }
    }
}

void push_sorted_unique(s_type* stack, elem_type x)
{
    if (!is_full(*stack)) {
        s_type temp_stack;

        init_stack(&temp_stack);

        while (!is_empty(*stack) && x > stack->data[stack->top]) {
            push(&temp_stack, stack->data[stack->top]);
            pop(stack);
        }

        if (stack->top == -1 || x != stack->data[stack->top]) {
            push(stack, x);
        }

        while (!is_empty(temp_stack)) {
            push(stack, temp_stack.data[temp_stack.top]);
            pop(&temp_stack);
        }
    }
}

void pop(s_type* stack)
{
    if (!is_empty(*stack)) {
        stack->top--;
    }
}

void insert_bottom(s_type* stack, elem_type x)
{
    if (!is_full(*stack)) {
        s_type temp_stack;

        init_stack(&temp_stack);
        while (!is_empty(*stack)) {
            push(&temp_stack, stack->data[stack->top]);
            pop(stack);
        }

        push(stack, x);

        while (!is_empty(temp_stack)) {
            push(stack, temp_stack.data[temp_stack.top]);
            pop(&temp_stack);
        }
    }
}

elem_type top(s_type stack)
{
    return (!is_empty(stack)) ? stack.data[stack.top] : '\0';
}
