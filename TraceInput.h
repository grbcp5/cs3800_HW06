//
// Created by Grant Broadwater on 11/10/17.
//

#ifndef HW06_TRACEINPUT_H
#define HW06_TRACEINPUT_H

#include <fstream>

using namespace std;

enum ActionType {
    ALLOCATE,
    DEALLOCATE
};

union Block {
    int size;
    int num;
};

struct TraceInputItem {
    int num;
    ActionType actionType;
    Block block;
};

class TraceInput {
private:
    ifstream fin;

public:
    TraceInput( const char *fileName );

    TraceInputItem *getNextInputItem();

    ~TraceInput();
};


#endif //HW06_TRACEINPUT_H
