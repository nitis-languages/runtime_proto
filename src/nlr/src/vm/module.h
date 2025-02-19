// Licensed to the NiTiS-Dev under one or more agreements.
// The NiTiS-Dev licenses this file to you under the MIT license.

#ifndef _NLR_MODULE_H
#define _NLR_MODULE_H

#include "../string.h"
#include <vector>

namespace nlr::vm {

class Module {
private:
	String *name;
	std::vector<void *> members;
public:
	String *get_name() const noexcept {
		return name;
	}
};

} // namespace nlr::vm
#endif