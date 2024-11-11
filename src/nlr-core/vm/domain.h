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
	NLR_TYPE_REMOVE_CONSTRUCTORS(Domain)

	friend class Runtime;

	/// @brief Unique identifier.
	Uint32 identifier;
	/// @brief List of all dependent domains.
	/// @remark All domains in this list has this domain as parental.
	std::vector<Domain> childs;
	/// @brief Parent domain.
	/// @remarks May be null.
	Domain *parent;
	/// @brief Domain name. Can be identical with other domain name.
	/// @remarks May be null.
	NlrString *name;

	Domain(Uint32 identifier, Domain *const parent) noexcept;
};

NLR_END_NAMESPACE
#endif