#include <stdio.h>
#include <stdio.h>
#include <malloc.h>
#include "node.h"
#include "linked_list.h"

void test_delete()
{
    printf("\n------test_delete------\n");

    struct linked_list list;
    create_list(&list, 0);

    for (size_t i = 1; i < 10; i++)
        add_elem(&list, i);
    
    print_list(&list);

    for (size_t i = 9; i != 0; i--)
        delete_elem(&list, i);
    
    print_list(&list);
    free(list.first_node);
}

void do_test()
{
    test_delete();
}