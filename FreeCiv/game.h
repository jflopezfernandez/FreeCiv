#ifndef FREECIV_GAME_H_
#define FREECIV_GAME_H_

#ifndef GLFW_GLFW_H_
#include "glfw.h"
#endif

class GameState;

class Game {
public:
	GameState state;
};


#endif // FREECIV_GAME_H_

