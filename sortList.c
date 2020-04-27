#include "prio.c"

void Swap(IORB *a, IORB* b);

typedef struct iorb {
    int base_pri;
    struct iorb *link;
    char filler[100];
} IORB;

void sortList(IORB *head, int (*prio)(int))
{

}

void selectionSort(IORB *head)
{
    IORB *smallest = head;
    IORB *current = head;
    while (current != NULL)
    {
        if (smallest->base_pri < current->base_pri)
        {
            smallest = current;
        }
        current = current->link;
    }
    Swap(smallest, head);
}

void Swap(IORB* a, IORB* b)
{
    IORB *aNext = a->link;
    IORB *temp = b;

    //do the swapping.
    b = a;
    a = temp;

    //Rewire the links.
    b->link = a->link;
    a->link = aNext;
}