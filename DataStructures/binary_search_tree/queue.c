#include <stdio.h>
#include <malloc.h>
#include "node.h"
#include "queue.h"

struct queue* create_queue()
{
    struct queue* qu = (struct queue*)malloc(sizeof(struct queue));
    qu->capacity = CAPACITY_DEFAULT;
    qu->size = 0;
    qu->nd = (struct node*)malloc(qu->capacity * sizeof(struct node));
    return qu;
}

struct node pop(struct queue* qu)
{
    if (!qu) return ;

    struct node nd = qu->nd[0];
    
    qu->size--;
    
    for (int i = 0; i < qu->size; ++i)
        qu->nd[i] = qu->nd[i + 1];
    
    if (CAPACITY_DECREASE(qu) >= CAPACITY_DEFAULT)
    {
        if (qu->size < CAPACITY_DECREASE(qu))
        {
            qu->capacity = CAPACITY_DECREASE(qu);
            qu->nd = (struct node*)realloc(qu->nd, qu->capacity * sizeof(struct node));
        }
    }

    return nd;
}

void push(struct queue* qu, struct node* nd)
{
    if (qu->size == qu->capacity)
    {
        qu->capacity = CAPACITY_INCREACE(qu);
        qu->nd = realloc(qu->nd, qu->capacity * sizeof(struct node));
        qu->nd[qu->size++] = *nd;
        return;
    }
    qu->nd[qu->size++] = *nd;
}

void delete_queue(struct queue* qu)
{
    if (qu->nd) free(qu->nd);
    free(qu);
}