#ifndef STACK_H
#define STACK_H

#define CAPACITY_DEFAULT 5
#define STK_CAPACITY_INCREACE(stk) ((int)(stk->capacity * 2))
#define STK_CAPACITY_DECREASE(stk) ((int)(stk->capacity / 2))

struct stack
{
    struct pair *pr;
    int capacity;
    int top;
};

void init_stack(struct stack *stk);
void push(struct stack *stk, int first_number, int second_number);
struct pair pop(struct stack *stk);
int is_not_empty(struct stack *stk);
void delete_stack(struct stack *stk);

#endif