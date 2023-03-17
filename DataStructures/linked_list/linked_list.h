#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct linked_list
{
    int size;
    struct node *first_node;
};

void create_list(struct linked_list *list, int value);
void add_elem(struct linked_list *list, int value);
void print_list(struct linked_list *list);
void delete_elem(struct linked_list *list, int index);

#endif
