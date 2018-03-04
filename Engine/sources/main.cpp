
#include <SDL.h>
#include "Window.hpp"

int main(int, char **)
{
	Window window("SDL Prueba", 800, 600);

	while (!window.isClosed())
	{
		window.pollEvents();
	}

	return 0;
}