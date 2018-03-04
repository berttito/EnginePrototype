
/* * * * * * * * * * * * * * * * * * * *\
*                                      *
*  Author: Alberto Quesada Ibáñez      *
*                                      *
*  Date: 30/01/2018                    *
*                                      *
\* * * * * * * * * * * * * * * * * * * */

#pragma once

#include "Module.hpp"
#include "Render_Module.hpp"
#include "Update_Module.hpp"

class FactoryModule
{
	/**Puntero a funcion que devuelve un shared_ptr de module pasandole una escena*/
	typedef std::shared_ptr< Module >(*Module_Factory) (Scene * scene);

	/**Mapa con la factoria*/
	std::map< std::string, Module_Factory >  module_registry;

	/**Instancia*/
	static FactoryModule * instance;

public:

	
	FactoryModule(const FactoryModule &) {}

	/**Operador*/
	FactoryModule & operator = (const FactoryModule &) 
	{
		return *this;
	}

	/**Constructor*/
	FactoryModule() 
	{
		/**Creamos los modulos*/
		registerModule("render", Render_Module::create);
		registerModule("transform", Update_Module::create);
	}

public:

	/**Destructor*/
	~FactoryModule()
	{
		module_registry.clear();
	}

public:

	/**Getter de la instancia*/
	static FactoryModule * getInstance()
	{
		if (!instance)
			instance = new FactoryModule;
		return instance;
	}

	/**Registrar modulo*/
	void registerModule(const std::string & id, Module_Factory factory)
	{
		module_registry[id] = factory;
	}

	/**Crear modulo*/
	std::shared_ptr< Module > createModule(const std::string & id, Scene * scene)
	{
		if (module_registry.count(id))
		{
			return module_registry[id](scene);
		}

		return std::shared_ptr< Module >();
	}
};