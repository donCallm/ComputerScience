#ifndef HASHTABLE_H
#define HASHTABLE_H
#define CAPACITY 5

struct hashtable
{
    int size;
    int capacity;
    struct item* items;
};

void create_hashtable(struct hashtable* table);
void add(struct hashtable* table);
int hash(int x);

#endif