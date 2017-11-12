
#include "FirstFit.h"
#include "NextFit.h"
#include "BestFit.h"
#include "TraceInput.h"

using namespace std;


void testInput() {

  TraceInput input( "trace.txt" );
  TraceInputItem *inputItem;

  inputItem = input.getNextInputItem();

  while ( inputItem != NULL ) {

    switch ( inputItem->actionType ) {
      case ALLOCATE:

        cout << inputItem->num << ": Alloc " << inputItem->block.size << endl;

        break;
      case DEALLOCATE:

        cout << "Dealloc block " << inputItem->block.num << endl;

        break;
    }

    inputItem = input.getNextInputItem();
  }

}

void testBestFit() {

  char *v1 = NULL;
  char *v2 = NULL;

  Allocator *allocator;

  cout << "\nTest Best Fit\n" << endl;

  cout << "New allocator" << endl;
  allocator = new BestFit( "" );
  cout << ( *dynamic_cast<BestFit *>( allocator )) << endl;

  /* Allocate 16 bytes */
  cout << "Allocate 16 bytes" << endl;
  v1 = ( char * ) allocator->alloc( 16 );
  cout << ( *dynamic_cast<BestFit *>( allocator )) << endl;

  /* Allocate 8 bytes */
  cout << "Allocate 8 bytes" << endl;
  ( char * ) allocator->alloc( 8 );
  cout << ( *dynamic_cast<BestFit *>( allocator )) << endl;

  /* Allocate 8 bytes */
  cout << "Allocate 8 bytes" << endl;
  v2 = ( char * ) allocator->alloc( 8 );
  cout << ( *dynamic_cast<BestFit *>( allocator )) << endl;

  /* Allocate 8 bytes */
  cout << "Allocate 8 bytes" << endl;
  ( char * ) allocator->alloc( 8 );
  cout << ( *dynamic_cast<BestFit *>( allocator )) << endl;

  /* Deallocate second block */
  cout << "Dealloc first block" << endl;
  allocator->dealloc( v1 );
  cout << ( *dynamic_cast<BestFit *>( allocator )) << endl;

  /* Deallocate third block */
  cout << "Dealloc third block" << endl;
  allocator->dealloc( v2 );
  cout << ( *dynamic_cast<BestFit *>( allocator )) << endl;

  /* Allocate 8 bytes */
  cout << "Allocate 8 bytes" << endl;
  ( char * ) allocator->alloc( 8 );
  cout << ( *dynamic_cast<BestFit *>( allocator )) << endl;

}

void testNextFit() {

  char *v1 = NULL;

  /* Local variables */
  Allocator *allocator;

  cout << "Test Next Fit" << endl << endl;

  /* Create new allocator */
  cout << "New allocator" << endl;
  allocator = new NextFit( "" );
  cout << ( *dynamic_cast<NextFit *>( allocator )) << endl;

  /* Allocate 8 bytes */
  cout << "Allocate 8 bytes" << endl;
  ( char * ) allocator->alloc( 8 );
  cout << ( *dynamic_cast<NextFit *>( allocator )) << endl;

  /* Allocate 8 bytes */
  cout << "Allocate 8 bytes" << endl;
  v1 = ( char * ) allocator->alloc( 8 );
  cout << ( *dynamic_cast<NextFit *>( allocator )) << endl;

  /* Allocate 8 bytes */
  cout << "Allocate 8 bytes" << endl;
  ( char * ) allocator->alloc( 8 );
  cout << ( *dynamic_cast<NextFit *>( allocator )) << endl;

  /* Deallocate second block */
  cout << "Dealloc second block" << endl;
  allocator->dealloc( v1 );
  cout << ( *dynamic_cast<NextFit *>( allocator )) << endl;

  /* Allocate 8 bytes */
  cout << "Allocate 8 bytes" << endl;
  ( char * ) allocator->alloc( 8 );
  cout << ( *dynamic_cast<NextFit *>( allocator )) << endl;

}

void testFirstFit() {

  char *v1 = NULL;
  char *v2 = NULL;
  char *v3 = NULL;

  /* Local variables */
  Allocator *allocator;

  /* Create new allocator */
  allocator = new FirstFit( "firstFitData.csv" );
  cout << ( *dynamic_cast<FirstFit *>( allocator )) << endl;

  /* Allocate 8 bytes */
  cout << "Allocate 8 bytes" << endl;
  v1 = ( char * ) allocator->alloc( 8 );
  cout << ( *dynamic_cast<FirstFit *>( allocator )) << endl;

  /* Use allocated memory */
  strcpy( v1, "Hello" );
  cout << "V1: " << v1 << endl << endl;

  /* Allocate 8 bytes */
  cout << "Allocate 8 bytes" << endl;
  v2 = ( char * ) allocator->alloc( 8 );
  cout << ( *dynamic_cast<FirstFit *>( allocator )) << endl;

  /* Allocate 8 bytes */
  cout << "Allocate 8 bytes" << endl;
  v3 = ( char * ) allocator->alloc( 8 );
  cout << ( *dynamic_cast<FirstFit *>( allocator )) << endl;

  /* Deallocate second block */
  cout << "Dealloc second block" << endl;
  allocator->dealloc( v2 );
  v2 = NULL;
  cout << ( *dynamic_cast<FirstFit *>( allocator )) << endl;

  /* Deallocate first block */
  cout << "Dealloc first block" << endl;
  allocator->dealloc( v1 );
  v1 = NULL;
  cout << ( *dynamic_cast<FirstFit *>( allocator )) << endl;

  /* Deallocate third block */
  cout << "Dealloc third block" << endl;
  allocator->dealloc( v3 );
  v3 = NULL;
  cout << ( *dynamic_cast<FirstFit *>( allocator )) << endl;

}