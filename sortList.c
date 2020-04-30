#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct iorb
{
    int base_pri;
    struct iorb *link;
    char filler[100];
} IORB;

//Swaps the nodes at position a and b of list pointed to by head
//returns pointer to new head node, since the top might have changed
IORB* swap(IORB *head, int a, int b);

//Returns the higher value from a and b.
int max(int a, int b);

//counts the number of nodes in the list.
int count(IORB *list);

//sorts the list in ascending order.
//returns pointer to new head because the head may be different.
IORB* sortList(IORB *head, int (*prio)(int))
{
    IORB *current;
    int start = 0;
    int size = count(head);

    //bring the smallest node to the front and then move on.
    for (int i = 0; i < size; i++)
    {
        current = head;
        int smallest = 50000;
        int index = 0;
        int smallestIndex = 0;
        int swapFlag = 0;
        //
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

    int traversal = max(a + 1, b + 1); //find the distance that we need to travel
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
    //make sure that the nodes are not null.
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
        if (aBlock != bNext) // prevent a pointing to itself
        {
            aBlock->link = bNext;
        }
        else // a is now before b
        {
            aBlock->link = bBlock;
        }

        if (bBlock != aNext) // prevent b pointing to itself
        {
            bBlock->link = aNext;
        }
        else // b is now before a
        {
            bBlock->link = aBlock;
        }

        //if a was the first node, now b is so return b as the new head.
        if (aPrev == NULL)
        {
            return bBlock;
        } else if (bPrev == NULL) // if b was the first node, now a is first, so return a as the new head.
        {
            return aBlock;
        }
        return head; // the head has not been swapped so return it untouched.
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