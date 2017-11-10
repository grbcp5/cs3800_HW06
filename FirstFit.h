//
// Created by Grant Broadwater on 11/6/17.
//

#ifndef HW06_FIRSTFIT_H
#define HW06_FIRSTFIT_H

#include <vector>
#include <cstdlib>
#include <iostream>
#include "Allocator.h"
#include "MemoryBlock.h"
#include "DataRecording.h"

using namespace std;

class FirstFit : public Allocator {
private:
    MemoryBlock *block;
    DataRecording output;

public:

    FirstFit( const char* fileName );

    void *alloc( size_t bytes );

    void dealloc( void *thing );

    AllocatorMetaData getMetaData();

    ~FirstFit();

    friend ostream &operator<<( ostream &out, const FirstFit &allocator );
};

ostream &operator<<( ostream &out, const FirstFit &allocator );


#endif //HW06_FIRSTFIT_H
