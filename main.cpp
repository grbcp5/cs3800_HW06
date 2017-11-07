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

#include "FirstFit.h"

using namespace std;

/* Main */

int main() {

  srand( 10021996 );

  char *v1;
  char *v2;
  char *v3;

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
  v3 = ( char * ) allocator->alloc( 32 );
  cout << ( *dynamic_cast<FirstFit *>( allocator )) << endl;

  /* Deallocate second block */
  cout << "Dealloc second block" << endl;
  allocator->dealloc( v2 );
  cout << ( *dynamic_cast<FirstFit *>( allocator )) << endl;

  /* Allocate 10 bytes */
  cout << "Alloc 10 bytes" << endl;
  v2 = ( char * ) allocator->alloc( 10 );
  cout << ( *dynamic_cast<FirstFit *>( allocator )) << endl;

  delete ( allocator );
}