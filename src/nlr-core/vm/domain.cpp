// Licensed to the NiTiS-Dev under one or more agreements.
// The NiTiS-Dev licenses this file to you under the MIT license.

#include "runtime.h"
#include "domain.h"

nlr::Result nlr::Domain::create_sub_domain(Domain *domain) {
	nlr::unused(domain);
	return nlr::Result::Success;
}

nlr::Result nlr::Domain::dispose() {
	return nlr::Result::Success;
}