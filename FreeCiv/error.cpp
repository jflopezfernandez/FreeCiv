
#ifndef STDLIB_IOSTREAM_INCLUDED
#define STDLIB_IOSTREAM_INCLUDED
#include <iostream>
#endif

#ifndef FREECIV_ERROR_H_
#include "error.h"
#endif

namespace FreeCiv {
	void ErrorCallbackFunction(int error, const char *description) {
		std::cerr << "[Error " << error << "]: " << description << '\n';
	}
}
