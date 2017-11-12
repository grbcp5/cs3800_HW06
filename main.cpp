/*******************************************************************************
 *
 * File:
 *   main.cpp
 *
 * Author:
 *   Grant Broadwater
 *
 * Description:
 *   Main class to test different allocators
 *
 ******************************************************************************/

#include <iostream>
#include <vector>

#include "TraceInput.h"
#include "Allocator.h"
#include "FirstFit.h"
#include "NextFit.h"
#include "BestFit.h"

using namespace std;

enum AllocatorType {
    FIRST_FIT,
    NEXT_FIT,
    BEST_FIT
};

void print( AllocatorType type, Allocator *allocator );

void testAllocator( AllocatorType type, Allocator *allocator );

/* Main */
int main() {

  const int NUM_ALLOCATORS = 3;
  AllocatorPtr allocators[NUM_ALLOCATORS] = {
      new FirstFit( "out/firstFit.csv" ),
      new NextFit( "out/nextFit.csv" ),
      new BestFit( "out/bestFit.csv" )
  };
  AllocatorType types[NUM_ALLOCATORS] = {
      FIRST_FIT,
      NEXT_FIT,
      BEST_FIT
  };

  for ( int i = 0; i < NUM_ALLOCATORS; ++i ) {
    testAllocator( types[ i ], allocators[ i ] );
  }


}

void testAllocator( AllocatorType type, Allocator *allocator ) {

  TraceInput input( "in/trace.txt" );
  TraceInputItem *inputItem;
  vector< char * > refs;
  char *ref;

  inputItem = input.getNextInputItem();

  while ( inputItem != NULL ) {

    switch ( inputItem->actionType ) {
      case ALLOCATE:

        cout << inputItem->num << ": Alloc " << inputItem->block.size << endl;
        ref = ( char * ) allocator->alloc(( size_t ) inputItem->block.size );
        strcpy( ref, to_string( inputItem->num ).c_str());
        refs.push_back( ref );
        print( type, allocator );

        break;
      case DEALLOCATE:

        cout << "Dealloc block " << inputItem->block.num << endl;
        allocator->dealloc(
            refs.at(( unsigned long ) inputItem->block.num )
        );
        print( type, allocator );

        break;
    }

    inputItem = input.getNextInputItem();
  }

}

void print( AllocatorType type, Allocator *allocator ) {

  switch ( type ) {
    case FIRST_FIT:

      cout << ( *dynamic_cast<FirstFit *>( allocator )) << endl;

      break;
    case NEXT_FIT:

      cout << ( *dynamic_cast<NextFit *>( allocator )) << endl;

      break;
    case BEST_FIT:

      cout << ( *dynamic_cast<BestFit *>( allocator )) << endl;

      break;
  }

}
