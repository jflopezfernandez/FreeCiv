
#ifndef FREECIV_GLFW_H_
#include "glfw.h"
#endif

namespace FreeCiv {
	void InitializeGLFW() noexcept {
		if (!glfwInit()) {
			exit(EXIT_FAILURE);
		}
	}

	void ExitGLFW() noexcept {
		glfwTerminate();
	}
}