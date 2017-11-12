//
// Created by Grant Broadwater on 11/6/17.
//

#ifndef HW06_MEMORYBLOCK_H
#define HW06_MEMORYBLOCK_H

#include <cstdlib>

/* Typedefs */
struct MemoryBlock;

typedef MemoryBlock *MemoryBlockPtr;

typedef unsigned char byte;

struct MemoryBlock {
    size_t size;
    byte *data;
    bool occupied;
    MemoryBlock *before;
    MemoryBlock *next;

    MemoryBlock() :
        size( 0 ),
        data( NULL ),
        occupied( false ),
        before( NULL ),
        next( NULL ) {}

    MemoryBlock( const size_t s, byte *pos, bool isOccupied ) :
        size( s ),
        data( pos ),
        occupied( isOccupied ),
        before( NULL ),
        next( NULL ) {}

    MemoryBlock(
        const size_t s,
        byte *pos,
        bool o,
        MemoryBlock *b,
        MemoryBlock *n
    ) :
        size( s ),
        data( pos ),
        occupied( o ),
        before( b ),
        next( n ) {}

    ~MemoryBlock() {

      size = 0;
      occupied = false;

      if ( data != NULL ) {
        delete ( data );
        data = NULL;
      }

      if ( before != NULL ) {
        delete ( before );
        before = NULL;
      }

      if ( next != NULL ) {
        delete ( next );
        next = NULL;
      }

    }

};

void split(
    MemoryBlockPtr overSizedBlock,
    const size_t bytes,
    bool overSizedBlockOccupied,
    bool newBlockOccupied
);

bool join(
    MemoryBlockPtr newlyFreedBlock
);

bool join(
    MemoryBlockPtr newlyFreedBlock,
    MemoryBlockPtr ref
);

#endif //HW06_MEMORYBLOCK_H
