#include "MainGame.h"

#include <iostream>

MainGame::MainGame()
{
	_window = nullptr;
	_screenWidth = 1024;
	_screenHeight = 768;
	_gameState = GameState::PLAY;
}

MainGame::~MainGame()
{

}

void MainGame::run()
{
	initSystems();

	gameLoop();
}

void MainGame::initSystems()
{
	// Initialize SDL
	SDL_Init(SDL_INIT_EVERYTHING);

	_window = SDL_CreateWindow("Game Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenWidth, _screenHeight, SDL_WINDOW_OPENGL);
}

void MainGame::gameLoop()
{
	while (_gameState != GameState::EXIT)
	{
		processInput();
	}
}

void MainGame::processInput()
{
	SDL_Event evnt;

	// Polls OS for User Events. Returns bool value: was there an event
	while (SDL_PollEvent(&evnt))
	{
		// Event has occured. Process Here
		switch (evnt.type)
		{
			case SDL_QUIT: 
				_gameState = GameState::EXIT;
				break;
			case SDL_MOUSEMOTION:
				// See in SDL_Event documentation: Relationships between event types and union members
				std::cout << evnt.motion.x << ", " << evnt.motion.y << std::endl;
				break;
		}

	}
}