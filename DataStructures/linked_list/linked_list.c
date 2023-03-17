#include <malloc.h>
#include <stdio.h>
#include "node.h"
#include "linked_list.h"

void create_list(struct linked_list *list, int value)
{
    list->size = 1;
    list->first_node = (struct node*)malloc(sizeof(struct node));
    create_node(list->first_node, value);
}

void add_elem(struct linked_list *list, int value)
{
    if (list == NULL)
        return;

    struct node* last_node = list->first_node;
    
    for (size_t i = 0; i < list->size - 1; i++)
        last_node = last_node->next;

    last_node->next = (struct node*)malloc(sizeof(struct node));
    create_node(last_node->next, value);
    list->size++;
}

void delete_elem(struct linked_list *list, int index)
{
    if (list == NULL || list->size <= index)
        return;

    if (index == 0)
    {
        list->first_node->data = list->first_node->next->data;
        list->first_node->next = list->first_node->next->next;
        list->size--;
        return;
    }

    struct node* pre_removed_node = list->first_node;
    struct node* removed_node = list->first_node;

    for (size_t i = 0; i < index - 1; i++)
        pre_removed_node = pre_removed_node->next;

    for (size_t i = 0; i < index; i++)
        removed_node = removed_node->next;

    pre_removed_node->next = removed_node->next;
    delete_node(removed_node);
    list->size--;
}

void print_list(struct linked_list *list)
{
    if (list == NULL)
        return;
        
    printf("\nlist_size: %d\n", list->size);

    struct node* last_node = list->first_node;
    
    for (size_t i = 0; i < list->size; i++)
    {

        printf("data: %d\n", last_node->data);
        last_node = last_node->next;
    }
}