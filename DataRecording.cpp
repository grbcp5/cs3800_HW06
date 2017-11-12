//
// Created by Grant Broadwater on 11/9/17.
//

#include "DataRecording.h"

DataRecording::DataRecording( const char *outFileName )
    : out() {
  out.open( outFileName );

  if ( !out.is_open())
    throw int( 0 );

  out << "Free Bytes,"
      << " Free Regions,"
      << " Min Free Region Size,"
      << " Max Free Region Size\n";
}

void DataRecording::outputData( const AllocatorMetaData data ) {
  out << data << endl;
}

DataRecording::~DataRecording() {
  out.close();
}

ostream &operator<<( ostream &o, const AllocatorMetaData &data ) {
  o << data.numFreeBytes << ", "
    << data.numFreeRegions << ", "
    << data.minFreeRegionSize << ", "
    << data.maxFreeRegionSize;

  return o;
}

void output( const AllocatorMetaData data ) {
  static DataRecording dataRecording( "testFile.csv" );

  dataRecording.outputData( data );
}
