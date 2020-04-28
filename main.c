#include "sortList.c"
#include <stdlib.h>
#include <string.h>

void buildList(struct iorb *head);
void displayList(struct iorb *head);
void fill(struct iorb *toFill, int i);
struct iorb* buildBlock();
struct iorb *attachBlock(struct iorb *end);
int main()
{
    struct iorb *head;
    buildList(head);
    displayList(head);
    return 0;
}

void buildList(struct iorb *head)
{
    head = buildBlock();
    for (int i = 0; i < 9; i++)
    {
        head = attachBlock(head);
    }
}

void displayList(struct iorb *head)
{
    while (head != NULL)
    {
        printf("Description: this is i/o request %d", head->filler[0]);
        head = head->link;
    }
}

void fill(struct iorb *toFill, int i)
{
    char *input;

    char *test2;
    test2[0] = toFill->base_pri;
    test2[1] = '\0';
    strcat(input, i);
    strcat(input, test2);
    strcpy(toFill->filler, input);
}

//returns empty IORB with null link
struct iorb *buildBlock()
{
    struct iorb *block = (IORB *)malloc(sizeof(IORB));
    fill(block, 0);
    return block;
}

//creates new IORB and stores in link of end
struct iorb *attachBlock(struct iorb *end)
{
    end->link = (IORB *)malloc(sizeof(IORB));
    fill(end->link, 0);
    return end->link;
}