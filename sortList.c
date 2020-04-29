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
    IORB *current;
    int smallestIndex;
    int index;
    while (head != NULL)
    {
        //smallestIndex = 0;
        //index = 0;
        //current = head;
        //smallest = head;
        //while (current != NULL)
        //{
        //    if (prio(smallest->base_pri) > prio(current->base_pri))
        //    {
        //        smallest = current;
        //        smallestIndex = index;
        //        printf("smallest priority detected %d, at index: ", prio(smallest->base_pri));
        //        printf("%d\n", index);
        //    }
        //    current = current->link;
        //    index++;
        //}
        //swap(head, 0, smallestIndex);
        current = head;
        int smallest = 50000;
        int index = 0;
        int smallestIndex = 0;
        int swapFlag = 0;
        while (current->link != NULL)
        {
            if (smallest > current->base_pri)
            {
                smallest = current->base_pri;
                smallestIndex = index;
                swapFlag = 1;
            }
            current = current->link;
            index++;
        }
        if (swapFlag)
        {
            swap(head, 0, smallestIndex);
        }
        head = head->link;
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

    int traversal = max(a + 1, b + 1) + 1;
    printf("A is %d, B is %d\n", a, b);
    for (int i = 0; i < traversal; i++)
    {
        if (i == a - 1)
            aLess = current;
        if (i == a)
            aBlock = current;
        if (i == a + 1)
            aPlus = current;
        if (i == b - 1)
            bLess = current;
        if (i == b)
            bBlock = current;
        if (i == b + 1)
            bPlus = current;
        current = current->link;
    }
    if (aPlus != bBlock)
    {
        // make b point to a+1
        if (aPlus != NULL)
        {
            bBlock->link = aPlus;
        }
        // make b-1 point to a
        bLess->link = aBlock;
    }
    else
    {
        //   b -> a
        bBlock->link = aBlock;
    }

    //   a-1 -> b
    aLess->link = bBlock; //SEGMENTATION FAUlt;

    //   a -> b+1
    if (bPlus != NULL)
    {
        aBlock->link = bPlus;
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