// Licensed to the NiTiS-Dev under one or more agreements.
// The NiTiS-Dev licenses this file to you under the MIT license.

#ifndef _NLR_STRING_H
#define _NLR_STRING_H
#include "../support.h"
#include <string>

NLR_BEGIN_NAMESPACE

class NlrString {
};

template<UintPtr Length>
class StaticNlrString {
private:
	UintPtr size;
	std::array<char8_t, Length> content;

public:
	NLR_INLINE constexpr NlrString *as_string() {
		return ptr_cast<StaticNlrString *, NlrString *>(this);
	}
	NLR_INLINE constexpr std::u8string_view as_std_string_view() {
		return std::u8string_view(move_ptr<char8_t>(this, sizeof(UintPtr)), size);
	}
};

NLR_END_NAMESPACE
#endif