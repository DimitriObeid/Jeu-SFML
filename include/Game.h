#ifndef GAME_H
#define GAME_H

#include "States/MainMenuState.h"

class Game
{
private:
    /***********************************************
	*  Constructor / destructor                    * 
 	***********************************************/
	float dt;				// Delta-time is the elapsed time since the last frame
	sf::Clock dtClock;

	sf::Event sfEvent;
	sf::RenderWindow *window;

	std::map<std::string, int> supportedKeys;

	std::stack<State*> states;

    /***********************************************
	*  Initialization methods	                   * 
 	***********************************************/
	void initWindow();
	void initKeys();
	void initStates();

public:
	/***********************************************
	*  Constructor / destructor                    * 
 	***********************************************/
	Game();
	virtual ~Game();


	/***********************************************
	*  Game loop                                   *
	***********************************************/
	void run();


	/***********************************************
	*  Regular functions                           *
	***********************************************/
	void endApplication();


	/***********************************************
	*  Render functions                            *
	***********************************************/
	void render();


	/***********************************************
 	*  Update functions                            *
 	***********************************************/
	void updateSFMLEvents();
	void update();
	void updateDT();
};

#endif
