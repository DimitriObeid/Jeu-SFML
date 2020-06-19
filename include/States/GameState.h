#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "State.h"

class GameState : public State
{
private:
    /***********************************************
	*  Attributes                                  * 
 	***********************************************/
	Entity player;


    /***********************************************
	*  Methods					                   * 
 	***********************************************/
	void initKeybinds();

public:
    /***********************************************
	*  Constructor / destructor                    * 
 	***********************************************/
	GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys);
	virtual ~GameState();


    /***********************************************
	*  Functions			                       * 
 	***********************************************/
	void endState();


    /***********************************************
	*  Render				                       * 
 	***********************************************/
	void render(sf::RenderTarget* target = NULL);


	/***********************************************
	*  Update					                   * 
 	***********************************************/
	void update(const float& dt);
	void updateInput(const float& dt);
};

#endif
