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
}

nlr::Result nlr::Runtime::dispose() {
	this->zone.release_all();

	return nlr::Result::Success;
}