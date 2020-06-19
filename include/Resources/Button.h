#ifndef BUTTON_H
#define BUTTON_H

// C++ standard libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>

// SFML headers
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

enum button_states
{
    BTN_IDLE = 0,
    BTN_ACTIVE,
    BTN_HOVER
};

class Button
{
private:
    short unsigned buttonState;

    sf::Font* font;
    sf::RectangleShape shape;
    sf::Text text;

    sf::Color idleColor;
    sf::Color hoverColor;
    sf::Color activeColor;

public:
    /***********************************************
	*  Constructor / destructor                    * 
 	***********************************************/
    Button(float x, float y, float width, float height,
        sf::Font* font, std::string text,
        sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor);
    ~Button();


    /***********************************************
    *  Accessors                                   *
    ***********************************************/
    const bool isPressed() const;


	/**********************************************
    * Functions                                   * 
 	***********************************************/


 	/**********************************************
    * Render                                      * 
 	***********************************************/
    void render(sf::RenderTarget* target);


    /**********************************************
    * Update                                      * 
 	***********************************************/
    void update(const sf::Vector2f mousePos);
};

#endif