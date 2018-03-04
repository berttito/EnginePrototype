
/* * * * * * * * * * * * * * * * * * * *\
*                                      *
*  Author: Alberto Quesada Ibáñez      *
*                                      *
*  Date: 30/01/2018                    *
*                                      *
\* * * * * * * * * * * * * * * * * * * */

#pragma once

/**
*  @class: Render_Component
*  @brief: Clase render_component que hereda de component.
*         
*/

#include "Component.hpp"

class Render_Component : public Component
{	

public:

	/**Constructor*/
	Render_Component(Entity * entity) : Component(entity) 
	{
		
	}

	/**Metodos que tiene que implementar del padre*/
	void initialize() override {}
	void update(float deltaTime) override {}
	bool parse(xml_node<> * node)override 
	{
		return false;
	}
};