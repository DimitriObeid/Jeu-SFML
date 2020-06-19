#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include "GameState.h"
#include "../Resources/Button.h"

class MainMenuState :
    public State
{
private:
	/***********************************************
	* Attributes                                   * 
 	***********************************************/
	sf::Font font;
	sf::RectangleShape background;

	Button* gamestate_btn;


	/***********************************************
	* Methods                                   * 
 	***********************************************/
	void initFonts();
	void initKeybinds();

public:
    /***********************************************
	*  Constructor / destructor                    * 
 	***********************************************/
	MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys);
	virtual ~MainMenuState();


    /***********************************************
	*  Functions			                       * 
 	***********************************************/
	void endState();


    /***********************************************
	*  Render				                       * 
 	***********************************************/
	void render(sf::RenderTarget* target = NULL);
	

    /***********************************************
	*  Update				                       * 
 	***********************************************/
	void update(const float& dt);
	void updateInput(const float& dt);
};

#endif
