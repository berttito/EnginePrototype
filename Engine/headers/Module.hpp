
/* * * * * * * * * * * * * * * * * * * *\
*                                      *
*  Author: Alberto Quesada Ibáñez      *
*                                      *
*  Date: 30/01/2018                    *
*                                      *
\* * * * * * * * * * * * * * * * * * * */

#pragma once

/**
*  @class: Module
*  @brief: Clase module de la que van a heredar el resto de modulos.
*          Contiene un puntero a la escena a la que pertenece.
*/

#include "Component.hpp"
#include "Task.hpp"
#include <map>
#include <string>
#include <memory>

class Module
{
protected:

	/**Puntero a la escena*/
	Scene * scene;

	/**Constructor*/
	Module(Scene * scene) : scene(scene) {}

public:
	
	/**Metodo virtual para crear un componente*/
	virtual std::shared_ptr< Component > create_component(Entity * entity, const std::string & type, xml_node<> * data) = 0;

	/**Metodo virtual para acceder a la task*/
	virtual Task * get_task()
	{
		return nullptr;
	}

};