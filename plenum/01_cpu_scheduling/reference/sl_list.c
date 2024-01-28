#include <stdio.h>
#include "sl_list.h"

struct SLListElement
{
    int              pid;
    SLListElementPtr next;
};

SLListElement elements[1000];

SLListElementPtr unused_elements = NULL;

void list_init( )
{
    for( int i=0; i<1000; i++ )
    {
        elements[i].pid  = -1;
        elements[i].next = unused_elements;
        unused_elements  = &elements[i];
    }
}

SLListElementPtr list_get_unused( )
{
    SLListElementPtr ptr = unused_elements;

    if( ptr == NULL ) return ptr;

    unused_elements = ptr->next;
    ptr->next = NULL;
    return ptr;
}

void list_put_unused( SLListElementPtr ptr )
{
    ptr->pid        = -1;
    ptr->next       = unused_elements;
    unused_elements = ptr;
}

int list_enqueue( SLListPtr list, int pid )
{
    SLListElementPtr q = list_get_unused( );
    if( q == NULL )
    {
        printf("There were no unused process blocks available. enqueue failed.\n");
        return 0;
    }

    q->pid = pid;
    q->next = NULL;

    if( list->first == NULL )
    {
        list->first = q;
        return 1;
    }

    SLListElement* iterator = list->first;
    while( iterator->next != NULL )
    {
        iterator = iterator->next;
    }
    iterator->next = q;
    return 1;
}

int list_dequeue( SLListPtr list )
{
    if( list->first == NULL ) return -1;

    SLListElementPtr ptr = list->first;
    list->first = ptr->next;

    int pid = ptr->pid;
    list_put_unused( ptr );

    return pid;
}

int list_remove( SLListPtr list, int pid )
{
    if( list->first == NULL ) return -1;

    SLListElementPtr ptr = list->first;

    if( ptr->pid == pid ) return list_dequeue( list );

    while( ptr->next != NULL )
    {
        if( ptr->next->pid == pid )
        {
            SLListElementPtr tbd = ptr->next;
            ptr->next = tbd->next;
            list_put_unused( tbd );
            return pid;
        }
        ptr = ptr->next;
    }

    return -1;
}

void list_print( SLListPtr list )
{
    SLListElement* iterator = list->first;
    while( iterator != NULL )
    {
        printf( "%d ", iterator->pid );
        iterator = iterator->next;
    }
}

