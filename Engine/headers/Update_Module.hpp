
/* * * * * * * * * * * * * * * * * * * *\
*                                      *
*  Author: Alberto Quesada Ibáñez      *
*                                      *
*  Date: 30/01/2018                    *
*                                      *
\* * * * * * * * * * * * * * * * * * * */

#pragma once

/**
*  @class: Update_Module
*  @brief: Clase update_module que hereda de module.
*          Contiene una referencia a la updateTask.	   
*/

#include "Module.hpp"
#include "Transform_Component.hpp"
#include "Update_Task.hpp"
#include <memory>
#include <string>

using namespace rapidxml;

class Update_Module : public Module
{
private:

	Update_Task updateTask;

public:

	Update_Module(Scene * scene) : Module(scene), updateTask(scene) {}

	static std::shared_ptr <Module> create(Scene * scene)
	{
		return std::shared_ptr <Module>(new Update_Module(scene));
	}

	std::shared_ptr< Component > create_component(Entity * entity, const std::string & type, xml_node<> * data)
	{
		return std::shared_ptr <Component>(new Transform_Component(entity));
	}

	Task * get_task() override
	{
		return &updateTask;
	}
};