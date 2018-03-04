
/* * * * * * * * * * * * * * * * * * * *\
*                                      *
*  Author: Alberto Quesada Ibáñez      *
*                                      *
*  Date: 30/01/2018                    *
*                                      *
\* * * * * * * * * * * * * * * * * * * */

#pragma once

/**
*  @class: Entity
*  @brief: Clase entity, actua como contenedor. 
*          Contiene una lista de componentes, en ellos es donde se hacen las diferentes cosas (render, transform.. etc)
*/

#include "Component.hpp"
#include <map>
#include <string>
#include <memory>


/**Declaracion adelantada*/
class Scene;

class Entity
{
	/**Mapa ordenado con el nombre del componente y el puntero al componente*/
	typedef std::map< std::string, std::shared_ptr< Component > > Components;

	Components componentes;

	/**Escena parent de la entidad*/
	Scene * parent;

public:

	/**Constructor*/
	Entity(Scene * scene) : parent(scene)
	{
	}

	/**Metodo de inicializacion que llama a la initialize de los components*/
	void initialize()
	{
		for (auto & component : componentes)
		{
			component.second->initialize();					
		}
	}

	/**Metodo de update que llama al update de los components*/
	void update(float deltaTime)
	{
		for (auto & component : componentes)
		{
			component.second->update(deltaTime);			
		}
	}

	/**Metodo para añadir un componente*/
	void add_component(const std::string & name, std::shared_ptr< Component > & component)
	{
		componentes[name] = component;
	}

	/**Obtener el componente en funcion del name*/
	std::shared_ptr< Component > getComponent(const std::string & name)
	{
		return componentes[name];
	}

};