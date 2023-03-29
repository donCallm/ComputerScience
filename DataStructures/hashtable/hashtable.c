#include <malloc.h>
#include "item.h"
#include "hashtable.h"

void create_hashtable(struct hashtable* table)
{
    table->capacity = CAPACITY;
    table->size = 0;
    //table->items = (struct hashtable*)malloc(table->capacity * sizeof(struct hashtable));
}

void add(struct hashtable* table)
{
    
}

int hash(int x) 
{
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = (x >> 16) ^ x;
    return x;
}