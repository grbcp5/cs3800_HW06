//
// Created by Grant Broadwater on 11/10/17.
//

#include "TraceInput.h"

TraceInput::TraceInput( const char *fileName ) : fin() {
  fin.open( fileName );

  if ( !fin.is_open()) {
    throw int();
  }

}

TraceInputItem *TraceInput::getNextInputItem() {

  int num;
  string actionType;
  int block;
  TraceInputItem *result = new TraceInputItem();

  fin >> num;

  if ( fin.eof()) {
    return NULL;
  }

  fin >> actionType >> block;

  result->num = num;

  if ( actionType.find( "a" ) != string::npos ) {

    result->actionType = ALLOCATE;
    result->block.size = block;

  }
  else if ( actionType.find( "d" ) != string::npos ) {

    result->actionType = DEALLOCATE;
    result->block.num = block;

  }

  return result;

}

TraceInput::~TraceInput() {
  fin.close();
}

