
#include <iostream>

#include <GLFW/glfw3.h>


/** Function:			PrintGLFWVersion()
 *
 *  Description:		This function is inline because 'glfwGetVersionString()' must be
 *                      called from the main thread.
 *
 *  Return Type:		void
 */

inline void PrintGLFWVersion() {
	std::cout << "GLFW Version: " << glfwGetVersionString() << '\n';
}


int main()
{
	//std::cout << "GLFW Version: " << glfwGetVersionString() << '\n';
	PrintGLFWVersion();

	const auto NullVar = GLFW_NOT_INITIALIZED;

	GLFWwindow *window;

	// Initialize the library
	if (!glfwInit()) {
		return -1;
	}

	// Create a windowed mode window and its OpenGL context
	window = glfwCreateWindow(640, 480, "Hello, World!", NULL, NULL);
	if (!window) {
		glfwTerminate();
		return -1;
	}

	// Make the window's context current
	glfwMakeContextCurrent(window);

	// Loop until the user closes the window
	while (!glfwWindowShouldClose(window)) {
		// Render here
		glClear(GL_COLOR_BUFFER_BIT);

		// Swap front and back buffers
		glfwSwapBuffers(window);

		// Poll for and process events
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}