#include<stdio.h>
#include<stdlib.h>

typedef struct list_item
{
        int a;
        struct list_item *next;
}list_item;

void erase_list(list_item *head)
{
        list_item *p=head;
        list_item *next1=NULL:wq;

        for(p=head;p!=NULL;p=next1)
        {
                next1=p->next;
                free(p);
        }
}
