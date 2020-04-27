#include "sortList.c"
#include <stdlib.h>

void buildList(IORB *head);
void displayList(IORB *head);
void fill(char **toFill);

int main()
{
    IORB *head;
    buildList(head);
    displayList(head);
    return 0;
}

void buildList(IORB *head)
{
    head = (IORB *)malloc(sizeof(IORB));
    head->base_pri = rand() % 100;
    for (int i = 0; i < 9; i++)
    {
        head->link = (IORB *)malloc(sizeof(IORB));
        head = head->link;
        head->base_pri = rand() % 100;
        head->filler[2] = 'a';
    }
}

void displayList(IORB *head)
{
    while (head != NULL)
    {
        /* code */
    }

}

void fill(char **toFill)
{

}