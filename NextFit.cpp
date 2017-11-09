//
// Created by Grant Broadwater on 11/7/17.
//

#include "NextFit.h"

NextFit::NextFit() {

  block = new MemoryBlock(
      DEFAULT_POOL_SIZE,
      ( byte * ) malloc( DEFAULT_POOL_SIZE ),
      false
  );

  /* Create circular loop */
  block->before = block;
  block->next = block;

}

void *NextFit::alloc( size_t bytes ) {

  /* Local variables */
  MemoryBlockPtr curBlock;
  MemoryBlockPtr endBlock;

  for ( curBlock = block, endBlock = NULL;           // Initialize
        curBlock != endBlock;                        // Condition
        curBlock = curBlock->next, endBlock = block  // Iterate
      ) {

    /* Skip if current block is occupied */
    if ( curBlock->occupied )
      continue;

    /* See if current block is the exact right size */
    if ( curBlock->size == bytes ) {

      curBlock->occupied = true;
      block = curBlock->next;
      return curBlock->data;

      /* See if current block is larger than what we need */
    }
    else if ( curBlock->size > bytes ) {

      /* Split over sized memory block into two blocks */
      split( curBlock, bytes, true, false );

      block = curBlock->next;

      /* Return this blocks data ptr */
      return ( void * ) ( curBlock->data );

    }

  }

  /* Return null if no data was found */
  return NULL;

}

void NextFit::dealloc( void *thing ) {

  /* Local variables */
  MemoryBlockPtr curBlock;
  MemoryBlockPtr endBlock;

  for ( curBlock = block, endBlock = NULL;           // Initialize
        curBlock != endBlock;                        // Condition
        curBlock = curBlock->next, endBlock = block  // Iterate
      ) {

    if ( curBlock->data == thing ) {
      curBlock->occupied = false;
      join( curBlock );
      return;
    }

  }

}

ostream &operator<<( ostream &out, const NextFit &allocator ) {

  /* Local variables */
  MemoryBlockPtr curBlock;
  MemoryBlockPtr endBlock;
  MemoryBlockPtr block;

  block = allocator.block;

  out << "Memory Blocks: " << endl;

  for ( curBlock = block, endBlock = NULL;            // Initialize
        curBlock != endBlock;                                   // Condition
        curBlock = curBlock->next, endBlock = block             // Iterate
      ) {
    out << "\t" << "Block of size " << ( curBlock->size )
        << " is " << ( curBlock->occupied ? "" : " not " ) << "occupied"
        << endl;
  }

  return out;
}