
/* * * * * * * * * * * * * * * * * * * *\
*                                      *
*  Author: Alberto Quesada Ibáñez      *
*                                      *
*  Date: 30/01/2018                    *
*                                      *
\* * * * * * * * * * * * * * * * * * * */

#pragma once

/**
*  @class: Render_Task
*  @brief: Clase render_task hereda de task y se encarga de ejecutar el glClear y el swapBuffers.
*		   Contiene un render node para la renderizacion.
*		   En su constructor se añaden una camara y una luz.
*/

#include <iostream>
#include "Task.hpp"
#include "Render_Node.hpp"
#include "Camera.hpp"
#include "Light.hpp"
#include "Model.hpp"

class Render_Task : public Task
{

public:

	/**Render node de opengl*/
	std::shared_ptr<glt::Render_Node> render_node;

public:

	/**Constructor que da una prioridad y que crea una camara y una luz*/
	Render_Task(Scene * scene, glt::Render_Node * render_node,  int priority = 2, bool finished = false) 
		: Task(scene, priority, finished), render_node(render_node)
	{		
		render_node->add("light", std::shared_ptr<glt::Light>(new glt::Light));
		render_node->add("camera", std::shared_ptr<glt::Camera>(new glt::Camera(20.f, 0.3f, 1000.f, 1.0f)));
	}

	/**Metodo de inicializacion que hereda del padre*/
	void initialize();
	

	/**Recorre el update de todos los componentes y realiza el glClear y swapBuffers*/
	void run(float time);
	
	/**Metodo de finalizacion que hereda del padre*/
	void finalize() 
	{
		std::cout << "SE FINALIZA TAREA DE RENDER";
	}

public:

	/**Referencia al render node*/
	glt::Render_Node & get_render_node()
	{
	  return *render_node;
	}
};