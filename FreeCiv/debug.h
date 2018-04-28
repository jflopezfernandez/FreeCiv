#ifndef FREECIV_DEBUG_H_
#define FREECIV_DEBUG_H_

#ifndef STDLIB_STRING_INCLUDED
#define STDLIB_STRING_INCLUDED
#include <string>
#endif

template <typename T>
void PrintVar(const std::string& parameterName, const T& parameterValue) {
	#ifdef DEBUG
	std::cout << "[" << parameterName << "]: " << parameterValue << '\n';
	#else
	#endif
}

#endif // FREECIV_DEBUG_H_
