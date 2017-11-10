/*******************************************************************************
 *
 * File:
 *   simple.cpp
 *
 * Author:
 *   Grant Broadwater
 *
 * Description:
 *   Implements Simple allocator functions
 *
 ******************************************************************************/

#include "simple.h"

using namespace std;

void *Simple::alloc( size_t bytes ) {

  if ( first_free + bytes <= pool_size ) {
    cout << "Allocating " << bytes << " bytes" << endl;
    size_t allocated = first_free;
    first_free += bytes;
    return &pool[ allocated ];
  }
  else {
    cout << "Could not allocate " << bytes << " bytes" << endl;
    throw bad_alloc();
  }

}

void Simple::dealloc( void *thing ) {
  cout << "Deallocating address " << thing << endl;
  // If we did deallocation, the code would go here
}

AllocatorMetaData Simple::getMetaData() {

  AllocatorMetaData data;

  return data;
}

int simple_main() {
  // In here, need to run through a trace of allocations and deallocations,
  // then record allocator efficiency stats.
  vector< void * > allocations;
  Allocator *allocator;

  allocator = new Simple();

  for ( unsigned int i = 0; i < 1000; i++ ) {
    if ( allocations.size() == 0 || rand() % 2 ) // Allocate something
    {
      try {
        size_t size = ( unsigned int ) ( rand() % 127 + 1 );
        void *p = allocator->alloc( size );
        allocations.push_back( p );
      }
      catch ( const bad_alloc &b ) {}
    }
    else // Free something
    {
      size_t to_free =
          rand() % allocations.size(); // Randomly select something to free
      allocator->dealloc( allocations[ to_free ] ); // Free it
      allocations.erase( allocations.begin() +
                         to_free ); // Remove it from our list of allocated blocks
    }
  }

  // Write statistics out to a CSV file
  return 0;
}
