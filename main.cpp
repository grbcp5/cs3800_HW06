


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
  FirstFit *allocator;

  /* Create new allocator */
  allocator = new FirstFit();
  cout << ( *allocator ) << endl;

  /* Allocate 10 bytes */
  cout << "Allocate 10 bytes" << endl;
  v1 = ( char * ) allocator->alloc( 10 );
  cout << ( *allocator ) << endl;

  /* Allocate 14 bytes */
  cout << "Allocate 14 bytes" << endl;
  v2 = ( char * ) allocator->alloc( 14 );
  cout << ( *allocator ) << endl;

  /* Allocate 14 bytes */
  cout << "Allocate 32 bytes" << endl;
  v3 = ( char * ) allocator->alloc( 32 );
  cout << ( *allocator ) << endl;


  cout << "Dealloc 14 bytes" << endl;
  allocator->dealloc( v2 );
  cout << ( *allocator ) << endl;

  cout << "Alloc 10 bytes" << endl;
  v2 = ( char * ) allocator->alloc( 10 );
  cout << ( *allocator ) << endl;

}