
/* * * * * * * * * * * * * * * * * * * *\
*                                      *
*  Author: Alberto Quesada Ibáñez      *
*                                      *
*  Date: 30/01/2018                    *
*                                      *
\* * * * * * * * * * * * * * * * * * * */

#pragma once

#include <SDL.h>
#include "Window.hpp"
#include <assert.h>  
#include <iostream>
#include <glbinding\Binding.h>
#include <glbinding\gl\gl.h>

/**Constructor de la ventana*/
Window::Window(const std::string &title, int width, int height) : _title(title), _width(width), _height(height)
{
	if(!init())
	{
		_closed = true;
	}
}

/**Destructor*/
Window::~Window()
{
	SDL_DestroyWindow(_window);
	SDL_Quit();
}

/**Inicializacion de la ventana con los atributos de openGL*/
bool Window::init()
{
	if(SDL_Init(SDL_INIT_VIDEO)!= 0)
	{
		std::cerr << "Failed to initialize SDL. \n";
		return 0;
	}

	assert(!SDL_GL_LoadLibrary(nullptr));
	
	SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

	
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);


	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);

	/**Se crea la ventana*/
	_window = SDL_CreateWindow(_title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _width, _height, SDL_WINDOW_OPENGL |SDL_WINDOW_RESIZABLE);
	

	if(_window == nullptr)
	{
		std::cerr << "Failed to create window. \n";
		return 0;
	}	

	/**Se crea el contexto*/
	SDL_GLContext context = SDL_GL_CreateContext(_window);	

	glbinding::Binding::initialize(false);

	/**Se crea el viewport*/
	gl::glViewport(0,0, 800, 600);

	return true;
}

/**Metodo para poner la pantalla a fullscreen*/
void Window::setFullScreen()
{	
	SDL_SetWindowFullscreen(_window, SDL_WINDOW_FULLSCREEN);
}

/**Metodo para minimizar la ventana*/
void Window::hide()
{
	SDL_HideWindow(_window);
}

/**Metodo para mostrar la ventana*/
void Window::show()
{
	SDL_ShowWindow(_window);
}

/**Metodo para cerrar la ventana*/
void Window::stop() 
{
	_closed = true;
}

/**Metodo para setear el size de la ventana*/
void Window::setSize(int w, int h)
{
	_width = w;
	_height = h;
	SDL_SetWindowSize(_window, w, h);
}

/**Swap buffers de la ventana*/
void Window::swap_buffers()
{
	SDL_GL_SwapWindow(_window);
}

