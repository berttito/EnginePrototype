
/* * * * * * * * * * * * * * * * * * * *\
*                                      *
*  Author: Alberto Quesada Ibáñez      *
*                                      *
*  Date: 30/01/2018                    *
*                                      *
\* * * * * * * * * * * * * * * * * * * */

#pragma once

#include "Kernel.hpp"

/**Metodo que contiene el bucle principal*/
void Kernel::execute()
{
	/**Se llama al metodo initialize() de todas las task*/
	for	(auto iterator = task_list.begin();	iterator != task_list.end() && !exit; ++iterator)
	{
		Task * task = *iterator;

		task->initialize();
	}

	exit = false;

	/**Bucle principal*/
	while (!exit)
	{		
		for	(auto iterator = task_list.begin();	iterator != task_list.end() && !exit; ++iterator)
		{
			Task * task = *iterator;

			task->run(0); 

			if (task->is_finished())
			{
				task->finalize();
				task_list.erase(iterator);
			}

			if (exit) break;
		}	
	}

	/**Se llama al metodo finalize() de todas las task*/
	for	(auto iterator = task_list.begin(); iterator != task_list.end() && !exit; ++iterator)
	{
		Task * task = *iterator;

		task->finalize();
	}
}

void Kernel::add(Task & task)
{
	/** Se añade la tarea a la lista de tareas*/
	task_list.push_back(&task);

	/** Se reordena la lista por prioridad de ejecución*/
	/** de las tareas*/
	task_list.sort(compare);
}