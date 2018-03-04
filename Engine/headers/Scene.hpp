
/* * * * * * * * * * * * * * * * * * * *\
*                                      *
*  Author: Alberto Quesada Ibáñez      *
*                                      *
*  Date: 30/01/2018                    *
*                                      *
\* * * * * * * * * * * * * * * * * * * */

#pragma once

/**
*  @class: Scene
*  @brief: Clase scene que se va a crear a partir del XML que se parsea.
*		   Contiene un puntero al kernel para la ejecucion del bucle principal.
*		   Contiene dos mapas de entidades y modulos a los que vamos a acceder en el parseo del XML.
*		   Contiene un puntero de la ventana a la que pertenece.
*/


#include <string>
#include <map>
#include <memory>
#include "Entity.hpp"
#include "Module.hpp"
#include "rapidxml.hpp"
#include "Window.hpp"
#include "Kernel.hpp"



class Scene
{
	/**Acceso al kernel*/
	Kernel * kernel;

protected:

	/**Mapas de entidades y modulos*/
	std::map< std::string, std::shared_ptr< Module > > modules;
	std::map< std::string, std::shared_ptr< Entity > > entities;

	/**Acceso a la ventana a la que pertenece*/
	Window * parentWindow;

public:	

	/**Constructor que recibe la ruta del xml y la window a la que pertenece*/
	Scene(const std::string & scene_file_path, Window * window);	
	
	/**Si se carga la escena correctamente*/
	bool load_scene(const std::string & scene_file_path);	
	
	/**Ejecuta el bucle principal que se encuentra en el kernel*/
	void run()
	{
		kernel->execute();
	}

	/**Referencia a la ventana a la que pertenece*/
	Window * getParentWindow()
	{
		return parentWindow;
	}

	/**Referencia al kernel*/
	Kernel * getKernel()
	{
		return kernel;
	}

private:

	/**Metodos para parsear escenas, entidades y componentes*/
	bool parse_scene(xml_node<> * scene_node);
	bool parse_entities(xml_node<> * entities_node);
	bool parse_components(xml_node<> * component_tag, Entity & entity);	
};


