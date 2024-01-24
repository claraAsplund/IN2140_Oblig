#include <stdio.h>
#include "queue.h"

struct QueueElement
{
    int             pid;
    QueueElementPtr next;
};

QueueElement elements[1000];

QueueElementPtr unused_elements = NULL;

void queue_init( )
{
    for( int i=0; i<1000; i++ )
    {
        elements[i].pid  = -1;
        elements[i].next = unused_elements;
        unused_elements  = &elements[i];
    }
}

QueueElementPtr queue_get_unused( )
{
    QueueElementPtr ptr = unused_elements;

    if( ptr == NULL ) return ptr;

    unused_elements = ptr->next;
    ptr->next = NULL;
    return ptr;
}

void queue_put_unused( QueueElementPtr ptr )
{
    ptr->pid        = -1;
    ptr->next       = unused_elements;
    unused_elements = ptr;
}

int queue_enqueue( QueuePtr queue, int pid )
{
    QueueElementPtr q = queue_get_unused( );
    if( q == NULL )
    {
        printf("There were no unused process blocks available. enqueue failed.\n");
        return 0;
    }

    q->pid = pid;
    q->next = NULL;

    if( queue->first == NULL )
    {
        queue->first = q;
        return 1;
    }

    QueueElement* iterator = queue->first;
    while( iterator->next != NULL )
    {
        iterator = iterator->next;
    }
    iterator->next = q;
    return 1;
}

int queue_dequeue( QueuePtr queue )
{
    if( queue->first == NULL ) return -1;

    QueueElementPtr ptr = queue->first;
    queue->first = ptr->next;

    int pid = ptr->pid;
    queue_put_unused( ptr );

    return pid;
}

int queue_remove( QueuePtr queue, int pid )
{
    if( queue->first == NULL ) return -1;

    QueueElementPtr ptr = queue->first;

    if( ptr->pid == pid ) return queue_dequeue( queue );

    while( ptr->next != NULL )
    {
        if( ptr->next->pid == pid )
        {
            QueueElementPtr tbd = ptr->next;
            ptr->next = tbd->next;
            queue_put_unused( tbd );
            return pid;
        }
        ptr = ptr->next;
    }

    return -1;
}

void queue_print( QueuePtr queue )
{
    QueueElement* iterator = queue->first;
    while( iterator != NULL )
    {
        printf( "%d ", iterator->pid );
        iterator = iterator->next;
    }
}

