
/* * * * * * * * * * * * * * * * * * * *\
*                                      *
*  Author: Alberto Quesada Ibáñez      *
*                                      *
*  Date: 30/01/2018                    *
*                                      *
\* * * * * * * * * * * * * * * * * * * */

#pragma once

#include "Transform_Component.hpp"
#include "Scene.hpp"
#include "SDL.h"


/**Metodo de inicializacion que implementa del madre y obtiene el modelo y lo guarda en el transform*/
void Transform_Component::initialize()
{
	Model_Component * model = dynamic_cast<Model_Component*>(parent->getComponent("render").get());
	transform = model->get_model().get();
}

/**Metodo de actualizacion de la posicion en funcion de la tecla que se pulsa*/
void Transform_Component::update(float deltaTime)
{	
	static float x = 0;
	static float y = 0;

	/**Movimiento eje Y*/
	if (input.getKey(input.S))
	{		
		y = -0.03f;
	}
	else if (input.getKey(input.W))
	{ 
		y = 0.03f;
	}	

	/**Movimiento eje X*/
	if (input.getKey(input.A))
	{
		x = -0.03f;
	}
	else if (input.getKey(input.D))
	{
		x = 0.03f;
	}

	if(input.getKey(input.S) || input.getKey(input.W) || input.getKey(input.A) || input.getKey(input.D))
	{
		//**Se aplica la traslacion*/
		transform->translate(glm::vec3(x, y, 0));
	}
	else
	{
		//**Se aplica la traslacion*/
		transform->translate(glm::vec3(0, 0, 0));
		x = 0;
		y = 0;
	}
	
	
}



