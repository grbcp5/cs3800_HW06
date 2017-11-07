/*******************************************************************************
 *
 * File:
 *   simple.h
 *
 * Author:
 *   Grant Broadwater
 *
 * Description:
 *   Declares simple allocator class and main function to test class
 *
 ******************************************************************************/

#ifndef HW06_SIMPLE_H
#define HW06_SIMPLE_H

#include <iostream>
#include <vector>
#include "Allocator.h"

using namespace std;

/* A simple allocator that just allocates memory from a pool
 * and does no deallocation whatsoever.
 *
 * Your allocator classes should do both allocation and deallocation.
 * Furthermore, they need to have some means of gathering statistics
 * and recording them to a file.
 */
class Simple : public Allocator {
private:
    static const size_t pool_size = 1024;
    char pool[pool_size];
    size_t first_free;

public:
    Simple() : first_free( 0 ) {}

    void *alloc( size_t bytes );

    void dealloc( void *thing );

};

int simple_main();

#endif //HW06_SIMPLE_H
