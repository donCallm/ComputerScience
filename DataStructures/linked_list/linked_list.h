#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct linked_list
{
    int size;
    struct node *head;
};

struct linked_list* create_list();
void add_elem(struct linked_list *list, int value);
void filling_list(struct linked_list* list, int from, int to);
void print_list(struct linked_list *list);
void delete_elem(struct linked_list *list, int index);
void delete_list(struct linked_list* list);

#endif
