
/* * * * * * * * * * * * * * * * * * * *\
*                                      *
*  Author: Alberto Quesada Ibáñez      *
*                                      *
*  Date: 30/01/2018                    *
*                                      *
\* * * * * * * * * * * * * * * * * * * */

#pragma once

/**
*  @class: Kernel
*  @brief: Clase kernel contiene el bucle principal.
*          Contiene una lista de tareas para inicializarlas, ejecutarlas y pararlas.
*/

#include "Task.hpp"
#include <iostream>
#include <list>
#include <chrono>

class Kernel
{
	/**Lista de tareas*/
	typedef std::list< Task * > Task_List;

	Task_List task_list;
	bool      exit;

public:

	/**Constructor*/
	Kernel() : exit(false)
	{

	}

	/**Destructor*/
	~Kernel()
	{
		task_list.clear();
	}

	/**Ejecucion del bucle principal*/
	void execute();
	
	/**Parar la ejecucion del kernel*/
	void stop()
	{
		exit = true;
	}

	/**Añadir tareas*/
	void add(Task & task);
	
	/**Comparar tareas*/
	static bool compare(const Task * a, const Task * b)
	{
		return *a < *b;
	}

};

