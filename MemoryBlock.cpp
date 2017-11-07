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

}

void join(
    MemoryBlockPtr block
) {

  MemoryBlockPtr consumedBlock;

  if ( block->next != NULL && !block->next->occupied ) {

    consumedBlock = block->next;

    /* Consume following memory block into this memory block */
    block->size += consumedBlock->size;
    block->next = consumedBlock->next;

  }

  if ( block->before != NULL && !block->before->occupied ) {

    consumedBlock = block->before;

    /* Consume proceeding memory block into this memory block */
    block->size += consumedBlock->size;
    block->data = consumedBlock->data;
    block->before = consumedBlock->before;

    if ( consumedBlock->before != NULL ) {
      consumedBlock->before->next = block;
    }

  }

}