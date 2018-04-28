#ifndef FREECIV_MONITOR_H_
#define FREECIV_MONITOR_H_

#ifndef FREECIV_GLFW_H_
#include "glfw.h"
#endif

#ifndef FREECIV_ERROR_H_
#include "error.h"
#endif

namespace FreeCiv {
	using Monitor = GLFWmonitor * ;

	void PrintPrimaryMonitorName() noexcept;
}


#endif // FREECIV_MONITOR_H_
