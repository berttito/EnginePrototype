
/* * * * * * * * * * * * * * * * * * * *\
*                                      *
*  Author: Alberto Quesada Ibáñez      *
*                                      *
*  Date: 30/01/2018                    *
*                                      *
\* * * * * * * * * * * * * * * * * * * */

#pragma once

/**
*  @class: Update_Task
*  @brief: Clase update_task hereda de task y se encarga de hacer el update.
*		
*/

#include <iostream>
#include "Task.hpp"
#include "Update_Module.hpp"

class Update_Task : public Task
{
public:

	/**Constructor que da una prioridad*/
	Update_Task(Scene * scene, int priority = 1, bool finished = false)
		: Task(scene, priority, finished)
	{
	}

	/**Metodo de inicializacion que hereda del padre*/
	void initialize()
	{
		for (auto & component : components)
		{
			component->initialize();
		}

		std::cout << "SE INICIALIZA TAREA DE UPDATE";
	}

	/**Recorre el update de todos los componentes*/
	void run(float time)
	{
		for (auto & component : components)
		{
			component->update(time);
		}
	}

	/**Metodo de finalizacion que hereda del padre*/
	void finalize()
	{
		std::cout << "SE FINALIZA TAREA DE UPDATE";
	}
};