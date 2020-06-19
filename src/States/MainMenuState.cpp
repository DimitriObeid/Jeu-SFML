#include "States/MainMenuState.h"

/***********************************************
*  Constructor                                 *
***********************************************/
MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys)
	: State(window, supportedKeys)
{
	this->initFonts();
	this->initKeybinds();

	this->gamestate_btn = new Button(100, 100, 150, 50, &this->font, "New Game",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(0, 0, 20, 200));

	this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	this->background.setFillColor(sf::Color::Magenta);
}


/***********************************************
*  Initialization function                     *
***********************************************/
// Font initialization
void MainMenuState::initFonts()
{
	if (!this->font.loadFromFile("Fonts/Ubuntu-C.ttf"))
	{
		throw("ERROR::MAINMENUSTATE.CPP::UNABLE TO LOAD THIS FONT");	// On quitte le programme et on indique l'erreur s'�tant produite
	}
}

// Keybind initialization
void MainMenuState::initKeybinds()
{
	std::ifstream ifs("Config/gamestate_keybinds.ini");

	if (ifs.is_open())
	{
		std::string key = "";
		std::string key2 = "";

		while (ifs >> key >> key2)
		{
			this->keybinds[key] = this->supportedKeys->at(key2);
		}
	}

	ifs.close();
}

/***********************************************
*  Regular functions                           *
***********************************************/
void MainMenuState::endState()
{
	std::cout << "Ending game state" << std::endl;
}


/***********************************************
*  Update                                      *
***********************************************/
// Updating "MainMenuState" according to the delta-time
void MainMenuState::update(const float& dt)
{
	this->updateMousePositions();
	this->updateInput(dt);
	this->gamestate_btn->update(this->mousePosView);
}

//Updating keyboard input detection
void MainMenuState::updateInput(const float& dt)
{
	this->checkForQuit();
}


/***********************************************
*  Render                                      *
***********************************************/
void MainMenuState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	// Drawing the background
	target->draw(this->background);

	// Render buttons
	this->gamestate_btn->render(target);
}


/***********************************************
*  Destructor                                  *
***********************************************/
MainMenuState::~MainMenuState()
{
	delete this->gamestate_btn;
}
