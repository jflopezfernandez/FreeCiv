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

#ifndef WINDOW
#define WINDOW NamespaceWindow
#else
#error "WINDOW -> NamespaceWindow already defined!"
#endif

// TODO: Create a class to handle window configuration settings

namespace FreeCiv {
	using Window = GLFWwindow * ;

	

	Window newWindow(const int width, const int height, const char *title, Monitor monitor, const Window share);

	void CloseWindow(Window window) noexcept;

	bool keepWindowOpen(Window window) noexcept;

	// TODO: Decide between WINDOW::Close() or CloseWindow(); not sure which one I prefer

	namespace WINDOW {
		const auto DEFAULT_SCREEN_WIDTH = 800;
		const auto DEFAULT_SCREEN_HEIGHT = 600;

		void Close(Window window) noexcept;

		// ERROR: This function fails to load GLAD; currently still using default function
		/*inline void MakeContextCurrent(Window window) noexcept {
			if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
				std::cerr << "Failed to initialize GLAD...\n";
				system("PAUSE");

				exit(EXIT_FAILURE);
			}
		}*/

		// TODO: LoadOpenGLFunctions()
		//void LoadOpenGLFunctions() noexcept;

		// TODO: Start documenting these
		// ----- ----- Callback Function Setters-Wrappers ----- -----
		inline void SetKeyCallback(Window window, void(*callbackFunction)(Window window, int key, int scancode, int action, int mods)) {
			glfwSetKeyCallback(window, callbackFunction);
		}

		inline void SetMouseButtonCallback(Window window, void (*callbackFunction)(Window window, int button, int action, int mods)) {
			glfwSetMouseButtonCallback(window, callbackFunction);
		}

		inline void SetFrameBufferCallback(Window window, void(*callbackFunction)(Window window, int width, int height)) {
			glfwSetFramebufferSizeCallback(window, callbackFunction);
		}

		static inline void ProcessInput(Window window) {
			if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
				glfwSetWindowShouldClose(window, true);
		}

		// Begin actual callback functions

		static inline void MouseButtonCallback(Window window, int button, int action, int mods) {
			if (action == GLFW_PRESS) {
				if (button == GLFW_MOUSE_BUTTON_RIGHT) {
					// TEST: Getting cursor position in callback
					double x = 0;
					double y = 0;

					glfwGetCursorPos(window, &x, &y);

					std::clog << "Mouse coordinates: (" << x << "," << y << ")\n";
				}
			}
		}

		static inline void EscapeKeyCloseWindow(GLFWwindow *window, int key, int scancode, int action, int mods) {
			if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
				glfwSetWindowShouldClose(window, GLFW_TRUE);
		}

		static inline void FramebufferSizeCallback(Window window, int width, int height) {
			// Make sure the viewport matches the new window dimensions; note that width and height
			// will be significantly larger than specified on retina displays

			glViewport(0, 0, width, height);
		}
	}
}

#endif // FREECIV_WINDOW_H_
