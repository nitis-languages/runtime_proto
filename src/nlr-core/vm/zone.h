// Licensed to the NiTiS-Dev under one or more agreements.
// The NiTiS-Dev licenses this file to you under the MIT license.

#ifndef _NLR_ZONE_H
#define _NLR_ZONE_H

#include "../support.h"
#include "virtual-memory.h"

NLR_BEGIN_NAMESPACE

/// @brief Zone is incremental allocator. Once place in memory allocated, it can't be freed, unless free whole zone.
class Zone {
private:
	struct Node {
		Node *prev;
		UintPtr size; // Size of allocated memory (included node)
		Uint8 *pointer;

		constexpr Uint8 *data() {
			return move_ptr<Uint8>(this, +sizeof(Node));
		}

		constexpr UintPtr available() {
			return size - (pointer - ptr_cast<Node *, Uint8 *>(this));
		}

		NLR_INLINE Uint8 *advance_pointer(UintPtr offset) {
			Uint8 *data_ptr = this->pointer;
			this-> pointer = move_ptr<Uint8>(this->pointer, offset);

			return data_ptr;
		}
	};

	Node *last_node;
public:
	Zone() = default;
	Zone(UintPtr initial_size);

	void *allocate(UintPtr size);

	NLR_INLINE bool valid() {
		return this->last_node != nullptr;
	}

	void release_all();
};

NLR_END_NAMESPACE
#endif