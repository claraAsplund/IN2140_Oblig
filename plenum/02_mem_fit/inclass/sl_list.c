#include <stdio.h>
#include <stdlib.h>
#include "sl_list.h"

Element* element_new( )
{
    /* allocate an element and initialize empty */
}

Element* element_new_init( int start, int size )
{
    /* allocate an element and initialize with parameters */
}

void element_delete( Element* elem )
{
    /* deallocate an element */
}

void list_init( List* list )
{
    /* initialize to an empty list */
}

void list_delete( List* list )
{
    /* deallocate all elements currently in the list */
}

void list_append( List* list, Element* elem )
{
    /* append the given element at the end of the list */
}

void list_insert( List* list, Element* elem )
{
    /* Assume that the list is sorted on entry.
     * Search for the last element whose start value is below elem->start and
     * insert after that element.
     * Do not check if the old and new ranges overlap.
     */
}

void list_compress( Element* base )
{
    /* support function for list_insert_and_merge */
}

void list_insert_and_merge( List* list, Element* elem )
{
    /* Do the same as list_insert, but whenever e->start + e->size == e->next->start,
     * merge those two elements into a single one.
     */
}

Element* find_first( List* list, int size )
{
    /* Find the first Element e whose size is larger or equal size.
     * If sizes are equal, remove e from the list and return it.
     * If e->size > size, create a new element with e->start and size
     * as values, and change e->start and e->size changed to reflect
     * that size units have been removed at the start of block e.
     */
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

