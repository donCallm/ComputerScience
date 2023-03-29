#include <malloc.h>
#include <stdio.h>
#include "hashtable.h"
#include "item.h"

void test_hash()
{
    int number = 10;
    int number1 = hash(number);
    printf("TEST: %d\n", number1);
}

void do_test()
{
    test_hash();
}