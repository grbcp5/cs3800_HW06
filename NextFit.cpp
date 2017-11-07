//
// Created by Grant Broadwater on 11/7/17.
//

#include "NextFit.h"

NextFit::NextFit() {

}

void *NextFit::alloc( size_t bytes ) {


  return NULL;
}

void NextFit::dealloc( void *thing ) {

}

friend ostream &operator<<( ostream &out, const NextFit &allocator ) {

  return out;
}