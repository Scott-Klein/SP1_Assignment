#include "prio.c"

typedef struct iorb {
    int base_pri;
    struct iorb *link;
    char filler[100];
} IORB;

void sortList(IORB *head, int (*prio)(int))
{

}
