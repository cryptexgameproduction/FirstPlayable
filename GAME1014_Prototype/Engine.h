#pragma once

#include "fstream"
#include "Sprite.h"
#include "Player.h"
#include "Levels.h"
#include "Images.h"
#include "SoundManager.h"
#include "Timer.h"

#include "Collision.h"

#define fps 60

enum State {
	TITLE,
	GAME,
	WIN,
	LOSE,
	SCORE
};

class Engine
{

public:

	Engine() :m_iFps(fps), m_bGotTick(false) {}
	~Engine() {}

	bool init(const char*title, int xpos, int ypos, int width, int height, int flags);

	bool running();
	bool tick();
	void update();
	void render();
	void clean();
	void pause();
	void handleEvents();
	void mainMenu();
	void resetLevel();
	void m_checkState();
	State getState();
	void setState(State m_newState);
	static Engine* I()
	{

		static Engine* instance = new Engine();
		return instance;

	}

private:

	int m_iFps, m_iCurrLvl;

	bool m_bRunning, m_bGotTick, m_bPause;
	bool m_bUp, m_bDown, m_bLeft, m_bRight;

	State m_State;

	Win m_Win;
	Lose m_Lose;
	Paused m_Paused;

	Player *m_Player;
	Levels *m_Levels;
	Music *m_Music;
	Timer *m_Timer;
	

	Collision m_Collision;
	

	SDL_Window*m_pWindow;
	SDL_Renderer*m_pRenderer;

	SDL_Texture*m_pPauseTexture;
	SDL_Texture*m_pWinTexture;
	SDL_Texture*m_pLoseTexture;
};

