#include <malloc.h>
#include "item.h"
#include "hashtable.h"

struct hashtable* create_hashtable()
{
    struct hashtable* table = (struct hashtable*)malloc(sizeof(struct hashtable));
    table->capacity = CAPACITY_DEFAULT;
    table->size = 0;
    table->items = (struct item*)malloc(table->capacity * sizeof(struct item));
    return table;
}

int hash(int x, struct hashtable* table) 
{
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = (x >> 16) ^ x;
    
    return x % table->capacity;
}

void add(struct hashtable* table, int key, int value)
{
    if (table->items == NULL)
        return;

    int index = hash(key, table);
    if (index >= table->capacity)
    {
        table->capacity = CAPACITY_INCREACE(table);
        table->items = realloc(table->items, table->capacity * sizeof(struct item));
    }


    table->items[index].key = key;
    table->items[index].value = value;
    table->size++;

    if (table->size == table->capacity)
    {
        table->capacity = CAPACITY_INCREACE(table);
        table->items = realloc(table->items, table->capacity * sizeof(struct item));
    }
}

int get_elem(struct hashtable* table, int key)
{
    if (table->items == NULL)
        return -1;

    return table->items[hash(key, table)].value;
}

void fill_table(struct hashtable* table, int from, int to)
{
    if (table->items == NULL)
        return;

    if (from < to)
    {
        for (int i = from; i <= to; ++i)
            add(table, i, i);
        return;
    }
    
    for (int i = from; i >= to; --i)
        add(table, i, i);
}

void delete_elem(struct hashtable* table, int key)
{
    if (table->items == NULL)
        return;

    int index = hash(key, table);
    table->items[index].key = 0;
    table->items[index].value = 0;

    table->size--;
    if (table->size < table->capacity)
    {
        if (CAPACITY_DECREASE(table) >= CAPACITY_DEFAULT)
        {
            table->capacity = CAPACITY_DECREASE(table);
            table->items = realloc(table->items, table->capacity * sizeof(struct item));
        }
    }
}

void delete_table(struct hashtable* table)
{
    free(table->items);
    free(table);
}