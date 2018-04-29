
#ifndef FREECIV_WINDOW_H_
#include "window.h"
#endif


namespace FreeCiv {
	Window newWindow(const int width, const int height, const char *title, Monitor monitor, const Window share) {
		Window newWindow = glfwCreateWindow(width, height, title, monitor, share);

		if (!newWindow) {
			glfwTerminate();

			exit(EXIT_FAILURE);
		}

		return newWindow;
	}

	void CloseWindow(Window window) noexcept {
		glfwDestroyWindow(window);
	}

	bool keepWindowOpen(Window window) noexcept {
		return (!glfwWindowShouldClose(window));
	}

	namespace WINDOW {
		void Close(Window window) noexcept {
			if (!window) { return; }

			glfwDestroyWindow(window);
		}
	}
}
