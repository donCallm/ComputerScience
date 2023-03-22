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
    if (list->head == NULL)
    {
        list->head = create_node();
        list->head->data = value;
        return;
    }

    struct node* iter = list->head;
    
    while (iter->next)
        iter = iter->next;

    iter->next = create_node();
    iter->next->data = value;
}

void delete_elem(struct linked_list *list, int index)
{
    if (list->head == NULL || index < 0)
        return;

    if (index == 0)
    {
        if (list->head->next == NULL)
        {
            free(list->head);
            list->head = NULL;
            return;
        }
        struct node* temp = &list->head;
        list->head->data = list->head->next->data;
        list->head->next = list->head->next->next;
        free(temp);
        temp = NULL;
        return;
    }

    struct node* pre_removed_node = list->head;
    struct node* removed_node = list->head;

    for (int i = 0; i < index - 1; ++i)
    {
        if (pre_removed_node->next == NULL)
            return;
        pre_removed_node = pre_removed_node->next;
    }

    removed_node = pre_removed_node->next;
    pre_removed_node->next = removed_node->next;
    free(removed_node);
    removed_node = NULL;
}

void fill_list(struct linked_list* list, int from, int to)
{
    for (int i = from; i <= to; ++i)
        add_elem(list, i);
}

void print_list(struct linked_list *list)
{
    if (list->head == NULL)
        return;

    if (list->head->next == NULL)
    {
        printf("data: %d\n", list->head->data);
        return;
    }

    struct node* iter = list->head;
    printf("data: %d\n", iter->data);
    
    while (iter->next)
    {
        iter = iter->next;
        printf("data: %d\n", iter->data);
    }
}

int contains(struct linked_list* list, int number)
{
    if (list->head == NULL)
        return;

    if (list->head->next == NULL)
    {
        if (list->head->data == number)
            return 1;
        return 0;
    }

    struct node* iter = list->head;

    while (iter->next)
    {
        if (iter->data == number)
            return 1;
        iter = iter->next;
    }
    
    return 0;
}

void reverse(struct linked_list* list)
{
    if (list->head == NULL || list->head->next == NULL)
        return;
    
    struct node* prev = NULL;
    struct node* current = list->head;
    struct node* next;

    while (current != NULL)
    {
        next = current->next; 
        current->next = prev;  
        prev = current;
        current = next;
    }
    list->head = prev;
}

void delete_list(struct linked_list* list)
{
    if (list->head == NULL)
    {
        free(list);
        return;
    }
    
    while (list->head->next)
        list->head = list->head->next;
        
    free(list->head);
    free(list);
}