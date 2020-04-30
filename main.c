#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sortList.c"
#include "prio.c"

IORB *buildList();

void displayList(IORB *head);
void displayOptions();
void freeOld(IORB *top);
char *fillerBuilder(int i, int priority);

int main()
{
    IORB *head = NULL;
    int input = -1;
    while (input != 0)
    {
        displayOptions();
        scanf("%d", &input);
        printf("\n");
        if (input == 1)
        {
            freeOld(head);
            head = NULL;
            head = buildList();
        }
        else if (input == 2)
        {
            head = sortList(head, prio);
        }
        else if (input == 3)
        {
            displayList(head);
        }
    }
    printf("Terminating...\n");
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

IORB *buildBlock(int i)
{
    IORB *block = (IORB *)malloc(sizeof(IORB));
    block->base_pri = rand() % 100;
    char *input = fillerBuilder(i, block->base_pri);
    strcpy(block->filler, input);
    return block;
}

IORB *buildList()
{
    IORB *top = buildBlock(0);
    IORB *current = top;
    for (int i = 0; i < 9; i++)
    {
        current->link = buildBlock(i + 1);
        current = current->link;
    }
    current->link = NULL;
    return top;
}

void displayOptions()
{
    printf("Please enter your choiece:\n\n0) Exit\n\n1) Build List\n\n2) Sort List (ascending)\n\n3) Display List\n\n Your choice: ");
}

void displayList(IORB *head)
{
    int count = 0;
    while (head != NULL && count++ < 15)
    {
        printf("%s\n", head->filler);
        head = head->link;
    }
    printf("\n");
}

char *fillerBuilder(int i, int priority)
{
    char *result = malloc(100);
    sprintf(result, "Description: this is i/o request %d, Base Priority: %d Priority %d", i, priority, 100 - priority);
    return result;
}