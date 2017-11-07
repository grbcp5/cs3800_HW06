//
// Created by Grant Broadwater on 11/6/17.
//

#ifndef HW06_MEMORYBLOCK_H
#define HW06_MEMORYBLOCK_H

#include <stdatomic.h>

struct MemoryBlock {
    size_t size;
    void *start_position;
    bool occupied;

    MemoryBlock() :
        size( 0 ),
        start_position( NULL ),
        occupied( false ) {}

    MemoryBlock( const size_t s, void *pos, bool isOccupied ) :
        size( s ),
        start_position( pos ),
        occupied( isOccupied ) {}

    ~MemoryBlock() {

      size = 0;
      occupied = false;
      if ( start_position != NULL ) {
        delete ( start_position );
        start_position = NULL;
      }

    }

};

#endif //HW06_MEMORYBLOCK_H
