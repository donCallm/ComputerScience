#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct linked_list
{
    struct node *head;
};

struct linked_list* create_list();
void add_elem(struct linked_list *list, int value);
void fill_list(struct linked_list* list, int from, int to);
void print_list(struct linked_list *list);
void delete_elem(struct linked_list *list, int index);
void delete_list(struct linked_list* list);
int contains(struct linked_list* list, int number);
void reverse(struct linked_list* list);
void swap(struct linked_list* list, int first_index, int second_index);
void merge_list(struct linked_list* first_list, struct linked_list* second_list, int index);
int compare_list(struct linked_list* list1, struct linked_list* list2);

#endif
