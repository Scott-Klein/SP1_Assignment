#include <stdio.h>
#include <stdlib.h>

void Swap(IORB *a, IORB *b);

typedef struct iorb
{
    int base_pri;
    struct iorb *link;
    char filler[100];
} IORB;

void sortList(IORB *head, int (*prio)(int))
{
    IORB *smallest = head;
    IORB *current = head;
    while (head != NULL)
    {
        while (current != NULL)
        {
            if (prio(smallest->base_pri) > prio(current->base_pri))
            {
                smallest = current;
            }
            current = current->link;
        }
        Swap(smallest, head);
        current = smallest->link;
    }
}

void Swap(IORB *a, IORB *b)
{
    IORB *bNext = a->link;
    IORB *aNext = b->link;

    a->link = aNext;
    b->link = bNext;
}