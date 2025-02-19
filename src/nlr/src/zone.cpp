// Licensed to the NiTiS-Dev under one or more agreements.
// The NiTiS-Dev licenses this file to you under the MIT license.

#include "zone.h"

nlr::Zone::Zone(UIntPtr initial_size) {
	//nlr_assert(initial_size != 0);

	UIntPtr page_size = nlr::get_page_size();

	initial_size = nlr::align_up(initial_size, page_size);

	nlr::allocate(nlr::ptr_cast<Node **, void **>(&this->last_node), initial_size, MemoryFlags::ReadWrite);

	this->last_node->pointer = nlr::move_ptr<UInt8>(this->last_node, +sizeof(nlr::Zone::Node));
	this->last_node->prev = nullptr;
	this->last_node->size = initial_size;
}

void *nlr::Zone::allocate(UIntPtr size) {
	Node *node = this->last_node;

	// Iterate nodes to select a suitable
	while (node) {
		if (node->available() >= size) {
			return node->advance_pointer(size);
		}

		node = node->prev;
	}

	// When there no available space in all nodes: create other node with proper size
	UIntPtr required_size = size + sizeof(nlr::Zone::Node);

	Node *new_node;

	nlr::allocate(nlr::ptr_cast<Node **, void **>(&new_node), required_size, MemoryFlags::ReadWrite);

	new_node->prev = this->last_node;
	new_node->pointer = nlr::move_ptr<UInt8>(new_node, +sizeof(nlr::Zone::Node));
	new_node->size = required_size;
	this->last_node = new_node;

	return new_node->advance_pointer(size);
}

void nlr::Zone::release_all() {
	Node *node = this->last_node;
	Node *prev_node;

	do {
		prev_node = node->prev;

		nlr::release(node, node->size);
		node = prev_node;
	} while (prev_node);
}