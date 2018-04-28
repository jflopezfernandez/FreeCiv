#ifndef FREECIV_ERROR_H_
#define FREECIV_ERROR_H_

#ifndef FREECIV_STDDEFS_H_
#include "stddefs.h"
#endif

namespace FreeCiv {
	void ErrorCallbackFunction(int error, const char *description);
}

#endif // FREECIV_ERROR_H_
