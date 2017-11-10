//
// Created by Grant Broadwater on 11/7/17.
//

#include "MemoryBlock.h"

void split(
    MemoryBlockPtr overSizedBlock,
    const size_t bytes,
    bool overSizedBlockOccupied,
    bool newBlockOccupied
) {

  MemoryBlockPtr newBlock;

  newBlock = new MemoryBlock(
      overSizedBlock->size - bytes,  // Size
      overSizedBlock->data + bytes,  // data (location pointer)
      newBlockOccupied,              // isOccupied
      overSizedBlock,                // before ptr
      overSizedBlock->next           // after ptr
  );
  overSizedBlock->size = bytes;
  overSizedBlock->occupied = overSizedBlockOccupied;
  overSizedBlock->next = newBlock;

  if ( newBlock->next != NULL ) {
    newBlock->next->before = newBlock;
  }

}

bool join(
    MemoryBlockPtr block
) {

  MemoryBlockPtr consumedBlock;

  if ( block->next != NULL
       && !block->next->occupied
       && block->next != block
      ) {

    consumedBlock = block->next;

    /* Consume following memory block into this memory block */
    block->size += consumedBlock->size;
    block->next = consumedBlock->next;

    if ( consumedBlock->next != NULL ) {
      consumedBlock->next->before = block;
    }

  }

  if ( block->before != NULL
       && !block->before->occupied
       && block->before != block
      ) {

    consumedBlock = block->before;

    /* Consume proceeding memory block into this memory block */
    block->size += consumedBlock->size;
    block->data = consumedBlock->data;
    block->before = consumedBlock->before;

    if ( consumedBlock->before != NULL ) {
      consumedBlock->before->next = block;
    }
    else {
      return true;
    }

  }

  return false;

}
