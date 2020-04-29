#include <stdio.h>
#include <stdlib.h>

typedef struct iorb
{
    int base_pri;
    struct iorb *link;
    char filler[100];
} IORB;

void swap(IORB *head, int a, int b);

int max(int a, int b);

void sortList(IORB *head, int (*prio)(int))
{
    IORB *smallest = head;
    IORB *current = head;
    while (head != NULL)
    {
        printf("outerWHile\n");
        while (current != NULL)
        {
            if (prio(smallest->base_pri) > prio(current->base_pri))
            {
                smallest = current;
            }
            current = current->link;
        }
        //swap(smallest, head);
        current = smallest->link;
    }
}

void swap(IORB *head, int a, int b)
{

    IORB *current = head;
    IORB *aLess;
    IORB *aBlock;
    IORB *bLess;
    IORB *bBlock;
    IORB *aPlus;
    IORB *bPlus;

    int traversal = max(a + 1, b + 1);
    printf("traversal is %d, a is %d, b is %d\n", traversal, a, b);
    for (int i = 0; i < traversal+3; i++)
    {
        if (i == a - 1)
        {
            printf("\nI = %d\n", i);
            printf("a minus\n");
            aLess = current;
        }
        if (i == a)
        {
            printf("\nI = %d\n", i);
            printf("a\n");
            aBlock = current;
        }
        if (i == a + 1)
        {
            printf("\nI = %d\n", i);
            printf("a plus\n");
            aPlus = current;
        }
        if (i == b - 1)
        {
            printf("\nI = %d\n", i);
            printf("b minus\n");
            bLess = current;
        }
        if (i == b)
        {
            printf("\nI = %d\n", i);
            printf("b\n");
            bBlock = current;
        }
        if (i == b + 1)
        {
            printf("\nI = %d\n", i);
            printf("b plus\n");
            bPlus = current;
        }
        current = current->link;
    }
    if (aPlus != bBlock)
    {
        // make b point to a+1
        bBlock->link = aPlus;

        // make b-1 point to a
        bLess->link = aBlock;
    }
    else
    {
        //   b -> a
        bBlock->link = aBlock;
    }

    //   a-1 -> b
    aLess->link = bBlock;

    //   a -> b+1
    aBlock->link = bPlus;
}

int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}