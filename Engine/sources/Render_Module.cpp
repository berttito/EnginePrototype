
/* * * * * * * * * * * * * * * * * * * *\
*                                      *
*  Author: Alberto Quesada Ibáñez      *
*                                      *
*  Date: 30/01/2018                    *
*                                      *
\* * * * * * * * * * * * * * * * * * * */

#pragma once

#include "Render_Module.hpp"

/**Metodo de creacion del modelo a partir del parseo*/
std::shared_ptr< Component > Render_Module::create_component(Entity * entity, const std::string & type, xml_node<> * data)
{
	if (type == "render")
	{
		/**Se parsea la ruta del archivo del model*/

		/**se crea el componente*/
		std::shared_ptr< Model_Component > compModel(new Model_Component(entity));

		/**parseamos el componente pasandole el nodo de la informacion*/
		compModel->parse(data);

		renderTask.get_render_node().add(compModel->getModelName(), dynamic_cast<Model_Component *> (compModel.get())->get_model());

		return compModel;
	}

	return std::shared_ptr<Component>();
}