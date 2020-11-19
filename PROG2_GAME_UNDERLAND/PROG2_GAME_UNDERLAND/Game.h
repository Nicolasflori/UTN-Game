#pragma once
#include "MainMenuState.h"

class Game
{
private:
	//Variables
	sf::RenderWindow *window;
	sf::Event sfEvent;

	sf::Clock dtClock;
	float dt;

	std::stack<State*> states;

	std::map<std::string, int> supportedKeys;

	//Initialization
	void initWindow();
	void initKeys();
	void initStates();

public:
	//Contructors
	Game();
	//Destructors
	virtual ~Game();

	//Functions
	void endApplication();

	//Update
	void updateDt();
	void updateSFMLEvents();
	void update();

	//Render
	void render();
	void run();
};

