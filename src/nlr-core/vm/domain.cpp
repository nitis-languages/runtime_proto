// Licensed to the NiTiS-Dev under one or more agreements.
// The NiTiS-Dev licenses this file to you under the MIT license.

#include "runtime.h"
#include "domain.h"

nlr::Domain::Domain(Uint32 identifier, Domain *const parent) noexcept {
	this->identifier = identifier;
	this->childs = std::vector<Domain>();
	this->parent = parent;
}