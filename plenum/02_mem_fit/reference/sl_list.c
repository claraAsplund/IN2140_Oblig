#include <stdio.h>
#include <stdlib.h>
#include "sl_list.h"

Element* element_new( )
{
    Element* e = malloc( sizeof(Element) );
    e->start = 0;
    e->size  = 0;
    e->next  = NULL;
    return e;
}

Element* element_new_init( int start, int size )
{
    Element* e = malloc( sizeof(Element) );
    e->start = start;
    e->size  = size;
    e->next  = NULL;
    return e;
}

void element_delete( Element* elem )
{
    if( elem == NULL ) return;
    free( elem );
}

void list_init( List* list )
{
    list->first = NULL;
}

void list_delete( List* list )
{
    while( list->first != NULL )
    {
        Element* e = list->first;
        list->first = e->next;
        element_delete( e );
    }
}

void list_append( List* list, Element* elem )
{
    if( list->first == NULL )
    {
        list->first = elem;
        return;
    }

    Element* iterator = list->first;
    while( iterator->next != NULL ) iterator = iterator->next;
    iterator->next = elem;
}

void list_insert( List* list, Element* elem )
{
    if( list->first == NULL )
    {
        list->first = elem;
        return;
    }

    if( list->first->start > elem->start )
    {
        elem->next = list->first;
        list->first = elem;
        return;
    }

    Element* iterator = list->first;
    while( iterator->next != NULL && iterator->next->start < elem->start )
    {
        iterator = iterator->next;
    }
    
    if( iterator->next == NULL )
    {
        iterator->next = elem;
        return;
    }

    elem->next = iterator->next;
    iterator->next = elem;
}

void list_compress( Element* base )
{
    while( base->next != NULL )
    {
        Element* next = base->next;
        if( next == NULL ) return;
        if( base->start + base->size < next->start ) return;

        if( base->start + base->size > next->start )
        {
            printf("Programming Error for sorted lists. List is not ordered.\n");
            return;
        }

        base->size = base->size + next->size;
        base->next = next->next;
        element_delete( next );
    }
}

void list_insert_and_merge( List* list, Element* elem )
{
    if( list->first == NULL )
    {
        list->first = elem;
        return;
    }

    if( list->first->start > elem->start )
    {
        elem->next = list->first;
        list->first = elem;
        list_compress( list->first );
        return;
    }

    Element* iterator = list->first;
    while( iterator->next != NULL && iterator->next->start < elem->start )
    {
        if( iterator->start + iterator->size == elem->start )
        {
            elem->next = iterator->next;
            iterator->next = elem;
            list_compress( iterator );
            return;
        }

        iterator = iterator->next;
    }
    
    if( iterator->next == NULL )
    {
        iterator->next = elem;
        list_compress( iterator );
        return;
    }

    elem->next = iterator->next;
    iterator->next = elem;
    list_compress( iterator );
}

Element* find_first( List* list, int size )
{
    Element* retval;

    if( list->first == NULL ) return NULL;

    Element* iterator = list->first;
    if( iterator->size == size )
    {
        list->first = iterator->next;
        iterator->next = NULL;
        return iterator;
    }
    if( iterator->size > size )
    {
        retval = element_new_init( iterator->start, size );
        iterator->start = iterator->start + size;
        iterator->size  = iterator->size  - size;
        return retval;
    }

    while( iterator->next != NULL && iterator->next->size < size )
    {
        iterator = iterator->next;
    }

    if( iterator->next == NULL ) return NULL;

    if( iterator->next->size == size )
    {
        retval = iterator->next;
        iterator->next = retval->next;
        retval->next = NULL;
        return retval;
    }

    retval = element_new_init( iterator->next->start, size );
    iterator->next->start = iterator->next->start + size;
    iterator->next->size  = iterator->next->size  - size;
    return retval;
}

void list_print( List* list )
{
    printf("List:\n");

    if( list->first == NULL )
    {
        printf("    EMPTY\n");
        return;
    }

    Element* iterator = list->first;
    while( iterator )
    {
        printf("    from: %d size: %d, next: %d\n", iterator->start, iterator->size, iterator->start + iterator->size );
        iterator = iterator->next;
    }
}

void list_draw( List* list, int limit )
{
    int i = 0;

    if( list->first == NULL )
    {
        for( i=0; i<limit; i++ ) printf("X");
        printf("\n");
        return;
    }

    Element* iterator = list->first;
    while( iterator != NULL )
    {
        for(    ; i<iterator->start; i++ ) printf("X");
        for(    ; i<iterator->start + iterator->size; i++ ) printf(".");
        iterator = iterator->next;
    }
    for(    ; i<limit; i++ ) printf("X");
    printf("\n");
}

