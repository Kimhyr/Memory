#pragma once
#ifndef HEAP_HPP
#define HEAP_HPP

#include "Core.hpp"

union Mlock {
  static const UInt64 MaxSize = 0x7FFFFFFFFFFFFFFF;
  struct Header {
    UInt64 size;
    Mlock *next;
  } header;
  UInt8 stub[16];

  static constexpr Mlock Create(UInt64 size) {
	  return {
	  	.header = {
	  		.size = size,
	  		.next = nil,
	  	},
	  };
  }
    
  constexpr Bool IsFree() {
    return this->header.size & 1;
  }
};

struct Heap {
  Mlock *head;
  Mlock *tail;
  
  static constexpr Heap Create() {
	  return {
	  	.head = nil,
	  	.tail = nil,
	  };
  }
  Void Destroy();
  template<typename TType>
  TType *Allocate(UInt64 size);
};

#endif  // HEAP_HPP
