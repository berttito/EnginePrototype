
/* * * * * * * * * * * * * * * * * * * *\
*                                      *
*  Author: Alberto Quesada Ibáñez      *
*                                      *
*  Date: 30/01/2018                    *
*                                      *
\* * * * * * * * * * * * * * * * * * * */

#pragma once

/**
*  @class: Window
*  @brief: Clase window que contiene todos los elementos correspondientes a la ventana.
*		   Contiene una struct de la window de SDL. Se crea en el main.
*/

#include <string>

struct SDL_Window;

class Window 
{
public:

	/**Constructor*/
	Window(const std::string &title, int width, int height);

	/**Destructor*/
	~Window();
	

private:

	/**Atributos de titulo, ancho, alto*/
	std::string _title;
	int _width;
	int _height;	

	/**bool para controlar cuando se cierra*/
	bool _closed = false;

	SDL_Window * _window = nullptr;

public:

	bool init();
	
	/**Controlar si la ventana ha sido cerrada*/
	inline bool isClosed() const { return _closed; }	

public:

	/**Getter y setter del titulo*/
	std::string getTitle() const { return _title; };
	void setTitle(const std::string & title) { _title = title; };

	/**Getter y setter del ancho y el alto*/
	int getWidth() const { return _width; };
	int getHeight() const { return _height; };
	void setWidth(int width) { _width = width; };
	void setHeight(int height) { _height = height; };
	
	/**Poner la ventana a fullscreen*/
	void setFullScreen();

	/**Esconder la ventana*/
	void hide();

	/**Mostrar la ventana*/
	void show();

	/**Parar la ventana*/
	void stop();

	/**Setear el size de la ventana*/
	void setSize(int w, int h);

	/**Swap Buffers*/
	void swap_buffers();

	
};
