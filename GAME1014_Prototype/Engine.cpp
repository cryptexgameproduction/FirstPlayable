#include "Engine.h"

#include <chrono>

using namespace chrono;

bool Engine::init(const char*title, int xpos, int ypos, int width, int height, int flags)
{

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{

		cout << "SDL INIT SUCCESS" << endl;
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		if (m_pWindow != 0)
		{

			cout << "Window Creation Successful" << endl;
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

			if (m_pRenderer != 0)
			{

				cout << "Renderer Creation successful" << endl;
				IMG_Init(IMG_INIT_PNG);

				SDL_Surface* m_pBackgroundSurface = IMG_Load("Assets/Birdie_Background.png");
				
			

			
				SDL_FreeSurface(m_pBackgroundSurface);
			
		


				if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
				{
					std::cout << "Error: " << Mix_GetError() << std::endl; // If Fails to Initialize Audio, Will Display this Error.
				}
			}

			else
			{

				cout << "Renderer Failed" << endl;

				return false;

			}

		}

		else
		{

			cout << "WINDOW CREATION Failed" << endl;

			return false;

		}

	}

	else
	{

		cout << "SDL SYSTEMS Failed" << endl;

		return false;

	}
	m_Player = new Player();
	
	m_Levels = new Levels();
	m_Music = new Music();
	m_Timer = new Timer();

	setState(State::TITLE);
	cout << "Everything worked" << endl;
	m_Music->BaseMusic();
	
	m_bRunning = true;
	// Will render main screen first
	//Set Current Level to 0
	m_iCurrLvl = 0;
	//Game is paused.
	m_bPause = false;

	return true;

}

bool Engine::running()
{

	return m_bRunning;

}

bool Engine::tick()
//Timer
{

	auto duration = steady_clock::now().time_since_epoch();
	auto count = duration_cast<microseconds>(duration).count();

	int tick = 1000000 / m_iFps;

	if (count % tick < 100) // Drops potential duplicate frames.
	{

		if (m_bGotTick == false)
		{

			m_bGotTick = true;
			//cout << "Tick " << tick << " @ " << count << endl;
			return true;

		}

		return false;

	}

	else m_bGotTick = false;

	return false;

}

void Engine::update()
//Updates Player, Hazard, Background
{
	
	if (getState() == State::TITLE || getState() == State::WIN || getState() == State::LOSE) {
	}

	
}


void Engine::render()
//Renders based on boolean
{

	SDL_RenderClear(m_pRenderer);

	

	m_checkState();

	SDL_RenderPresent(m_pRenderer);

}

void Engine::handleEvents()
//Key Down/Up Events
{

	SDL_Event event;

	while (SDL_PollEvent(&event))
	{

		switch (event.type)
		{

		case SDL_QUIT:

			m_bRunning = false;
			break;

		case SDL_KEYDOWN:

			switch (event.key.keysym.sym)
			{

			case SDLK_ESCAPE:

				if (getState() == State::TITLE || getState() == State::WIN || getState() == State::LOSE || getState() == State::SCORE)
				{
					m_bRunning = false;
				}

				break;

			case'w':
			case 'W':

				if (!m_bUp)
				{

					m_bUp = true;

				}

				break;

			case'a':
			case 'A':

				if (!m_bLeft)
				{

					m_bLeft = true;

				}

				break;

			case's':
			case 'S':
				if (getState() == State::TITLE)
				{
					setState(State::SCORE);
					break;
				}

				if (getState() == State::SCORE)
				{
					setState(State::TITLE);
					break;
				}

				if (getState() == State::GAME && !m_bDown)
				{

					m_bDown = true;

				}

				break;

			case'd':
			case 'D':

				if (!m_bRight)
				{

					m_bRight = true;

				}

				break;

				//Start game from main menu
			case'r':
			case 'R':

				if (getState() == State::WIN || getState() == State::LOSE)
				{
					resetLevel();
					
					break;
				}

				if (getState() == State::TITLE)
				{
					
					setState(State::GAME);
					m_Timer->start();
					break;
				}

				if (getState() == State::SCORE)
				{
					//m_bScore = false;
					//m_bGame = true;
					setState(State::GAME);
					m_Timer->start();
					break;
				}
				break;

				// Pause
			case'p':
			case'P':

				pause();

				break;
			}
			break;

		case SDL_KEYUP:
			switch (event.key.keysym.sym)
			{

			case'w':
			case 'W':
				m_bUp = false;

				break;

			case'a':
			case 'A':

				m_bLeft = false;

				break;

			case's':
			case 'S':

				m_bDown = false;

				break;

			case'd':
			case 'D':

				m_bRight = false;

				break;

			}

			break;

		}
	}
}

void Engine::clean()
//Cleans the program
{
	delete m_Player;
	delete m_Levels;
	delete m_Music;
	delete m_Timer;
	SDL_DestroyRenderer(m_pRenderer);
	SDL_DestroyWindow(m_pWindow);
	Mix_Quit();
	IMG_Quit();
	SDL_Quit();

}

void Engine::pause()
//Pause Game
{

	if (getState() == State::GAME && !m_bPause)
	{

		m_bPause = true;
		m_Timer->pause();

	}

	else
	{

		m_bPause = false;
		m_Timer->unpause();
	}
}




void Engine::mainMenu()
{
}


void Engine::resetLevel()
//Resets Level
{
	m_Timer->stop();
	
	setState(State::TITLE);
	m_iCurrLvl = 0;

}


void Engine::m_checkState()
{
	switch (getState())
	{
	case State::TITLE:
		mainMenu();
		break;
	case State::GAME:
		break;
	case State::WIN:
		break;
	case State::LOSE:
		break;
	case State::SCORE:
		break;
	}
}

State Engine::getState()
{
	return m_State;
}

void Engine::setState(State m_newState)
{
	m_State = m_newState;
}

