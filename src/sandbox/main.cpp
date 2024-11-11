#include <vm/runtime.h>
#include <vm/domain.h>
#include <vm/string.h>
#include <iostream>

static NLR_INLINE void nlr_defense(nlr::Result result) noexcept {
	if (result < nlr::Result::Success) {
		exit((std::underlying_type<nlr::Result>::type)(result));
	}
}

int main() {
	using namespace nlr;
	Runtime runtime = Runtime(nullptr, nullptr);

	nlr_defense(runtime.dispose());
	
	return 0;
}