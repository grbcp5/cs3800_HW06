//
// Created by Grant Broadwater on 11/9/17.
//

#ifndef HW06_BESTFIT_H
#define HW06_BESTFIT_H

#include <cstdlib>
#include <iostream>
#include "Allocator.h"
#include "MemoryBlock.h"

using namespace std;

class BestFit : public Allocator {
private:
    MemoryBlockPtr block;

public:
    BestFit();

    virtual void *alloc( size_t bytes ) override;

    virtual void dealloc( void *thing ) override;

    friend ostream &operator<<( ostream &out, const BestFit &allocator );
};

ostream &operator<<( ostream &out, const BestFit &allocator );

#endif //HW06_BESTFIT_H
