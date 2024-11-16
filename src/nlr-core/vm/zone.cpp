// Licensed to the NiTiS-Dev under one or more agreements.
// The NiTiS-Dev licenses this file to you under the MIT license.

#include "zone.h"

nlr::Zone::Zone(UintPtr initial_size) {
	nlr::unused(initial_size);
}

void *nlr::Zone::allocate(UintPtr size) {
	Node *node = last_node;

	nlr::unused(node);

	return nullptr;
}