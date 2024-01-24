#ifndef IN2140_QUEUE
#define IN2140_QUEUE

struct SLList;
struct SLListElement;

typedef struct SLList         SLList;
typedef struct SLList*        SLListPtr;
typedef struct SLListElement  SLListElement;
typedef struct SLListElement* SLListElementPtr;

struct SLList
{
    SLListElementPtr first;
};

void list_init( );
int  list_enqueue( SLListPtr queue, int val );
int  list_dequeue( SLListPtr queue );
int  list_remove( SLListPtr queue, int pid );
void list_print( SLListPtr queue );

#endif /* IN2140_QUEUE */

