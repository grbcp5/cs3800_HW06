//
// Created by Grant Broadwater on 11/7/17.
//

#include "NextFit.h"

NextFit::NextFit( const char *fileName )
    : block( NULL ),
      output( fileName ) {

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

  output.outputData( getMetaData());

  curBlock = block;
  endBlock = block;

  do {

    /* Skip if current block is occupied */
    if ( !curBlock->occupied ) {

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

    curBlock = curBlock->next;

  } while ( curBlock != endBlock );

  /* Return null if no data was found */
  return NULL;

}

void NextFit::dealloc( void *thing ) {

  /* Local variables */
  MemoryBlockPtr curBlock;
  MemoryBlockPtr endBlock;

  output.outputData( getMetaData());

  curBlock = block;
  endBlock = block;

  do {

    if ( curBlock->data == thing ) {
      curBlock->occupied = false;
      if ( join( curBlock, block )) {
        block = curBlock;
      }
      return;
    }

    curBlock = curBlock->next;

  } while ( curBlock != endBlock );

}

ostream &operator<<( ostream &out, const NextFit &allocator ) {

  /* Local variables */
  MemoryBlockPtr curBlock;
  MemoryBlockPtr endBlock;

  curBlock = allocator.block;
  endBlock = allocator.block;

  out << "Memory Blocks: " << endl;

  do {
    out << "\t" << "Block of size " << ( curBlock->size )
        << " is " << ( curBlock->occupied ? "" : " not " ) << "occupied"
        << endl;

    curBlock = curBlock->next;

  } while ( curBlock != endBlock );

  return out;
}

AllocatorMetaData NextFit::getMetaData() {

  AllocatorMetaData data;

  /* Local variables */
  MemoryBlockPtr curBlock;
  MemoryBlockPtr endBlock;

  curBlock = block;
  endBlock = block;

  do {

    if ( !curBlock->occupied ) {

      data.numFreeBytes += curBlock->size;
      data.numFreeRegions++;

      if ( curBlock->size > data.maxFreeRegionSize ) {
        data.maxFreeRegionSize = ( unsigned int ) curBlock->size;
      }

      if ( curBlock->size < data.minFreeRegionSize ) {
        data.minFreeRegionSize = ( unsigned int ) curBlock->size;
      }

    }

    curBlock = curBlock->next;

  } while ( curBlock != endBlock );

  return data;
}

NextFit::~NextFit() {
  delete ( block );
}

string NextFit::toString() {

  /* Local variables */
  MemoryBlockPtr curBlock;
  MemoryBlockPtr endBlock;
  stringstream out;

  out << "Memory Blocks: " << endl;

  for ( curBlock = block, endBlock = NULL;            // Initialize
        curBlock != endBlock;                                   // Condition
        curBlock = curBlock->next, endBlock = block             // Iterate
      ) {
    out << "\t" << "Block of size " << ( curBlock->size )
        << " is " << ( curBlock->occupied ? "" : " not " ) << "occupied"
        << endl;
  }

  return out.str();

}
