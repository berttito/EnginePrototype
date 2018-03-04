
/* * * * * * * * * * * * * * * * * * * *\
*                                      *
*  Author: Alberto Quesada Ibáñez      *
*                                      *
*  Date: 30/01/2018                    *
*                                      *
\* * * * * * * * * * * * * * * * * * * */

#pragma once

/**
*  @class: Render_Module
*  @brief: Clase render_module que hereda de module.
*          Contiene una referencia a la renderTask.
*		   En el se parsea el modelo y se crea el modelComponent.
*/

#include "Module.hpp"
#include "Render_Component.hpp"
#include "Model_Component.hpp"
#include "Render_Task.hpp"
#include "rapidxml.hpp"
#include <memory>
#include <string>

class Render_Module : public Module
{
private:

	Render_Task renderTask;

public:

	/**Constructor*/
	Render_Module(Scene * scene) : Module(scene), renderTask(scene, new glt::Render_Node) 
	{
	}	

	/**Metodo de creacion del modelo a partir del parseo*/
	std::shared_ptr< Component > create_component(Entity * entity, const std::string & type, xml_node<> * data) override;
	
	/**Se crea el modulo*/
	static std::shared_ptr<Module> create (Scene * scene)
	{
		return std::shared_ptr<Module>(new Render_Module(scene));
	}

	/**Referencia a la renderTask*/
	Task * get_task() override
	{
		return &renderTask;
	}
};