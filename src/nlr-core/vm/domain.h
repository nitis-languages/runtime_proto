// Licensed to the NiTiS-Dev under one or more agreements.
// The NiTiS-Dev licenses this file to you under the MIT license.

#ifndef _NLR_DOMAIN_H
#define _NLR_DOMAIN_H

#include "../nlr-core-api.h"
#include "string.h"
#include <vector>

NLR_BEGIN_NAMESPACE

/// @brief Domain is a 
class Domain {
private:

public:
	NLR_API Result create_sub_domain(Domain *domain);

	NLR_API Result dispose();
};

NLR_END_NAMESPACE
#endif