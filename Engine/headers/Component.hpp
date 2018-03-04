
/* * * * * * * * * * * * * * * * * * * *\
*                                      *
*  Author: Alberto Quesada Ibáñez      *
*                                      *
*  Date: 30/01/2018                    *
*                                      *
\* * * * * * * * * * * * * * * * * * * */

#pragma once

/**
*  @class: Component
*  @brief: Clase component de la que van a heredar el resto de componentes.
*          Contiene un puntero a la entidad a la que pertenece.
*/

#include "rapidxml.hpp"

using namespace rapidxml;

/**Declaracion adelantada*/
class Entity;

class Component
{
protected:

	/**Entidad parent del componente*/
	Entity * parent;

public:

	/**Constructor*/
	Component(Entity * entity) : parent(entity)
	{
	}

	/**Metodos virtuales que van a tener que implementar los componentes hijos*/
	virtual void initialize() = 0;
	virtual void update(float deltaTime) = 0;
	virtual bool parse(xml_node<> * node) 
	{
		return false;
	}

};

