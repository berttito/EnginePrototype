
/* * * * * * * * * * * * * * * * * * * *\
*                                      *
*  Author: Alberto Quesada Ibáñez      *
*                                      *
*  Date: 30/01/2018                    *
*                                      *
\* * * * * * * * * * * * * * * * * * * */

#pragma once

/**
*  @class: Input_Task
*  @brief: Clase input_task hereda de task y se encarga de todos los eventos que tienen que ver con la ventana y el input.
*/

#include <iostream>
#include "Task.hpp"
#include "Render_Task.hpp"
#include "Transform_Component.hpp"


class Input_Task : public Task
{	
public:

	/**Constructor*/
	Input_Task(Scene * scene, int priority = 5, bool finished = false)
		: Task(scene, priority, finished)
	{
	}

	/**Metodo de inicializacion que hereda del padre*/
	void initialize()
	{
		std::cout << "SE INICIALIZA TAREA DE INPUT";
	}

	/**Metodo que va a controlar eventos de ventana e input que hereda del padre*/
	void run(float deltaTime);

	/**Metodo de finalizacion que hereda del padre*/
	void finalize()
	{
		std::cout << "SE FINALIZA TAREA DE INPUT";
	}
	
};