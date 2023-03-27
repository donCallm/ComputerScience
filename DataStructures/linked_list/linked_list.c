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
    if (from < to)
    {
        for (int i = from; i <= to; ++i)
            add_elem(list, i);
        return;
    }
    
    for (int i = from; i >= to; --i)
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

    while (iter)
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
    
    int min_index = (first_index < second_index) ? first_index : second_index;
    int max_index = (first_index > second_index) ? first_index : second_index;

    struct node* p_to_first_node = list->head;
    struct node* sec_node = list->head;

    for (int i = 0; i < max_index; ++i)
    {
        if (sec_node->next == NULL)
            return; 
        if (i < min_index - 1)
            p_to_first_node = p_to_first_node->next;
        sec_node = sec_node->next;
    }
    
    if (min_index == 0)
    {
        struct node* old_head = list->head;
        struct node* sec_node_next = sec_node->next;
        sec_node->next = old_head->next;
        list->head = sec_node;

        struct node* iter = list->head;
        while (iter->next != sec_node)
            iter = iter->next;
        
        iter->next = old_head;
        old_head->next = sec_node_next;
        return;
    }

    if (p_to_first_node == sec_node)
        return;

    struct node* next_sec_node = sec_node->next;
    struct node* first_node = p_to_first_node->next;
    struct node* iter = sec_node;

    sec_node->next = first_node->next;
    while(iter->next != sec_node)
        iter = iter->next;

    iter->next = first_node;
    first_node->next = next_sec_node;
    p_to_first_node->next = sec_node;
}

void merge_list(struct linked_list* first_list, struct linked_list* second_list, int index)
{
    if (first_list->head == NULL || second_list == NULL || first_list->head == second_list->head || index < 0)
        return;

    struct node* first_iter;
    struct node* second_iter;

    if (index == 0)
    {
        struct node* old_head = first_list->head;
        first_list->head = create_node();
        first_list->head->data = second_list->head->data;
        first_iter = first_list->head;
        second_iter = second_list->head->next;

        while (second_iter)
        {
            first_iter->next = create_node();
            first_iter->next->data = second_iter->data;
            first_iter = first_iter->next;
            second_iter = second_iter->next;
        }
        
        first_iter->next = old_head;
        return;
    }    

    first_iter = first_list->head;
    second_iter = second_list->head;

    for (int i = 0; i < index - 1; ++i)
    {
        if (first_iter->next == NULL)
            return;
        first_iter = first_iter->next;
    }

    struct node* temp = first_iter->next;

    while (second_iter)
    {
        first_iter->next = create_node();
        first_iter->next->data = second_iter->data;
        second_iter = second_iter->next;
        first_iter = first_iter->next;
    }
    
    first_iter->next = temp;
}

int compare_list(struct linked_list* list1, struct linked_list* list2)
{
    if (list1->head == NULL || list2->head == NULL || list1->head == list2->head)
        return 0;

    struct node* first_iter = list1->head;
    struct node* second_iter = list2->head;

    while (first_iter->next || second_iter->next)
    {
        if (first_iter->data != second_iter->data)
            return 0;
        if ((first_iter->next == NULL && second_iter->next != NULL) || (first_iter->next != NULL && second_iter->next == NULL))
            return 0;
        first_iter = first_iter->next;
        second_iter = second_iter->next;
    }
    
    return 1;
}

void delete_list(struct linked_list* list)
{
    if (!list->head)
    {
        free(list);
        return;
    }
    
    struct node* temp;
    while (list->head->next)
    {
        temp = list->head;
        list->head = list->head->next;
        free(temp);
    }
        
    free(list->head);
    free(list);
}