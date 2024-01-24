#include <stdio.h>
#include "sl_list.h"

#define IDLE 0
#define BUSY 1

int    system_state = IDLE;
int    process_ids = 0;
int    running_process = -1;
SLList ready_queue;
SLList blocked_queue;

int process_create( );
int is_process_running( int pid );
void current_process_blocks( );
void current_process_terminates( );
void process_wakup( int pid );
void print_status( int line );

int main( )
{
    list_init();
    ready_queue.first = NULL;
    blocked_queue.first = NULL;

    int p = process_create( );
    print_status( __LINE__ );

    current_process_terminates( );
    print_status( __LINE__ );

    int a = process_create( );
    int b = process_create( );
    int c = process_create( );
    int d = process_create( );
    int e = process_create( );
    int f = process_create( );
    printf("Processes have the following PIDs:\n"
           "a: %d\n"
           "b: %d\n"
           "c: %d\n"
           "d: %d\n"
           "e: %d\n"
           "f: %d\n", a,b,c,d,e,f );
    print_status( __LINE__ );

    int q = is_process_running( a );
    if( q )
        printf( "Process %d is running\n", a);
    else
        printf( "Process %d is not running\n", a );

    q = is_process_running( b );
    if( q )
        printf( "Process %d is running\n", b );
    else
        printf( "Process %d is not running\n", b );

    current_process_blocks( );
    print_status( __LINE__ );
    current_process_blocks( );
    current_process_blocks( );
    current_process_blocks( );
    current_process_blocks( );
    print_status( __LINE__ );
    current_process_blocks( );
    print_status( __LINE__ );

    process_wakup( c );
    print_status( __LINE__ );

    current_process_terminates( );
    print_status( __LINE__ );

    process_wakup( b );
    print_status( __LINE__ );
    process_wakup( d );
    print_status( __LINE__ );
    process_wakup( e );
    print_status( __LINE__ );
    process_wakup( f );
    print_status( __LINE__ );
    process_wakup( a );
    print_status( __LINE__ );
    current_process_terminates( );
    current_process_terminates( );
    current_process_terminates( );
    print_status( __LINE__ );
    current_process_terminates( );
    current_process_terminates( );
    print_status( __LINE__ );
}

void print_status( int line )
{
    printf( "At line %d\n", line );
    if( system_state == IDLE )
    {
        printf("    System IDLE\n");
    }
    else
    {
        printf("    System BUSY\n");
        printf("    Running process: %d\n", running_process);
    }

    printf("    Ready queue: ");
    list_print( &ready_queue );
    printf("\n");

    printf("    Blocked queue: ");
    list_print( &blocked_queue );
    printf("\n\n");
}

int process_create( )
{
    process_ids = process_ids + 1;

    int process_id = process_ids;

    printf( "Process %d created", process_id );
    if( system_state == IDLE )
    {
        running_process = process_id;
        system_state = BUSY;
        printf( " and running\n" );
    }
    else
    {
        list_enqueue( &ready_queue, process_id );
        printf( " and in ready queue\n" );
    }

    return process_id;
}

void current_process_terminates( )
{
    if( running_process >= 0 ) printf( "Process %d terminates\n", running_process );

    if( ready_queue.first == NULL )
    {
        system_state = IDLE;
        return;
    }

    int pid = list_dequeue( &ready_queue );

    running_process = pid;
}

int is_process_running( int pid )
{
    if( system_state == IDLE ) return 0;
    if( running_process == pid ) return 1;
    return 0;
}

void current_process_blocks( )
{
    if( system_state == IDLE ) return;

    if( running_process >= 0 ) printf( "Process %d blocks\n", running_process );

    list_enqueue( &blocked_queue, running_process );
    int pid = list_dequeue( &ready_queue );

    if( pid < 0 )
        system_state = IDLE;

    running_process = pid;
}

void process_wakup( int pid )
{
    int success = list_remove( &blocked_queue, pid );
    if( success < 0 )
        return;


    if( system_state != IDLE )
    {
        list_enqueue( &ready_queue, running_process );
        printf( "Process %d unblocked and in ready queue\n", pid );
    }
    else
    {
        system_state = BUSY;
        printf( "Process %d unblocked and running\n", pid );
    }

    running_process = pid;
}

