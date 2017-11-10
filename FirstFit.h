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

using namespace std;

class FirstFit : public Allocator {
private:
    MemoryBlock *block;

public:

    FirstFit();

    void *alloc( size_t bytes );

    void dealloc( void *thing );

    AllocatorMetaData getMetaData();

    ~FirstFit();

    friend ostream &operator<<( ostream &out, const FirstFit &allocator );
};

ostream &operator<<( ostream &out, const FirstFit &allocator );


#endif //HW06_FIRSTFIT_H
