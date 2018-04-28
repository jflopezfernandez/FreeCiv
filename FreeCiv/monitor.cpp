
#ifndef STDLIB_IOSTREAM_INCLUDED
#define STDLIB_IOSTREAM_INCLUDED
#include <iostream>
#endif

#ifndef FREECIV_MONITOR_H_
#include "monitor.h"
#endif

namespace FreeCiv {
	void PrintPrimaryMonitorName() noexcept {
		const auto primaryMonitor = glfwGetPrimaryMonitor();

		std::cout << glfwGetMonitorName(primaryMonitor) << '\n';
	}
}
