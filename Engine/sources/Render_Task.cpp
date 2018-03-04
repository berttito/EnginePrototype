
/* * * * * * * * * * * * * * * * * * * *\
*                                      *
*  Author: Alberto Quesada Ibáñez      *
*                                      *
*  Date: 30/01/2018                    *
*                                      *
\* * * * * * * * * * * * * * * * * * * */

#pragma once

#include <SDL.h>
#include "Render_Task.hpp"
#include "Scene.hpp"
#include <glbinding\gl\gl.h>

/**Se inicializan los elementos de la escena*/
void Render_Task::initialize()
{
	std::cout << "SE INICIALIZA TAREA DE RENDER";

	/**Camara y luz*/
	render_node->get("light")->translate(glm::vec3(10.f, 10.f, 10.f));
	render_node->get("camera")->translate(glm::vec3(0.f, 0.f, 0.f));

	/**Paredes*/
	render_node->get("wall")->translate(glm::vec3(-24.f, 2.75f, -5.f));
	render_node->get("wall2")->translate(glm::vec3(-24.f, -3.75f, -5.f));
	render_node->get("wall3")->translate(glm::vec3(-28.f, 0.f, -4.4f));
	render_node->get("wall4")->translate(glm::vec3(-20.f, 0.f, -4.4f));	

	render_node->get("wall")->scale(2.5f);
	render_node->get("wall2")->scale(2.5f);
	render_node->get("wall3")->scale(2.5f);
	render_node->get("wall4")->scale(2.5f);

	/**Conejo*/
	render_node->get("conejo")->translate(glm::vec3(0.f, 0.f, -5.f));
	render_node->get("conejo")->scale(0.5f);

	/**Numeros*/
	render_node->get("1")->translate(glm::vec3(1.f, 1.5f, -5.f));
	render_node->get("2")->translate(glm::vec3(-2.25f, 2.f, -5.f));
	render_node->get("3")->translate(glm::vec3(0.5f, -1.f, -5.f));
	render_node->get("4")->translate(glm::vec3(2.f, 0.f, -5.f));
	render_node->get("5")->translate(glm::vec3(-2.f, -1.f, -5.f));
	
	/**Escala de los numeros*/
	render_node->get("1")->scale(0.25f);
	render_node->get("2")->scale(0.15f);
	render_node->get("3")->scale(0.15f);
	render_node->get("4")->scale(0.15f);
	render_node->get("5")->scale(0.25f);
	
	
}


/**Se realiza el glClear y el swapBuffers*/
void Render_Task::run(float deltaTime) 
{
	/**Rotacion de los numeros*/
	render_node->get("1")->rotate_around_y(0.1);
	render_node->get("2")->rotate_around_z(0.05);
	render_node->get("3")->rotate_around_z(0.15);
	render_node->get("4")->rotate_around_y(0.05);
	render_node->get("5")->rotate_around_z(0.03);

	glClearColor(1.0, 0.0, 0.0, 1.0);
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

	/**Se llama al update*/
	for (auto & component : components)
	{
		component->update(deltaTime);
	}
	
	render_node->render();
	
	parent->getParentWindow()->swap_buffers();
}