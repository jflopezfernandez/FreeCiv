
/*! \todo Create master application class with mainWindow and primaryMonitor members */

#ifndef WINDOWS_HEADER_INCLUDED
#define WINDOWS_HEADER_INCLUDED
#include <Windows.h>
#endif

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

const auto APPLICATION_NAME = "FreeCiv";

using namespace FreeCiv;

int main()
{
	GLFW::Initialize();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	Window mainWindow = newWindow(WINDOW::DEFAULT_SCREEN_WIDTH, WINDOW::DEFAULT_SCREEN_HEIGHT, "FreeCiv", NULL, NULL);

	glfwMakeContextCurrent(mainWindow);
	// ERROR: WINDOW::MakeContextCurrent(mainWindow);
	WINDOW::SetFrameBufferCallback(mainWindow, WINDOW::FramebufferSizeCallback);
	WINDOW::SetMouseButtonCallback(mainWindow, WINDOW::MouseButtonCallback);

	// glad: load all OpenGL function pointers
	// ---------------------------------------
	if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl;
		system("PAUSE");
		return -1;
	}

	// ----- ----- Triangle Code ----- -----
	float vertices[] = {
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.0f,  0.5f, 0.0f
	};

	unsigned int vertexBufferObject = 0;
	glGenBuffers(1, &vertexBufferObject);

	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);

	const auto vertexShaderSource = "#version 330 core\nlayout (location = 0) in vec3 aPos;\n\nvoid main()\n{\n\tgl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n}\n";

	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	int success = 0;
	char infoLog[512] = { 0 };

	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
	
	if (!success) {
		std::cerr << "ERROR: Shader-Vertex Compilation Failed:\n\t" << infoLog << '\n';
	} else {
		std::clog << "Successfully compiled shader: \n\t";

		if (!strlen(infoLog)) {
			std::clog << "<Error Log Empty>\n";
		} else {
			std::clog << infoLog << '\n';
		}
	}

	while (keepWindowOpen(mainWindow)) {
		WINDOW::ProcessInput(mainWindow);

		// Rendering Commands
		glClearColor(1.f, 1.f, 1.f, 1.f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(mainWindow);
		glfwPollEvents();
	}
	
	WINDOW::Close(mainWindow);
	GLFW::Exit();

	return EXIT_SUCCESS;
}
