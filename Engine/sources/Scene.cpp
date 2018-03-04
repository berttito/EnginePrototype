
/* * * * * * * * * * * * * * * * * * * *\
*                                      *
*  Author: Alberto Quesada Ibáñez      *
*                                      *
*  Date: 30/01/2018                    *
*                                      *
\* * * * * * * * * * * * * * * * * * * */

#pragma once

#include "Scene.hpp"
#include "rapidxml.hpp"
#include "Module.hpp"
#include <string>
#include <fstream>
#include <vector>
#include <memory>
#include "Input_Task.hpp"
#include "FactoryModule.hpp"
#include "Render_Task.hpp"

using namespace rapidxml;

/**Constructor de escena*/
Scene::Scene(const std::string & sceneFilePath, Window * window)
	: parentWindow(window), kernel(new Kernel)
{
	/**cargamos la escena*/
	load_scene(sceneFilePath);

	for	(auto iterator = modules.begin(), end = modules.end(); iterator != end; ++iterator)
	{
		kernel->add(*iterator->second->get_task());
	}

	Input_Task * input_task = new Input_Task(this);

	kernel->add(*input_task);

	kernel->execute();	
}

/**Metodo de carga de la escena*/
bool Scene::load_scene(const std::string & scene_file_path)
{
	/**Se lee el contenido del archivo:*/
	std::fstream xml_file(scene_file_path, std::fstream::in);

	if (xml_file.good())
	{
		std::vector< char > xml_content;

		bool finished = false;

		do
		{
			int character = xml_file.get();

			if (character != -1)
			{
				xml_content.push_back((char)character);
			}
			else
				finished = true;
		} while (!finished);

		/**Se añade un caracter nulo al final*/
		xml_content.push_back(0);

		/**Se crea el modelo de documento (DOM)*/
		xml_document< > document;

		document.parse< 0 >(xml_content.data());

		/**Se comprueba que el parseo ha funcionado*/
		xml_node< > * root = document.first_node();

		if (root && std::string(root->name()) == "scene")
		{
			parse_scene(root);
		}

		return true;
	}

	return false;
}

/**Si se ha parseado la escena se continuan parseando las entidades*/
bool Scene::parse_scene(xml_node<> * scene_node)
{
	/**Se recorren los hijos del nodo scene*/
	for (xml_node<> * child = scene_node->first_node(); child; child = child->next_sibling())
	{
		if (child->type() == node_element)
		{
			if (std::string(child->name()) == "entities")
			{
				if (!parse_entities(child)) return false;
			}			
		}
	}

	return true;
}

/**Metodo de parseo de las entities*/
bool Scene::parse_entities(xml_node<> * entities_node)
{
	std::string name;

	/**Se recorren las entity dentro del tag entities*/
	for (xml_node<> * entity_tag = entities_node->first_node(); entity_tag; entity_tag = entity_tag->next_sibling())
	{
		/**si el tag es una entity*/
		if (entity_tag->type() == node_element)
		{
			if (std::string(entity_tag->name()) != "entity") return false;			
		}

		/**se recorren los atributos de cada entity*/
		for (xml_attribute<> * attribute = entity_tag->first_attribute(); attribute; attribute = attribute->next_attribute())
		{
			/**si tiene el mismo nombre*/
			if (std::string(attribute->name()) == "name")
			{
				name = attribute->value();				
			}
		}

		if (name.empty()) return false;
		std::cout << name << std::endl;


		std::shared_ptr< Entity > entity(new Entity(this));


		/**se recorren los hijos de la entity*/
		for (xml_node<> * child = entity_tag->first_node(); child; child = child->next_sibling())
		{
			if (child->type() == node_element)
			{
				if (std::string(child->name()) == "components")
				{
					if (!parse_components(child, *entity)) return false;
				}
			}
		}

		/**se añade la entity al mapa de entities*/
		entities[name] = entity;		
	}

	return true;
}

/**Si se han parseado las entidades se continuan parseando los componentes*/
bool Scene::parse_components(xml_node<> * component_tag, Entity & entity)
{
	 std::string type;

	 /** se recorren todos los componentes*/
	 for (xml_node<> * component_node = component_tag->first_node(); component_node; component_node = component_node->next_sibling())
	 {
		 if (component_node->type() == node_element)
		 {
			 if (std::string(component_node->name()) != "component") return false;
		 }		 

		 for (xml_attribute<>  * attribute = component_node->first_attribute(); attribute; attribute = attribute->next_attribute())
		 {
			 if (std::string(attribute->name()) == "type")
			 {
				 type = attribute->value();
			 }
		 }

		 if (type.empty()) return false;		 
		 
		
			 if (modules.count(type) == 0)
			 {
				 modules[type] = FactoryModule::getInstance()->createModule(type, this);
			 }

			 //if(type != std::string("render"))
			 //{
				// Module * module = modules[type].get();

				// std::cout << type << std::endl;
				// if (!module) return false;

				// /**Se crea el componente*/
				// std::shared_ptr<Component> component(module->create_component(&entity, type, component_node));

				// entity.add_component(type, component);	

				// module->get_task()->add_Component(component);
			 //}

			 if(type != std::string ("script"))
			 {
				 Module * module = modules[type].get();

				 std::cout << type << std::endl;
				 if (!module) return false;

				 /**Se crea el componente*/
				 std::shared_ptr<Component> component(module->create_component(&entity, type, component_node));

				 entity.add_component(type, component);

				 //component ->parse(component_node);

				 if (!component) return false;

				 module->get_task()->add_Component(component);		
			 } 

	 }

	 return true;
}

	