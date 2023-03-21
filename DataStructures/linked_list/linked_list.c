#include <malloc.h>
#include <stdio.h>
#include "node.h"
#include "linked_list.h"

struct linked_list* create_list()
{
    struct linked_list *list = (struct linked_list*)malloc(sizeof(struct linked_list));
    list->size = 0;
    list->head = create_node();
    return list;
}

void add_elem(struct linked_list *list, int value)
{
    if (list == NULL)
        return;

    if (list->size == 0)
    {
        list->head = create_node();
        list->head->data = value;
        list->size++;
        return;
    }

    struct node* last_node = list->head;
    
    for (size_t i = 0; i < list->size - 1; ++i)
        last_node = last_node->next;

    last_node->next = create_node();
    last_node->next->data = value;
    ++list->size;
}

void delete_elem(struct linked_list *list, int index)
{
    if (list == NULL || index < 0 || list->size <= index)
        return;

    if (index == 0)
    {
        if (list->head->next == NULL)
        {
            list->head->data = 0;
            --list->size;
            return;
        }

        list->head->data = list->head->next->data;
        list->head->next = list->head->next->next;
        --list->size;
        return;
    }

    struct node* pre_removed_node = list->head;
    struct node* removed_node = list->head;

    for (int i = 0; i < index - 1; ++i)
    {
        pre_removed_node = pre_removed_node->next;
    }

    removed_node = pre_removed_node->next;
    pre_removed_node->next = removed_node->next;
    delete_node(removed_node);
    --list->size;
}

void filling_list(struct linked_list* list, int from, int to)
{
    for (int i = from; i <= to; ++i)
        add_elem(list, i);
}

void print_list(struct linked_list *list)
{
    if (list == NULL || list->size == 0)
        return;
        
    printf("\nlist_size: %d\n", list->size);

    struct node* last_node = list->head;
    
    for (int i = 0; i < list->size; ++i)
    {
        printf("data: %d\n", last_node->data);
        last_node = last_node->next;
    }
}

int contains(struct linked_list* list, int number)
{
    if (list == NULL || list->size <= 0)
        return 0;

    if (list->size == 1)
    {
        if (list->head->data == number)
            return 1;
        return 0;
    }

    struct node* temp_list = list->head;

    for (int i = 0; i < list->size - 1; ++i)
    {
        if (temp_list->data == number)
            return 1;
        temp_list = temp_list->next;
    }
    
    return 0;
}

void delete_list(struct linked_list* list)
{
    while (list->head->next)
        list->head = list->head->next;
        
    free(list->head);
    list->head = NULL;
    free(list);
}