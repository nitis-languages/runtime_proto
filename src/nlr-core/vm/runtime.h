// Licensed to the NiTiS-Dev under one or more agreements.
// The NiTiS-Dev licenses this file to you under the MIT license.

#ifndef _NLR_RUNTIME_H
#define _NLR_RUNTIME_H

#include "../nlr-core-api.h"
#include "string.h"

NLR_BEGIN_NAMESPACE

class Domain;

class Runtime {
private:
	Domain *root_domain;
	Uint32 domain_counter;
public:
	NLR_API Runtime(void *const configuration, NlrString *const root_domain_name);
	
	NLR_API Result dispose();
};

NLR_END_NAMESPACE
#endif