#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sortList.c"
#include "prio.c"
#include "helpers.c"

//Creates a list of 10  struct iorb,
//Returns pointer to first node
IORB *buildList();

//Prints the contents of the filler in each node of the list pointed to by head
void displayList(IORB *head);

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
            freeOld(head); // clean up an old list if building a new one.
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
        else
        {
            printf("Your input was not recognised, please enter a number (0-3)\n");
        }
    }
    printf("Terminating...\n");
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
    current->link = NULL; //explicitly terminate the end of the list.
    return top;
}

void displayList(IORB *head)
{
    while (head != NULL) //while not at the end of the list print the contents
    {
        printf("%s\n", head->filler);
        head = head->link; //select the next node.
    }
    printf("\n");
}

