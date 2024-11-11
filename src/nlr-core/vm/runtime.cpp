// Licensed to the NiTiS-Dev under one or more agreements.
// The NiTiS-Dev licenses this file to you under the MIT license.

#include "runtime.h"
#include "domain.h"

nlr::Runtime::Runtime(void *const configuration, NlrString *const root_domain_name) {
	nlr::unused(configuration, root_domain_name);
	this->domain_counter = 1; // 1 `Cause we create one domain right down here.
	this->root_domain = new nlr::Domain(0, nullptr);
}

nlr::Result nlr::Runtime::dispose() {
	delete this->root_domain;
	return nlr::Result::Success;
}