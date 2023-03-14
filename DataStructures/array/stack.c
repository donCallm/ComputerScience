#include <malloc.h>
#include "stack.h"
#include "pair.h"

void init_stack(struct stack *stk)
{
    stk->top = 0;
    stk->capacity = CAPACITY_DEFAULT;
    stk->pr = (struct pair*)malloc(stk->capacity * sizeof(struct pair));
}

void push(struct stack *stk, int first_number, int second_number)
{
    if (stk->top == stk->capacity)
    {
        stk->capacity = STK_CAPACITY_INCREACE(stk);
        stk->pr = realloc(stk->pr, stk->capacity * sizeof(struct pair));
        stk->pr[stk->top].first = first_number;
        stk->pr[stk->top++].second = second_number;
        return;
    }
    stk->pr[stk->top].first = first_number;
    stk->pr[stk->top++].second = second_number;
}

struct pair pop(struct stack *stk)
{
    stk->top--;

    if (STK_CAPACITY_DECREASE(stk) >= CAPACITY_DEFAULT)
    {
        if (stk->top < STK_CAPACITY_DECREASE(stk))
        {
            stk->capacity = STK_CAPACITY_DECREASE(stk);
            stk->pr = (struct pair*)realloc(stk->pr, stk->capacity * sizeof(struct pair));
        }
    }

    return stk->pr[stk->top];
}

int is_not_empty(struct stack *stk)
{
    if (stk->top != 0)
        return 1;
    return 0;
}

void delete_stack(struct stack *stk)
{
    free(stk->pr);
    free(stk);
}