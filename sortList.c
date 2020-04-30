#include <stdio.h>
#include <stdlib.h>

typedef struct iorb
{
    int base_pri;
    struct iorb *link;
    char filler[100];
} IORB;

IORB* swap(IORB *head, int a, int b);

int max(int a, int b);

int count(IORB *list);

IORB* sortList(IORB *head, int (*prio)(int))
{
    IORB *current;
    int smallestIndex;
    int index;
    int start = 0;
    int size = count(head);
    for (int i = 0; i < size; i++)
    {
        current = head;
        int smallest = 50000;
        int index = 0;
        int smallestIndex = 0;
        int swapFlag = 0;
        while (current != NULL)
        {
            if (smallest > prio(current->base_pri) && index >= start)
            {
                smallest = prio(current->base_pri);
                smallestIndex = index;
                swapFlag = 1;
            }
            current = current->link;
            index++;
        }
        if (swapFlag)
        {
            head = swap(head, start, smallestIndex);
        }
        start++;
    }
    return head;
}

int count(IORB *list)
{
    int result = 0;
    while (list != NULL)
    {
        result++;
        list = list->link;
    }
    return result;
}

IORB* swap(IORB *head, int a, int b)
{
    IORB *current = head;
    IORB *aPrev = NULL;
    IORB *aBlock = NULL;
    IORB *bPrev = NULL;
    IORB *bBlock = NULL;
    IORB *aNext = NULL;
    IORB *bNext = NULL;

    int traversal = max(a + 1, b + 1);
    for (int i = 0; i < traversal; i++)
    {
        if (i == a - 1)
            aPrev = current;
        if (i == a)
            aBlock = current;
        if (i == b - 1)
            bPrev = current;
        if (i == b)
            bBlock = current;
        current = current->link;
    }
    bNext = bBlock->link;
    aNext = aBlock->link;

    if (aBlock != NULL && bBlock != NULL)
    {
        //Link previous Nodes
        if (aPrev != NULL)
        {
            aPrev->link = bBlock;
        }
        if (bPrev != NULL)
        {
            bPrev->link = aBlock;
        }
        if (aBlock != bNext)
        {
            aBlock->link = bNext;
        }
        else
        {
            aBlock->link = bBlock;
        }

        if (bBlock != aNext)
        {
            bBlock->link = aNext;
        }
        else
        {
            bBlock->link = aBlock;
        }

        if (aPrev == NULL)
        {
            return bBlock;
        } else if (bPrev == NULL)
        {
            return aBlock;
        }
        return head;
    }
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