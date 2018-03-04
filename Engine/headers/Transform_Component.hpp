
/* * * * * * * * * * * * * * * * * * * *\
*                                      *
*  Author: Alberto Quesada Ibáñez      *
*                                      *
*  Date: 30/01/2018                    *
*                                      *
\* * * * * * * * * * * * * * * * * * * */

#pragma once

/**
*  @class: Transform_Component
*  @brief: Clase transform_component que hereda de component. Permite el movimiento del conejo.
*
*/

#include <Node.hpp>
#include "Component.hpp"
#include "Model_Component.hpp"
#include "Input.hpp"

class Transform_Component : public Component
{
	/**Referencia a la clase input*/
	Input input;

private:

	/**Se crea un node donde vamos a guardar el transform del modelo*/
	glt::Node * transform;

public:

	/**Constructor*/
	Transform_Component(Entity * entity) : Component(entity), transform(nullptr), input() {}

	/**Metodos que tiene que implementar del padre*/
	void initialize() override;
	void update(float deltaTime) override;
	bool parse(xml_node<> * node) override 
	{
		return false;
	}
};