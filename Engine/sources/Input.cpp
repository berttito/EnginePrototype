
/* * * * * * * * * * * * * * * * * * * *\
*                                      *
*  Author: Alberto Quesada Ibáñez      *
*                                      *
*  Date: 30/01/2018                    *
*                                      *
\* * * * * * * * * * * * * * * * * * * */

#pragma once

#include "Input.hpp"
#include <SDL_keyboard.h>

/**Array de las teclas SDL*/
const uint8_t Input::SDLKeys[] =
{
	SDL_SCANCODE_W,
	SDL_SCANCODE_A,
	SDL_SCANCODE_S,
	SDL_SCANCODE_D	
};

/**Constructor*/
Input::Input() :keyboard(SDL_GetKeyboardState(nullptr))
{

}

/**Getter de la key*/
const uint8_t Input::getKey(key _key)
{
	return keyboard[SDLKeys[_key]];
}





