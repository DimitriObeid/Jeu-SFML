#ifndef STATE_H
#define STATE_H

#include "../Entity.h"

using namespace std;

class State
{
private:


protected:
	bool quit;
	sf::RenderWindow* window;
	std::map<std::string, int>* supportedKeys;
	std::map<std::string, int> keybinds;

	sf::Vector2i mousePosScreen;	//
	sf::Vector2i mousePosWindow;	// Pour limiter le d�placement du curseur dans la fen�tre du jeu, C�D qu'il ne sorte pas de la cam�ra
	sf::Vector2f mousePosView;		// Pour "traquer" le curseur dans la cam�ra

	// Resources
	vector<sf::Texture> texture;

	// Protected methods (they can only be called by the "State" Class and its sub classes
	virtual void initKeybinds() = 0;

public:
	/***********************************************
	*  Constructor / destructor                    * 
 	***********************************************/
	State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys);
	virtual ~State();

	const bool& getQuit() const;

	/*
		A pure virtual function (equal to 0) prevent "State" objects creation, except in case of class inheritance
		A pure virtual function MUST ALWAYS be defined
	*/
	virtual void checkForQuit();

	virtual void endState() = 0;


	/***********************************************
	*  Update					                   * 
 	***********************************************/
	virtual void update(const float& dt) = 0;
	virtual void updateInput(const float& dt) = 0;
	virtual void updateMousePosition();
	virtual void updateMousePositions();


	/***********************************************
	*  Render					                   * 
 	***********************************************/
	virtual void render(sf::RenderTarget* target = NULL) = 0;	// Si rien n'est donn�
};

#endif
