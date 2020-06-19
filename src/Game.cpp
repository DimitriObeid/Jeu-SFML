#include "Game.h"

/***********************************************
*  Constructor                                 *
***********************************************/
Game::Game()
{
    this->initWindow(); // On appelle la fonction d'initialisation de la fen�tre de jeu
    this->initKeys();   // On appelle la fonction d'initialisation des options des touches du clavier (IMPORTANT : avant d'initialiser les �v�nements)
    this->initStates(); // On appelle la fonction d'initialisation des �v�nements
}


/***********************************************
*  Game loop                                   *
***********************************************/
void Game::run()
{
    // Game loop
    while (this->window->isOpen())
    {
        this->updateDT();   // Updating the delta-time at each frame
        this->update();     // Calling the update functio,
        this->render();     // Calling the game render window's render function
    }
}


/***********************************************
*  Initialization functions                    *
***********************************************/
// Window initialization
void Game::initWindow()
{
    std::ifstream ifs("Config/Window.ini");      // Creating a stream to the "window.ini" file
    std::string title = "None";
    sf::VideoMode window_bounds(800, 600);
    unsigned framerate_limit = 120;
    bool vertical_sync_enabled = false;

    if (ifs.is_open())
    {
        std::getline(ifs, title);
        ifs >> window_bounds.width >> window_bounds.height;
        ifs >> framerate_limit;
        ifs >> vertical_sync_enabled;
    }

    ifs.close();

    this->window = new sf::RenderWindow(sf::VideoMode(window_bounds), title);	// On alloue de la m�moire dynamiquement lors de la cr�ation d'une fen�tre en utilisant les options d'un fichier "window.ini"
    this->window->setFramerateLimit(framerate_limit);
    this->window->setVerticalSyncEnabled(vertical_sync_enabled);
}

// Keys support initialization
void Game::initKeys()
{
    std::ifstream ifs("Config/supported_keys.ini");

    if (ifs.is_open())
    {
        std::string key = "";
        int key_value = 0;

        while (ifs >> key >> key_value)
        {
            this->supportedKeys[key] = key_value;
        }
    }

    ifs.close();

    for (auto i : this->supportedKeys)
        std::cout << i.first << " " << i.second << std::endl;
}

// Events initialization
void Game::initStates()
{
    this->states.push(new MainMenuState(this->window, &this->supportedKeys));
}


/***********************************************
*  Regular functions                           *
***********************************************/
void Game::endApplication()
{
    std::cout << "End application" << std::endl;
}


/***********************************************
*  Render function                             *
***********************************************/
// Game's window render function
void Game::render()
{
    this->window->clear();  // Cleaning the render window from old pixels (resulting from the last frame)

    // Render objects
    if (!this->states.empty())
        this->states.top()->render(this->window);

    this->window->display();    // Display the render window's content
}



/***********************************************
*  Update functions                            *
***********************************************/
// Different updates are done by simply calling this function
void Game::update()
{
    this->updateSFMLEvents();

    if (!this->states.empty())
    {
        this->states.top()->update(this->dt);

        if (this->states.top()->getQuit())
        {
            this->states.top()->endState();
            delete this->states.top();
            this->states.pop();
        }
    }

    // Closing window, ending program
    else
    {
        this->endApplication();
        this->window->close();
    }
}

// Delta-time update according to the time took to update and didsplay an image's render
void Game::updateDT()
{
    this->dt = this->dtClock.restart().asSeconds();
}

// Updating SFML events
void Game::updateSFMLEvents()
{
    while (this->window->pollEvent(this->sfEvent))
    {
        if (this->sfEvent.type == sf::Event::Closed)
            this->window->close();
    }
}


/***********************************************
*  Destructor                                  *
***********************************************/
Game::~Game()
{
    delete this->window;	// Freeing allocated memory for displaying render window

    while (!this->states.empty())
    {
        delete this->states.top();
        this->states.pop();
    }
}