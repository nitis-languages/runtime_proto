// Licensed to the NiTiS-Dev under one or more agreements.
// The NiTiS-Dev licenses this file to you under the MIT license.

#include "runtime.h"
#include "domain.h"
#include "zone.h"

nlr::Runtime::Runtime() {
	this->zone = Zone(1);
	if (!this->zone.valid()) {
		// log
		return;
	}

	for (Uint64 i = 0; i < 1024; i++) {
		zone.allocate(sizeof(Uint32));
	}
}

nlr::Result nlr::Runtime::dispose() {
	this->zone.release_all();

	return nlr::Result::Success;
}