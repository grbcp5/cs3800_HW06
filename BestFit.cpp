//
// Created by Grant Broadwater on 11/9/17.
//

#include "BestFit.h"

BestFit::BestFit( const char *fileName )
    : block( NULL ),
      output( fileName ) {

  block = new MemoryBlock(
      DEFAULT_POOL_SIZE,
      ( byte * ) malloc( DEFAULT_POOL_SIZE ),
      false
  );

}

void *BestFit::alloc( size_t bytes ) {

  /* Local variables */
  MemoryBlockPtr curBlock;
  MemoryBlockPtr bestFit;

  bestFit = NULL;

  output.outputData( getMetaData());

  for ( curBlock = block; curBlock != NULL; curBlock = curBlock->next ) {

    /* Skip if current block is occupied */
    if ( curBlock->occupied )
      continue;

    /* See if current block is the exact right size */
    if ( curBlock->size == bytes ) {

      /* If exeact right size, it is the best fit */
      curBlock->occupied = true;
      return curBlock->data;

      /* See if current block is larger than what we need */
    }
    else if ( curBlock->size > bytes ) {

      /* If this block is smaller than the current best */
      if ( bestFit == NULL || curBlock->size < bestFit->size ) {
        bestFit = curBlock;
      }

    }

  }

  if ( bestFit != NULL ) {

    /* Split over sized memory block into two blocks */
    split( bestFit, bytes, true, false );

    /* Return best blocks data ptr */
    return ( void * ) ( bestFit->data );
  }

  return NULL;
}

void BestFit::dealloc( void *thing ) {

  /* Local variables */
  MemoryBlockPtr curBlock;

  output.outputData( getMetaData());

  for ( curBlock = block; curBlock != NULL; curBlock = curBlock->next ) {

    if ( curBlock->data == thing ) {
      curBlock->occupied = false;
      if ( join( curBlock )) {
        block = curBlock;
      }
      return;
    }

  }

}

ostream &operator<<( ostream &out, const BestFit &allocator ) {

  MemoryBlockPtr block;

  out << "Memory Blocks: " << endl;

  for ( block = allocator.block; block != NULL; block = block->next ) {
    out << "\t" << "Block of size " << ( block->size )
        << " is " << ( block->occupied ? "" : " not " ) << "occupied" << endl;
  }

  return out;

}

AllocatorMetaData BestFit::getMetaData() {

  AllocatorMetaData data;

  /* Local variables */
  MemoryBlockPtr curBlock;

  for ( curBlock = block; curBlock != NULL; curBlock = curBlock->next ) {

    if ( !curBlock->occupied ) {

      data.numFreeBytes += curBlock->size;
      data.numFreeRegions++;

      if ( curBlock->size > data.maxFreeRegionSize ) {
        data.maxFreeRegionSize = ( unsigned int ) curBlock->size;
      }
      else if ( curBlock->size < data.minFreeRegionSize ) {
        data.maxFreeRegionSize = ( unsigned int ) curBlock->size;
      }

    }

  }

  return data;
}

BestFit::~BestFit() {

  delete ( block );

}
