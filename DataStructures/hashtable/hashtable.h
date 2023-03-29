#ifndef HASHTABLE_H
#define HASHTABLE_H
#define CAPACITY_DEFAULT 5
#define CAPACITY_INCREACE(table) ((int)(table->capacity * 2))
#define CAPACITY_DECREASE(table) ((int)(table->capacity / 2))

struct hashtable
{
    int size;
    int capacity;
    struct item* items;
};

struct hashtable* create_hashtable();
void add(struct hashtable* table, int key, int value);
int hash(int x, struct hashtable* table);
int get_elem(struct hashtable* table, int key);
void fill_table(struct hashtable* table, int from, int to);
void delete_elem(struct hashtable* table, int key);
void delete_table(struct hashtable* table);

#endif