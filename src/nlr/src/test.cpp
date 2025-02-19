#include <nlr/test.h>
#include "runtime.h"

NLR_BEGIN_EXTERN_C

NLR_API int nlr_test__329() {
	nlr::report_critical_error(329, "TEST REPORT, NOT A ERROR");
	return 329;
};

NLR_END_EXTERN_C