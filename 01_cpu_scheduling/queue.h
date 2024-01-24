#ifndef IN2140_QUEUE
#define IN2140_QUEUE

struct Queue;
struct QueueElement;

typedef struct Queue         Queue;
typedef struct Queue*        QueuePtr;
typedef struct QueueElement  QueueElement;
typedef struct QueueElement* QueueElementPtr;

struct Queue
{
    QueueElementPtr first;
};

void queue_init( );
int queue_enqueue( QueuePtr queue, int val );
int queue_dequeue( QueuePtr queue );
int queue_remove( QueuePtr queue, int pid );
void queue_print( QueuePtr queue );

#endif /* IN2140_QUEUE */

