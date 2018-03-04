
/* * * * * * * * * * * * * * * * * * * *\
*                                      *
*  Author: Alberto Quesada Ibáñez      *
*                                      *
*  Date: 30/01/2018                    *
*                                      *
\* * * * * * * * * * * * * * * * * * * */

#pragma once

/**
*  @class: Task
*  @brief: Clase task generica de la que van a heredar el resto de tareas.
*		   Contiene una lista de componentes.
*		   Contiene un puntero a la escena a la que pertenece.
*/

#include <list>
#include <memory>
#include "Component.hpp"


/**Declaraciones adelantadas*/
class Scene;
class Window;

class Task
{
	/**Prioridad de ejecución y si esta terminada*/
	int  priority;
	bool finished;

protected: 

	/**Puntero a la escena a la que pertenece*/
	Scene * parent;

	/**Lista de components*/
	std::list < std::shared_ptr<Component> >components;

public:

	/**Constructor*/
	Task(Scene * scene, int priority, bool finished = false)
		:		
		parent(scene),
		priority(priority),
		finished(finished)
		
	{		
	}

	/**Si la tarea ha terminado*/
	bool is_finished() const
	{
		return finished;
	}

	/**Metodos virtuales que van a tener que implementar las tareas hijas*/
	virtual void initialize() = 0;
	virtual void finalize() = 0;
	virtual void run(float deltaTime) = 0;

	/**Comparadores de prioridad de tareas*/
	bool operator < (const Task & other) const
	{
		return this->priority < other.priority;
	}

	bool operator > (const Task & other) const
	{
		return this->priority > other.priority;
	}

	/**Añadir un componente a la lista de componentes*/
	void add_Component(std::shared_ptr <Component> component) 
	{
		components.push_back(component);
	}

	/**Referencia a la escena a la que pertenece*/
	Scene * getParentScene() 
	{
		return parent;		
	}	
};