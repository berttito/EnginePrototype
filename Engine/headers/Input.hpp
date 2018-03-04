
/* * * * * * * * * * * * * * * * * * * *\
*                                      *
*  Author: Alberto Quesada Ibáñez      *
*                                      *
*  Date: 30/01/2018                    *
*                                      *
\* * * * * * * * * * * * * * * * * * * */

#pragma once

/**
*  @class: Input
*  @brief: Clase input con una enumeracion de las teclas que se van a usar.
*		   Contiene un array de teclas SDL.
*
*/

#include <cstdint>

class Input {

	public:

		/**Enum de las teclas utilizadas*/
		enum key {

			W, A, S, D

		};

	private:

		const uint8_t *keyboard;

		static const uint8_t SDLKeys[];

	public:

		/**Constructor*/
		Input();

		/**Getter de la key*/
		const uint8_t getKey(key _key);



};


