#ifndef FREECIV_WINDOW_H_
#define FREECIV_WINDOW_H_

#ifndef GLFW_GLFW3_H_INCLUDED
#define GLFW_GLFW3_H_INCLUDED
#include <GLFW/glfw3.h>
#endif

#ifndef FREECIV_MONITOR_H_
#include "monitor.h"
#endif

// TODO: Create a class to handle window configuration settings

namespace FreeCiv {
	using Window = GLFWwindow * ;

	const auto DEFAULT_SCREEN_HEIGHT = 640;
	const auto DEFAULT_SCREEN_WIDTH  = 480;

	Window newWindow(const int width, const int height, const char *title, Monitor monitor, const Window share);

	void CloseWindow(Window window) noexcept;

	bool keepWindowOpen(Window window) noexcept;

	namespace Callbacks {
		static void EscapeKeyCloseWindow(GLFWwindow *window, int key, int scancode, int action, int mods) {
			if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
				glfwSetWindowShouldClose(window, GLFW_TRUE);
		}
	}
}



#endif // FREECIV_WINDOW_H_
