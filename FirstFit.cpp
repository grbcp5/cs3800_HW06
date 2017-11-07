//
// Created by Grant Broadwater on 11/6/17.
//

#include "FirstFit.h"

using namespace std;

FirstFit::FirstFit() : block( NULL ) {
  block = new MemoryBlock(
      DEFAULT_POOL_SIZE,
      ( byte * ) malloc( DEFAULT_POOL_SIZE ),
      false
  );
}

void *FirstFit::alloc( size_t bytes ) {

  /* Local variables */
  MemoryBlockPtr curBlock;

  for ( curBlock = block; curBlock != NULL; curBlock = curBlock->next ) {

    /* Skip if current block is occupied */
    if ( curBlock->occupied )
      continue;

    /* See if current block is the exact right size */
    if ( curBlock->size == bytes ) {

      curBlock->occupied = true;
      return curBlock->data;

      /* See if current block is larger than what we need */
    }
    else if ( curBlock->size > bytes ) {

      /* Split over sized memory block into two blocks */
      split( curBlock, bytes, true, false );

      /* Return this blocks data ptr */
      return ( void * ) ( curBlock->data );

    }

  }

  /* Return null if no data was found */
  return NULL;
}

void FirstFit::dealloc( void *thing ) {

  /* Local variables */
  MemoryBlockPtr curBlock;

  for ( curBlock = block; curBlock != NULL; curBlock = curBlock->next ) {

    if ( curBlock->data == thing ) {
      curBlock->occupied = false;
      join( curBlock );
    }

  }

}

ostream &operator<<( ostream &out, const FirstFit &allocator ) {

  MemoryBlockPtr block;

  out << "Memory Blocks: " << endl;

  for ( block = allocator.block; block != NULL; block = block->next ) {
    out << "\t" << "Block of size " << ( block->size )
        << " is " << ( block->occupied ? "" : " not " ) << "occupied" << endl;
  }

  return out;
}