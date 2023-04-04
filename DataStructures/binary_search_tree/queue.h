#ifndef QUEUE_H
#define QUEUE_H

#define CAPACITY_DEFAULT 5
#define CAPACITY_INCREACE(qu) ((int)(qu->capacity * 2))
#define CAPACITY_DECREASE(qu) ((int)(qu->capacity / 2))

struct queue
{
    int capacity;
    int size;
    struct node* nd;
};

struct queue* create_queue();
struct node pop(struct queue* qu);
void push(struct queue* qu, struct node* nd);
void delete_queue(struct queue* qu);

#endif