// Licensed to the NiTiS-Dev under one or more agreements.
// The NiTiS-Dev licenses this file to you under the MIT license.

#include "runtime.h"
#include <iostream>

#ifdef NLR_PLATFORM_WINDOWS
#include <Windows.h>

void nlr::report_critical_error(SInt32 error_code, const char *message) noexcept {
	SetConsoleOutputCP(CP_UTF8);
	setvbuf(stdout, nullptr, _IOFBF, 1000);

	std::cout << "nlr: critical error: " << error_code << "\n\r"
			<< message;

	ExitProcess(error_code);
}
#endif