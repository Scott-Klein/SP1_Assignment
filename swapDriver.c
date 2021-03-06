#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sortList.c"
#include "prio.c"

void buildList(IORB *head);

void displayList(IORB *head);

char *fillerBuilder(int i, int priority);

IORB *getAt(IORB *head, int target);

int main()
{
    IORB *head = (IORB *)malloc(sizeof(IORB));
    head->base_pri = rand() % 100;
    char *input = fillerBuilder(0, head->base_pri);
    strcpy(head->filler, input);

    buildList(head);
    displayList(head);
    swap(head,3,4);
    displayList(head);
}

void buildList(IORB *head)
{
    IORB *next;

    head->link = (IORB *)malloc(sizeof(IORB));

    next = head->link;

    for (int i = 0; i < 9; i++)
    {
        next->base_pri = rand() % 100;
        char *input = fillerBuilder(i + 1, next->base_pri);
        strcpy(next->filler, input);
        next->link = (IORB *)malloc(sizeof(IORB));

        next = next->link;
    }
}

void displayList(IORB *head)
{
    int count = 0;
    while (head != NULL && count++ < 15)
    {
        printf("%s\n", head->filler);
        head = head->link;
    }
}

char *fillerBuilder(int i, int priority)
{
    char *result = malloc(100);
    sprintf(result, "Description: this is i/o request %d, Base Priority: %d Priority %d", i, priority, 100 - priority);
    return result;
}

IORB* getAt(IORB* head, int target)
{
    IORB *current = head;
    for (int i = 0; i < target; i++)
    {
            current = current->link;
    }
    return current;
}