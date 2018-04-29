
#ifndef FREECIV_GLFW_H_
#include "glfw.h"
#endif

namespace FreeCiv {
	namespace GLFW {
		void Initialize() noexcept {
			if (!glfwInit()) {
				exit(EXIT_FAILURE);
			}
		}

		void Exit() noexcept {
			glfwTerminate();
		}
	}
}