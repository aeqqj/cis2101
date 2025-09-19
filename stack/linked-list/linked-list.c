#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef char elem_type;

typedef struct node {
    elem_type data;
    struct node* link;
}* s_type;

void init_stack(s_type*);
void read_stack(s_type*);
bool is_member(s_type*, elem_type);
void make_null(s_type*);

bool is_empty(s_type);

void push(s_type*, elem_type);
void pop(s_type*);
void insert_bottom(s_type*, elem_type);

elem_type top(s_type);

int main()
{
    s_type stack;

    init_stack(&stack);

    push(&stack, '1');
    push(&stack, '2');
    push(&stack, '3');
    push(&stack, '4');
    push(&stack, '5');
    insert_bottom(&stack, '0');

    printf("Insert result: ");
    read_stack(&stack);

    pop(&stack);
    pop(&stack);
    pop(&stack);
    pop(&stack);
    pop(&stack);
    pop(&stack);

    printf("Delete result: ");
    read_stack(&stack);
}

void init_stack(s_type* stack)
{
    *stack = NULL;
}

void read_stack(s_type* stack)
{
    if (!is_empty(*stack)) {
        s_type temp_stack;

        init_stack(&temp_stack);

        while (!is_empty(*stack)) {
            printf("%c ", (*stack)->data);
            push(&temp_stack, (*stack)->data);
            pop(stack);
        }

        while (!is_empty(temp_stack)) {
            push(stack, temp_stack->data);
            pop(&temp_stack);
        }
        printf("\n");
    }
}

bool is_member(s_type* stack, elem_type x)
{
    bool flag = false;

    if (!is_empty(*stack)) {
        s_type temp_stack;

        init_stack(&temp_stack);

        while (!is_empty(*stack)) {
            if ((*stack)->data == x) {
                flag = true;
            }
            push(&temp_stack, (*stack)->data);
            pop(stack);
        }

        while (!is_empty(temp_stack)) {
            push(stack, temp_stack->data);
            pop(&temp_stack);
        }
    }

    return flag;
}

void make_null(s_type* stack)
{
    while (!is_empty(*stack)) {
        pop(stack);
    }
}

bool is_empty(s_type stack)
{
    return (stack == NULL) ? true : false;
}

void push(s_type* stack, elem_type x)
{
    s_type new_node = (s_type)malloc(sizeof(struct node));

    if (new_node != NULL) {
        new_node->data = x;
        new_node->link = *stack;
        *stack = new_node;
    }
}

void pop(s_type* stack)
{
    if (!is_empty(*stack)) {
        s_type temp = *stack;
        *stack = (*stack)->link;
        free(temp);
    }
}

void insert_bottom(s_type* stack, elem_type x)
{
    s_type temp_stack;

    init_stack(&temp_stack);

    while (!is_empty(*stack)) {
        push(&temp_stack, (*stack)->data);
        pop(stack);
    }

    push(stack, x);

    while (!is_empty(temp_stack)) {
        push(stack, temp_stack->data);
        pop(&temp_stack);
    }
}

elem_type top(s_type stack)
{
    return (!is_empty(stack)) ? stack->data : '\0';
}
