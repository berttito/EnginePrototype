
/* * * * * * * * * * * * * * * * * * * *\
*                                      *
*  Author: Alberto Quesada Ibáñez      *
*                                      *
*  Date: 30/01/2018                    *
*                                      *
\* * * * * * * * * * * * * * * * * * * */

#pragma once

#include <SDL.h>
#include "Input_Task.hpp"
#include "Window.hpp"
#include "Scene.hpp"
#include <iostream>
#include <glbinding\gl\gl.h>

/**CREAR EVENTOS CUANDO PULSAS X TECLA PARA MOVERTE*/

/**Poll events: gestiona eventos tanto de teclado como de ventana*/
void Input_Task::run(float deltaTime) 
{
	SDL_Event event;
		
	if (SDL_PollEvent(&event) > 0)
	{
		switch (event.type)
		{
		case SDL_QUIT:			
			parent->getParentWindow()->stop();
			break;
		case SDL_KEYDOWN:
			SDL_Log("SE MANDA MENSAJE DE MOVIMIENTO");
			break;
		
		default:
			break;
		}
	}

	if (event.type == SDL_WINDOWEVENT)
	{
		switch (event.window.event)
		{
		case SDL_WINDOWEVENT_SHOWN:
			SDL_Log("Window %d shown", event.window.windowID);
			parent->getParentWindow()->show();
			break;

		case SDL_WINDOWEVENT_HIDDEN:
			SDL_Log("Window %d hidden", event.window.windowID);
			parent->getParentWindow()->hide();
			break;

		case SDL_WINDOWEVENT_EXPOSED:
			SDL_Log("Window %d exposed", event.window.windowID);
			break;

		case SDL_WINDOWEVENT_MOVED:
			SDL_Log("Window %d moved to %d,%d",
				event.window.windowID, event.window.data1, event.window.data2);
			break;

		case SDL_WINDOWEVENT_RESIZED:
			SDL_Log("Window %d resized to %dx%d", event.window.windowID, event.window.data1, event.window.data2);
			parent->getParentWindow()->setSize(event.window.data1, event.window.data2);
			gl::glViewport(0, 0, event.window.data1, event.window.data2);
			break;

		case SDL_WINDOWEVENT_SIZE_CHANGED:
			SDL_Log("Window %d size changed to %dx%d", event.window.windowID, event.window.data1, event.window.data2);
			parent->getParentWindow()->setSize(event.window.data1, event.window.data2);
			gl::glViewport(0, 0, event.window.data1, event.window.data2);
			break;

		case SDL_WINDOWEVENT_MINIMIZED:
			SDL_Log("Window %d minimized", event.window.windowID);
			break;

		case SDL_WINDOWEVENT_MAXIMIZED:
			//setWindowed();			;
			break;

		case SDL_WINDOWEVENT_RESTORED:
			SDL_Log("Window %d restored", event.window.windowID);
			break;

		case SDL_WINDOWEVENT_ENTER:
			SDL_Log("Mouse entered window %d", event.window.windowID);
			break;

		case SDL_WINDOWEVENT_LEAVE:
			SDL_Log("Mouse left window %d", event.window.windowID);
			break;

		case SDL_WINDOWEVENT_FOCUS_GAINED:
			SDL_Log("Window %d gained keyboard focus", event.window.windowID);
			break;

		case SDL_WINDOWEVENT_FOCUS_LOST:
			SDL_Log("Window %d lost keyboard focus", event.window.windowID);
			break;

		case SDL_WINDOWEVENT_CLOSE:
			SDL_Log("Window %d closed", event.window.windowID);
			parent->getKernel()->stop();
			break;

		case SDL_WINDOWEVENT_TAKE_FOCUS:
			SDL_Log("Window %d is offered a focus", event.window.windowID);
			break;

		case SDL_WINDOWEVENT_HIT_TEST:
			SDL_Log("Window %d has a special hit test", event.window.windowID);
			break;

		default:
			break;
		}
	}
}