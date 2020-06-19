#include "States/State.h"

/***********************************************
*  Constructor                                 *
***********************************************/
State::State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys)
{
	this->window = window;
	this->supportedKeys = supportedKeys;
	this->quit = false;
}


/***********************************************
*  Accessors                                   *
***********************************************/
// getting the "State"'s class "quit"'s attribute value via the "get" accessor
const bool& State::getQuit() const
{
	return this->quit;
}


/***********************************************
*  Regular functions                           *
***********************************************/
// Game execution interrupts when pressing the defined closing key
void State::checkForQuit()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE"))))
	{
		this->quit = true;
	}
}


/***********************************************
*  Update                                      *
***********************************************/
// Updating input
void State::updateInput(const float& dt)
{

}

// Updating mouse pointer position
void State::updateMousePosition()
{
	this->mousePosScreen = sf::Mouse::getPosition();
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}

void State::updateMousePositions()
{

}


/***********************************************
*  Destructor                                  *
***********************************************/
State::~State()
{

}