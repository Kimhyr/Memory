#include "Heap.hpp"

// #include <unistd.h>

Void Heap::Destroy() {
	while (this->head) {
		// Do stuff
		this->head = this->head->header.next;
	}
}

template<typename TType>
TType *Heap::Allocate(UInt64 size) {
	if (size > Mlock::MaxSize) {
		return nil;
	}
	// Cant do shit bceause im on fuckign windows what the actual fuck is this bullshit
	if (!this->head) {
		
	}
	return nil;
}
