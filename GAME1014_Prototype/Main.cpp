#include "Engine.h"

#define wwidth 1024
#define wheight 768

int main(int argc, char*args[])
{

	Engine game;



	Engine::I()->init("GAME1014 Prototype", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, wwidth, wheight, 0);

	while (Engine::I()->running())
	{

		Engine::I()->handleEvents();

		if (Engine::I()->tick())
		{

			Engine::I()->update();
			Engine::I()->render();

		}

	}

	Engine::I()->clean();
	system("pause");

	return 0;
}