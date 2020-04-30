#pragma once
#include "sortList.c"

void displayOptions()
{
    printf("Please enter your choiece:\n\n0) Exit\n\n1) Build List\n\n2) Sort List (ascending)\n\n3) Display List\n\nYour choice: ");
}

void freeOld(IORB *top)
{
    IORB *next;
    while (top != NULL)
    {
        next = top->link;
        free(top);
        top = next;
    }
}

char *fillerBuilder(int i, int priority)
{
    char *result = malloc(100);
    sprintf(result, "Description: this is i/o request %d, Base Priority: %d Priority %d", i, priority, 100 - priority);
    return result;
}

IORB *buildBlock(int i)
{
    IORB *block = (IORB *)malloc(sizeof(IORB));
    block->base_pri = rand() % 100;
    char *input = fillerBuilder(i, block->base_pri);
    strcpy(block->filler, input);
    return block;
}