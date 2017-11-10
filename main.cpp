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
#include <cstring>

#include "FirstFit.h"
#include "NextFit.h"
#include "BestFit.h"

using namespace std;

/* Main */

void testFirstFit();

void testNextFit();

void testBestFit();

int main() {

  srand( 10021996 );

  testFirstFit();

}

void testBestFit() {

  char *v1 = NULL;
  char *v2 = NULL;

  Allocator *allocator;

  cout << "\nTest Best Fit\n" << endl;

  cout << "New allocator" << endl;
  allocator = new BestFit();
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
  allocator = new NextFit();
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

  /* Local variables */
  Allocator *allocator;

  /* Create new allocator */
  allocator = new FirstFit();
  cout << ( *dynamic_cast<FirstFit *>( allocator )) << endl;

  /* Allocate 10 bytes */
  cout << "Allocate 10 bytes" << endl;
  v1 = ( char * ) allocator->alloc( 10 );
  cout << ( *dynamic_cast<FirstFit *>( allocator )) << endl;

  /* Use allocated memory */
  strcpy( v1, "Hello" );
  cout << "V1: " << v1 << endl << endl;

  /* Allocate 14 bytes */
  cout << "Allocate 14 bytes" << endl;
  v2 = ( char * ) allocator->alloc( 14 );
  cout << ( *dynamic_cast<FirstFit *>( allocator )) << endl;

  /* Allocate 14 bytes */
  cout << "Allocate 32 bytes" << endl;
  ( char * ) allocator->alloc( 32 );
  cout << ( *dynamic_cast<FirstFit *>( allocator )) << endl;

  /* Deallocate second block */
  cout << "Dealloc second block" << endl;
  allocator->dealloc( v2 );
  v2 = NULL;
  cout << ( *dynamic_cast<FirstFit *>( allocator )) << endl;

  /* Allocate 970 bytes */
  cout << "Alloc 970 bytes" << endl;
  v2 = ( char * ) allocator->alloc( 970 );
  cout << "Return value: " << ( v2 == NULL ? "NULL" : "" ) << endl;
  cout << ( *dynamic_cast<FirstFit *>( allocator )) << endl;

}
