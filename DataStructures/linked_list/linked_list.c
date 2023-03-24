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
        struct node* temp = list->head->next;
        free(list->head);
        list->head = temp;
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
        return 0;

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

void swap(struct linked_list* list, int first_index, int second_index)
{
    if (list->head == NULL || list->head->next == NULL || first_index == second_index)
        return;
    
    if (first_index > second_index)
    {
        int temp = first_index;
        first_index = second_index;
        second_index = temp;
    }

    struct node* first_node = list->head;
    struct node* second_node = list->head;

    for (int i = 0; i < second_index - 1; ++i)
    {
        if (second_node->next == NULL)
            return;
        if (i < first_index - 1)
            first_node = first_node->next;
        second_node = second_node->next;
    }
    
    struct node temp1 = *first_node;
    struct node temp2 = *second_node->next;
    first_node->next = second_node->next;
    second_node->next = temp1.next;

    first_node->next->next = temp1.next->next;
    second_node->next->next = temp2.next;
}

void merge_list(struct linked_list* first_list, struct linked_list* second_list, int index)
{
    if (first_list->head == NULL || second_list == NULL || first_list->head == second_list->head || index < 0)
        return;

    struct node* first_iter = first_list->head;
    for (int i = 0; i < index - 1; ++i)
    {
        if (first_iter->next == NULL)
            return;
        first_iter = first_iter->next;
    }
    
    struct node* temp = first_iter->next;
    first_iter->next = second_list->head;
    struct node* second_iter = second_list->head;

    while (second_iter->next)
        second_iter = second_iter->next;
    
    second_iter->next = temp;
}

void delete_list(struct linked_list* list)
{
    if (list->head == NULL)
    {
        free(list);
        list = NULL;
        return;
    }
    
    struct node* temp;
    while (list->head->next)
    {
        temp = list->head;
        list->head = list->head->next;
        free(temp);
        temp = NULL;
    }
        
    free(list->head);
    list->head = NULL;
    free(list);
    list = NULL;
}