/*******************************************************************************
 *
 * File:
 *   NextFit.h
 *
 * Author:
 *   Grant Broadwater
 *
 * Description:
 *   NextFit allocator class declaration
 *
 ******************************************************************************/

#ifndef HW06_NEXTFIT_H
#define HW06_NEXTFIT_H

#include <iostream>

#include "Allocator.h"
#include "MemoryBlock.h"

using namespace std;

class NextFit : public Allocator {
private:
    MemoryBlock *block;

public:

    NextFit();

    void *alloc( size_t bytes );

    void dealloc( void *thing );

    AllocatorMetaData getMetaData();

    virtual ~NextFit();

    friend ostream &operator<<( ostream &out, const NextFit &allocator );

};

ostream &operator<<( ostream &out, const NextFit &allocator );


#endif //HW06_NEXTFIT_H
