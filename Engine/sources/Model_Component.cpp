
/* * * * * * * * * * * * * * * * * * * *\
*                                      *
*  Author: Alberto Quesada Ibáñez      *
*                                      *
*  Date: 30/01/2018                    *
*                                      *
\* * * * * * * * * * * * * * * * * * * */

#pragma once

#include "Model_Component.hpp"

using namespace rapidxml;

bool Model_Component::parse(xml_node<> * node)
{
	std::string path;

	/**recorremos los nodos del componente buscando la info*/
	for (xml_node<> * component = node->first_node(); component; component = component->next_sibling())
	{
		if(std::string(component->name()) == "name")
		{
			modelName = component->value();
		}

		if (std::string(component->name()) == "mesh")
		{
			/**pasamos la ruta*/
			path = "..//..//resources//";

			/**añadimos el objeto*/
			path += component->value();

			model.reset(new glt::Model_Obj(path));
			return true;
		}
		
		if (std::string(component->name()) == "material")
		{
			//model->add(component->value());
		}

		

	}
}