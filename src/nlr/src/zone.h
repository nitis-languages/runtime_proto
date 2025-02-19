// Licensed to the NiTiS-Dev under one or more agreements.
// The NiTiS-Dev licenses this file to you under the MIT license.

#ifndef _NLR_ZONE_H
#define _NLR_ZONE_H

#include "utils.h"
#include "virtual-memory.h"

namespace nlr {

/// @brief Zone is incremental allocator. Once place in memory allocated, it can't be freed, unless free whole zone.
class Zone {
private:
	struct Node {
		Node *prev;
		UIntPtr size; // Size of allocated memory (included node)
		UInt8 *pointer;

		constexpr UInt8 *data() {
			return move_ptr<UInt8>(this, +sizeof(Node));
		}

		constexpr UIntPtr available() {
			return size - (pointer - ptr_cast<Node *, UInt8 *>(this));
		}

		NLR_INLINE UInt8 *advance_pointer(UIntPtr offset) {
			UInt8 *data_ptr = this->pointer;
			this-> pointer = move_ptr<UInt8>(this->pointer, offset);

			return data_ptr;
		}
	};

	Node *last_node;
public:
	Zone() = default;
	Zone(UIntPtr initial_size);

	void *allocate(UIntPtr size);

	NLR_INLINE bool valid() {
		return this->last_node != nullptr;
	}

	void release_all();
};

} // namespace nlr
#endif