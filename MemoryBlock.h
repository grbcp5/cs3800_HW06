//
// Created by Grant Broadwater on 11/6/17.
//

#ifndef HW06_MEMORYBLOCK_H
#define HW06_MEMORYBLOCK_H

#include <stdatomic.h>

struct MemoryBlock;

typedef MemoryBlock *MemoryBlockPtr;

struct MemoryBlock {
    size_t size;
    void *start_position;
    bool occupied;
    MemoryBlock *before;
    MemoryBlock *next;

    MemoryBlock() :
        size( 0 ),
        start_position( NULL ),
        occupied( false ),
        before( NULL ),
        next( NULL ) {}

    MemoryBlock( const size_t s, void *pos, bool isOccupied ) :
        size( s ),
        start_position( pos ),
        occupied( isOccupied ),
        before( NULL ),
        next( NULL ) {}

    MemoryBlock(
        const size_t s,
        void *pos,
        bool o,
        MemoryBlock *b,
        MemoryBlock *n
    ) :
        size( s ),
        start_position( pos ),
        occupied( o ),
        before( b ),
        next( n ) {}

    ~MemoryBlock() {

      size = 0;
      occupied = false;

      if ( start_position != NULL ) {
        delete ( start_position );
        start_position = NULL;
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

#endif //HW06_MEMORYBLOCK_H
