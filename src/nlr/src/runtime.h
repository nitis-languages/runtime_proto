// Licensed to the NiTiS-Dev under one or more agreements.
// The NiTiS-Dev licenses this file to you under the MIT license.

#ifndef _NLR_RUNTIME_H
#define _NLR_RUNTIME_H

#include <vector>
#include "vm/library.h"

namespace nlr {

class Runtime {
private:
	std::vector<vm::Library *> libraries;

public:
	Runtime() noexcept;

	String *get_runtime_identifier() const noexcept;

	void *load_library(char *path) const noexcept;
};

[[noreturn]]
void report_critical_error(SInt32 error_code, const char *message) noexcept;

} // namespace nlr
#endif