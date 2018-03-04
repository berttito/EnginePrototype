
/* * * * * * * * * * * * * * * * * * * *\
*                                      *
*  Author: Alberto Quesada Ibáñez      *
*                                      *
*  Date: 30/01/2018                    *
*                                      *
\* * * * * * * * * * * * * * * * * * * */

#pragma once

/**
*  @class: Model_Component
*  @brief: Clase model_component que hereda de component.
*          Contiene un model.
*/

#include "Component.hpp"
#include <memory>
#include <Model_Obj.hpp>
#include "Model.hpp"
#include "rapidxml.hpp"

using namespace rapidxml;

class Model_Component : public Component
{
	/**Model*/
	std::shared_ptr< glt::Model > model;

	/**String con el nombre del modelo*/
	std::string modelName;

public:

	/**Constructor*/
	Model_Component(Entity * entity) : Component(entity), model(nullptr)
	{
	}

	/**Referencia al model*/
	std::shared_ptr< glt::Model > get_model()
	{
		return model; 
	}

	/**Metodos que tiene que implementa del padre*/
	void initialize() override {}
	void update(float deltaTime) override {}
	bool parse(xml_node<> * node) override;
	
	/**Getter del nombre del modelo*/
	std::string getModelName()
	{
		return modelName;
	}
};