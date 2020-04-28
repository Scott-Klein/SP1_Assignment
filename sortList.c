#include <stdio.h>
#include <stdlib.h>

typedef struct iorb
{
    int base_pri;
    struct iorb *link;
    char filler[100];
} IORB;

void swap(struct iorb *a, struct iorb *b);

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
        swap(smallest, head);
        current = smallest->link;
    }
}

void swap(IORB *a, IORB *b)
{
    IORB *bNext = a->link;
    IORB *aNext = b->link;

    a->link = aNext;
    b->link = bNext;
}