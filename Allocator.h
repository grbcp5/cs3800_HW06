/*******************************************************************************
 *
 * File:
 *   Allocator.h
 *
 * Author:
 *   Grant Broadwater
 *
 * Description:
 *   Abstract allocator class
 *
 ******************************************************************************/

#ifndef HW06_ALLOCATOR_H
#define HW06_ALLOCATOR_H

#include <stdexcept>
#include "DataRecording.h"

#define DEFAULT_POOL_SIZE 1024

class Allocator {
public:

    virtual void *alloc( size_t bytes ) = 0;

    virtual void dealloc( void *thing ) = 0;

    virtual AllocatorMetaData getMetaData() = 0;

};



/* BEGIN DIVERSION */
/* The following three functions are needed for the
 * 'placement new' syntax and associated deletes.
 * You do not have to implement them for this assignment,
 * but if you wanted to use your allocator in practice,
 * you would want them.
 */
inline void *operator new( size_t nbytes, Allocator &pool ) {
  return pool.alloc( nbytes );
}

inline void operator delete( void *p, Allocator &pool ) {
  pool.dealloc( p );
}

template< class T >
inline void destruct( T *p, Allocator &pool ) {
  p->~T();
  operator delete( p, pool );
}

//void placement_new_demonstration()
//{
//  Simple s;
//  int *x;
//
//  // Just allocate as much memory as we can
//  try
//  {
//    for ( int i = 1;; i++ )
//    {
//      // allocation happens in our custom allocator instead of on the heap
//      x = new( s ) int( i );
//      cout << *x << endl;
//
//      // Never happens, just to get rid of "endless loop" warning
//      if( i < 0 ) break;
//
//    }
//  }
//  catch ( const bad_alloc &b )
//  {
//    cout << "Yup, no good " << b.what() << endl;
//  }
//
//  // Instead of calling delete, call destruct
//  destruct( x, s );
//
//  // Technically this should leak a bunch of memory,
//  // but because our allocator object is deallocated when
//  // this function returns, we have no memory leaks!
//}

/* END DIVERSION */


#endif //HW06_ALLOCATOR_H
