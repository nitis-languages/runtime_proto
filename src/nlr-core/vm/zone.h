// Licensed to the NiTiS-Dev under one or more agreements.
// The NiTiS-Dev licenses this file to you under the MIT license.

#if !defined(_NLR_ZONE_H) && defined(NLR_EXPORTS)
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
	};

	Node *last_node;
public:
	Zone(UintPtr initial_size);

	void *allocate(UintPtr size);

	void release_all();
};

NLR_END_NAMESPACE
#endif