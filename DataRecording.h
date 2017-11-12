//
// Created by Grant Broadwater on 11/9/17.
//

#ifndef HW06_DATARECORDING_H
#define HW06_DATARECORDING_H

#include <fstream>

using namespace std;

struct AllocatorMetaData {
    unsigned int numFreeBytes;
    unsigned int numFreeRegions;
    unsigned int maxFreeRegionSize;
    unsigned int minFreeRegionSize;

    AllocatorMetaData() :
        numFreeBytes( 0 ),
        numFreeRegions( 0 ),
        maxFreeRegionSize( 0 ),
        minFreeRegionSize( 1025 ) {}

};

class DataRecording {
private:
    ofstream out;

public:
    DataRecording( const char *outFileName );

    void outputData( const AllocatorMetaData data );

    ~DataRecording();
};

ostream &operator<<( ostream &out, const AllocatorMetaData &data );

//void output( const AllocatorMetaData data );

#endif //HW06_DATARECORDING_H
