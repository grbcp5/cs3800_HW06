//
// Created by Grant Broadwater on 11/6/17.
//

#ifndef HW06_FIRSTFIT_H
#define HW06_FIRSTFIT_H

#include <vector>
#include <cstdlib>
#include "Allocator.h"
#include "MemoryBlock.h"

using namespace std;

class FirstFit : public Allocator {
private:
    vector< MemoryBlock > blocks;

public:

    FirstFit();

    void *alloc( size_t bytes );

    void dealloc( void *thing );

};


#endif //HW06_FIRSTFIT_H
