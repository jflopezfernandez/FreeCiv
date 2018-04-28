#ifndef FREECIV_STRING_H_
#define FREECIV_STRING_H_

#ifndef STDLIB_STRING_H_INCLUDED
#define STDLIB_STRING_H_INCLUDED
#include <string.h>
#endif

// Forward declaring C++ String class
//class std::string; // Getting error

namespace FreeCiv {
	using String = char *;
}


#endif // FREECIV_STRING_H_

