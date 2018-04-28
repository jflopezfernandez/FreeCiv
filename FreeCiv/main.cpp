
/*! \todo Create master application class with mainWindow and primaryMonitor members */

#ifndef STDLIB_IOSTREAM_INCLUDED
#define STDLIB_IOSTREAM_INCLUDED
#include <iostream>
#endif

#ifndef STDLIB_STRING_INCLUDED
#define STDLIB_STRING_INCLUDED
#include <string>
#endif

#ifndef FREECIV_WINDOW_H_
#include "window.h"
#endif

#ifndef FREECIV_DEBUG_H_
#include "debug.h"
#endif

using namespace FreeCiv;

//static void key_callback(Window window, int key, int scancode, int action, int mods) {
//	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
//		glfwSetWindowShouldClose(window, GLFW_TRUE);
//}


int main()
{
	// Establish GLFW error callback function
	glfwSetErrorCallback(ErrorCallbackFunction);

	InitializeGLFW();

	Monitor primaryMonitor = glfwGetPrimaryMonitor();
	const auto primaryMonitorName = glfwGetMonitorName(primaryMonitor);

	//std::cout << "Primary Monitor Name: " << primaryMonitorName << '\n';
	PrintVar("Primary Monitor Name", primaryMonitorName);

	// Create a windowed mode window and its OpenGL context
	const auto mainWindow = newWindow(640, 480, "Hello, World!", NULL, NULL);
	
	// Bind the key callback defined above to the main window
	glfwSetKeyCallback(mainWindow, Callbacks::EscapeKeyCloseWindow);

	// Make the window's context current
	glfwMakeContextCurrent(mainWindow);

	// Loop until the user closes the window
	while (keepWindowOpen(mainWindow)) {
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(mainWindow);
		glfwPollEvents();
	}

	CloseWindow(mainWindow);
	ExitGLFW();

	return EXIT_SUCCESS;
}