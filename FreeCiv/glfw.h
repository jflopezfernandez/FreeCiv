#ifndef FREECIV_GLFW_H_
#define FREECIV_GLFW_H_

#ifndef STDLIB_STDLIB_H_INCLUDED
#define STDLIB_STDLIB_H_INCLUDED
#include <stdlib.h>
#endif

#ifndef GFLW_GLFW3_H_INCLUDED_
#define GFLW_GLFW3_H_INCLUDED_
#include <GLFW/glfw3.h>
#endif

namespace FreeCiv {
	void InitializeGLFW() noexcept;

	void ExitGLFW() noexcept;
}


#endif // FREECIV_GLFW_H_
