#ifndef FREECIV_WINDOW_H_
#define FREECIV_WINDOW_H_

// Included only for 'BeepOnKeyPress' should delete?
#ifndef STDLIB_IOSTREAM_INCLUDED
#define STDLIB_IOSTREAM_INCLUDED
#include <iostream>
#endif
// -- should delete?

#ifndef FREECIV_GLFW_H_
#include "glfw.h"
#endif

#ifndef FREECIV_MONITOR_H_
#include "monitor.h"
#endif

// TODO: Create a class to handle window configuration settings

namespace FreeCiv {
	using Window = GLFWwindow * ;

	const auto DEFAULT_SCREEN_WIDTH  = 800;
	const auto DEFAULT_SCREEN_HEIGHT = 600;

	Window newWindow(const int width, const int height, const char *title, Monitor monitor, const Window share);

	void CloseWindow(Window window) noexcept;

	bool keepWindowOpen(Window window) noexcept;

	// TODO: Create Window namespace or class or something
	//namespace Window {
	//	void Close(Window window) noexcept;
	//}

	namespace Callbacks {
		static void EscapeKeyCloseWindow(GLFWwindow *window, int key, int scancode, int action, int mods) {
			if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
				glfwSetWindowShouldClose(window, GLFW_TRUE);
		}

		// Note: For dev/learning only, remove
		static void BeepOnKeyPress(GLFWwindow *window, int key, int scancode, int action, int mods) {
			if (action == GLFW_PRESS)
				if (key != GLFW_KEY_ESCAPE) {
					std::cout << '\a';
				} else {
					glfwSetWindowShouldClose(window, GLFW_TRUE);
				}
		}
	}
}



#endif // FREECIV_WINDOW_H_
