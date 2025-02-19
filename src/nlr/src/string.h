// Licensed to the NiTiS-Dev under one or more agreements.
// The NiTiS-Dev licenses this file to you under the MIT license.

#ifndef _NLR_STRING_H
#define _NLR_STRING_H

#include "utils.h"
#include <string>

namespace nlr {

/// @remark For public API valid only as reference
class String {
private:
	// shadow field:  UIntPtr size: offsetof(-sizeof(UIntPtr));
	// shadow fields: char8_t content[size]: offsetof(0);
public:
	constexpr UIntPtr size() const noexcept {
		return *(nlr::ptr_cast<const String *, const UIntPtr *>(this) - 1);
	}
	constexpr const char8_t *data() const noexcept {
		return nlr::ptr_cast<const String *, const char8_t *>(this);
	}
};

static NLR_INLINE bool operator==(const String &lhs, const String &rhs) noexcept {
	UIntPtr size = lhs.size();
	if (size == rhs.size()) {
		return std::memcmp(lhs.data(), rhs.data(), size) == 0;
	}

	return false;
}

static NLR_INLINE bool operator!=(const String &lhs, const String &rhs) noexcept {
	return !(lhs == rhs);
}

} // namespace nlr

#endif