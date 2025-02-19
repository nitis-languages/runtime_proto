// Licensed to the NiTiS-Dev under one or more agreements.
// The NiTiS-Dev licenses this file to you under the MIT license.

#ifndef _NLR_TYPE_H
#define _NLR_TYPE_H

#include "../string.h"
#include <vector>

namespace nlr::vm {

class Module;

struct Version {
public:
	UInt16 major;
	UInt16 minor;
	UInt16 patch;
	UInt16 build;

	Version(UInt16 major)
		: major(major)
		, minor(0)
		, patch(0)
		, build(0)
	{}

	Version(UInt16 major, UInt16 minor)
		: major(major)
		, minor(minor)
		, patch(0)
		, build(0)
	{}

	Version(UInt16 major, UInt16 minor, UInt16 patch)
		: major(major)
		, minor(minor)
		, patch(patch)
		, build(0)
	{}

	Version(UInt16 major, UInt16 minor, UInt16 patch, UInt16 build)
		: major(major)
		, minor(minor)
		, patch(patch)
		, build(build)
	{}
};

class Library {
private:
	String *name;
	Version version;
	std::span<Module *> modules;
	// IdResolver *resolver;
public:
	String *get_name() const noexcept {
		return name;
	}

	Version get_version() const noexcept {
		return version;
	}
};

} // namespace nlr::vm
#endif