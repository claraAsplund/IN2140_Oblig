#include "allocation.h"
#include "inode.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

/* The number of bytes in a block.
 * Do not change.
 */
#define BLOCKSIZE 4096

/* The lowest unused node ID.
 * Do not change.
 */
static int num_inode_ids = 0;

/* This helper function computes the number of blocks that you must allocate
 * on the simulated disk for a give file system in bytes. You don't have to use
 * it.
 * Do not change.
 */
static int blocks_needed( int bytes )
{
    int blocks = bytes / BLOCKSIZE;
    if( bytes % BLOCKSIZE != 0 )
        blocks += 1;
    return blocks;
}

/* This helper function returns a new integer value when you create a new inode.
 * This helps you do avoid inode reuse before 2^32 inodes have been created. It
 * keeps the lowest unused inode ID in the global variable num_inode_ids.
 * Make sure to update num_inode_ids when you have loaded a simulated disk.
 * Do not change.
 */
static int next_inode_id( )
{
    int retval = num_inode_ids;
    num_inode_ids += 1;
    return retval;
}

struct inode* create_file( struct inode* parent, char* name, int size_in_bytes )
{
   if(parent->is_directory == 0) {
        return NULL; // parent is a file and not a directory
    }
    
    //check if the file already exist
    for (int i = 0; i < parent->num_children; ++i) {
    if (strcmp(parent->children[i]->name, name) == 0) {
      return NULL; 
    }
  }

  //allocate and create the iode
  struct  inode* new_inode = malloc(sizeof(struct inode));
  if(new_inode == NULL) {
    return NULL; //Failed to allocate
  }

  
  new_inode->name = strdup(name); // Copy the name
  new_inode->id = next_inode_id();
  new_inode->is_directory = 0;
  new_inode->num_children = 0;
  new_inode->children = NULL;
  new_inode->filesize = size_in_bytes;
  new_inode->num_blocks = (int)ceil((double)size_in_bytes / 4096.0);

  new_inode->blocks = malloc(sizeof(new_inode->blocks)*new_inode->num_blocks);
  if ((int)new_inode->blocks == NULL) {
    free(new_inode->name);
    free(new_inode);
    return NULL;    // Allocation failed
  }

  for (int i = 0; i < new_inode->num_blocks; ++i) {
    new_inode->blocks[i] = allocate_block();     // Call allocation function
    
    if (new_inode->blocks[i] == -1) { // Check for allocation error
      for (int j = 0; j < i; ++j) {
        free_block(new_inode->blocks[j]); // Release previously allocated blocks
      }

      free(new_inode->blocks);
      free(new_inode->name);
      free(new_inode);
      return NULL;
    }
  }

  parent->num_children++;

  parent->children = realloc(parent->children,sizeof(struct inode*) * parent->num_children);  //reallocate for the new inode 
  parent->children[parent->num_children-1] = new_inode;
  
    return new_inode;
}

struct inode* create_dir( struct inode* parent, char* name )
{
    if(parent->is_directory == 0) {
        return NULL; // parent is a file and not a directory
    }


    //check if the file/directory already exist
    for (int i = 0; i < parent->num_children; ++i) {
    if (strcmp(parent->children[i]->name, name) == 0) {
      return NULL; 
    }
  }

  struct inode* new_inode = malloc(sizeof(struct inode)); 
    if(new_inode == NULL) {
    return NULL; //Failed to allocate
  }

  //assign values and allocate dynamically

  new_inode->name = strdup(name); // Copy the name
  new_inode->id = next_inode_id();
  new_inode->is_directory = 1;
  new_inode->num_children = 0;
  new_inode->children = malloc(sizeof(struct inode) * parent->num_children);
    if(new_inode->children == NULL) {
        free(new_inode->name);
        free(new_inode);
        return NULL; // failed to allocate the children array of inodes
    }
    
  new_inode->filesize = NULL;
  new_inode->num_blocks = NULL;


  parent->num_children++;
  parent->children = realloc(parent->children,sizeof(struct inode*) * parent->num_children);  //reallocate for the new inode 
  parent->children[parent->num_children-1] = new_inode;
  
    return new_inode;
}

struct inode* find_inode_by_name( struct inode* parent, char* name )
{
    for(int i =0; i<parent->num_children; i++) {
        if(strcmp(parent->children[i]->name, name) == 1) { // true, inode exist
            return parent->children[i];
        }
    }
    
    return NULL;
    
}

static int verified_delete_in_parent( struct inode* parent, struct inode* node )
{
    /* to be implemented */
    return 0;
}

int is_node_in_parent( struct inode* parent, struct inode* node )
{
    /* to be implemented */
    return 0;
}

int delete_file( struct inode* parent, struct inode* node )
{
    /* to be implemented */
    return 0;
}

int delete_dir( struct inode* parent, struct inode* node )
{
    /* to be implemented */
    return 0;
}

struct inode* load_inodes( char* master_file_table )
{
    /* to be implemented */
    return NULL;
}

/* The function save_inode is a recursive functions that is
 * called by save_inodes to store a single inode on disk,
 * and call itself recursively for every child if the node
 * itself is a directory.
 */
static void save_inode( FILE* file, struct inode* node )
{
    if( !node ) return;

    int len = strlen( node->name ) + 1;

    fwrite( &node->id, 1, sizeof(int), file );
    fwrite( &len, 1, sizeof(int), file );
    fwrite( node->name, 1, len, file );
    fwrite( &node->is_directory, 1, sizeof(char), file );
    if( node->is_directory )
    {
        fwrite( &node->num_children, 1, sizeof(int), file );
        for( int i=0; i<node->num_children; i++ )
        {
            struct inode* child = node->children[i];
            size_t id = child->id;
            fwrite( &id, 1, sizeof(size_t), file );
        }

        for( int i=0; i<node->num_children; i++ )
        {
            struct inode* child = node->children[i];
            save_inode( file, child );
        }
    }
    else
    {
        fwrite( &node->filesize, 1, sizeof(int), file );
        fwrite( &node->num_blocks, 1, sizeof(int), file );
        for( int i=0; i<node->num_blocks; i++ )
        {
            fwrite( &node->blocks[i], 1, sizeof(size_t), file );
        }
    }
}

void save_inodes( char* master_file_table, struct inode* root )
{
    if( root == NULL )
    {
        fprintf( stderr, "root inode is NULL\n" );
        return;
    }

    FILE* file = fopen( master_file_table, "w" );
    if( !file )
    {
        fprintf( stderr, "Failed to open file %s\n", master_file_table );
        return;
    }

    save_inode( file, root );

    fclose( file );
}

/* This static variable is used to change the indentation while debug_fs
 * is walking through the tree of inodes and prints information.
 */
static int indent = 0;

/* Do not change.
 */
void debug_fs( struct inode* node )
{
    if( node == NULL ) return;
    for( int i=0; i<indent; i++ )
        printf("  ");

    if( node->is_directory )
    {
        printf("%s (id %d)\n", node->name, node->id );
        indent++;
        for( int i=0; i<node->num_children; i++ )
        {
            struct inode* child = (struct inode*)node->children[i];
            debug_fs( child );
        }
        indent--;
    }
    else
    {
        printf("%s (id %d size %db blocks ", node->name, node->id, node->filesize );
        for( int i=0; i<node->num_blocks; i++ )
        {
            printf("%d ", (int)node->blocks[i]);
        }
        printf(")\n");
    }
}

/* Do not change.
 */
void fs_shutdown( struct inode* inode )
{
    if( !inode ) return;

    if( inode->is_directory )
    {
        for( int i=0; i<inode->num_children; i++ )
        {
            fs_shutdown( inode->children[i] );
        }
    }

    if( inode->name )     free( inode->name );
    if( inode->children ) free( inode->children );
    if( inode->blocks )   free( inode->blocks );
    free( inode );
}

