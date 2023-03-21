#include <malloc.h>
#include <stdio.h>
#include "node.h"
#include "linked_list.h"

struct linked_list* create_list()
{
    struct linked_list *list = (struct linked_list*)malloc(sizeof(struct linked_list));
    list->head = NULL;
    return list;
}

void add_elem(struct linked_list *list, int value)
{
    if (list == NULL)
        return;

    if (list->head == NULL)
    {
        list->head = create_node();
        list->head->data = value;
        return;
    }

    struct node* last_node = list->head;
    
    while (last_node->next)
        last_node = last_node->next;

    last_node->next = create_node();
    last_node->next->data = value;
}

void delete_elem(struct linked_list *list, int index)
{
    if (list == NULL || index < 0)
        return;

    if (index == 0)
    {
        if (list->head->next == NULL)
        {
            free(list->head);
            list->head = NULL;
            return;
        }

        list->head->data = list->head->next->data;
        list->head->next = list->head->next->next;
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
    free(removed_node);
    removed_node = NULL;
}

void filling_list(struct linked_list* list, int from, int to)
{
    if (list == NULL)
        return;

    for (int i = from; i <= to; ++i)
        add_elem(list, i);
}

void print_list(struct linked_list *list)
{
    if (list == NULL || list->head == NULL)
        return;

    if (list->head->next == NULL)
    {
        printf("\ndata: %d\n", list->head->data);
        return;
    }

    struct node* last_node = list->head;
    printf("\ndata: %d\n", last_node->data);
    
    while (last_node->next)
    {
        last_node = last_node->next;
        printf("\ndata: %d\n", last_node->data);
    }
}

int contains(struct linked_list* list, int number)
{
    if (list == NULL)
        return 0;

    if (list->head->next == NULL)
    {
        if (list->head->data == number)
            return 1;
        return 0;
    }

    struct node* temp_list = list->head;

    while (temp_list->next)
    {
        if (temp_list->data == number)
            return 1;
        temp_list = temp_list->next;
    }
    
    return 0;
}

void delete_list(struct linked_list* list)
{
    if (list == NULL)
        return;
    
    if (list->head == NULL)
    {
        free(list);
        return;
    }
    
    while (list->head->next)
        list->head = list->head->next;
        
    free(list->head);
    list->head = NULL;
    free(list);
}