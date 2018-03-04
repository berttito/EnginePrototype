
#include "Scene.hpp"

extern "C" int SDL_main(int argc, char *argv[])
{
	Window window("SDL Prueba", 800, 600);
	std::string path = "..\\..\\resources\\scene.xml";
	Scene * scene = new Scene(path, &window);

	//while (!window.isClosed())
	//{
	//	//window.pollEvents();
	//}
	return 0;
}