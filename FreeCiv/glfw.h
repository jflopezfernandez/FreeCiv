#ifndef FREECIV_GLFW_H_
#define FREECIV_GLFW_H_

#ifndef STDLIB_STDLIB_H_INCLUDED
#define STDLIB_STDLIB_H_INCLUDED
#include <stdlib.h>
#endif

#ifndef STDLIB_IOSTREAM_INCLUDED
#define STDLIB_IOSTREAM_INCLUDED
#include <iostream>
#endif

#ifndef GFLW_GLFW3_H_INCLUDED_
#define GFLW_GLFW3_H_INCLUDED_
    #ifndef GLAD_GLAD_H_INCLUDED
    #define GLAD_GLAD_H_INCLUDED
    #include <glad/glad.h>
    #else
        #error "<glad/glad.h> already included in the project"
    #endif
#include <GLFW/glfw3.h>
#endif

namespace FreeCiv {
	namespace GLFW {
		void Initialize() noexcept;

		void Exit() noexcept;

		inline void PrintVersion() noexcept {
			std::cout << "Version: " << glfwGetVersionString() << '\n';
		}
	}
}


#endif // FREECIV_GLFW_H_
