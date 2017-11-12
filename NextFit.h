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
#include <sstream>

#include "Allocator.h"
#include "MemoryBlock.h"
#include "DataRecording.h"

using namespace std;

class NextFit : public Allocator {
private:
    MemoryBlock *block;
    DataRecording output;


public:

    NextFit( const char *fileName );

    void *alloc( size_t bytes );

    void dealloc( void *thing );

    AllocatorMetaData getMetaData();

    virtual ~NextFit();

    string toString();

    friend ostream &operator<<( ostream &out, const NextFit &allocator );

};

ostream &operator<<( ostream &out, const NextFit &allocator );


#endif //HW06_NEXTFIT_H
