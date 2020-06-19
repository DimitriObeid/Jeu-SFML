#ifndef ENTITY_H
#define ENTITY_H

// C++ standard libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <map>
#include <sstream>
#include <stack>
#include <vector>

// SFML headers
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Entity
{
private:


protected:
	sf::RectangleShape shape;
	float movementSpeed;

public:
	/***********************************************
	*  Constructor / destructor                    * 
	***********************************************/
	Entity();
	virtual ~Entity();


	/***********************************************
	*  Functions				                   * 
	***********************************************/
	virtual void move(const float& dt, const float dir_x, const float dir_y);


	/***********************************************
	*  Update					                   * 
	***********************************************/
	virtual void update(const float& dt);


	/***********************************************
	*  Render					                   * 
	***********************************************/
	virtual void render(sf::RenderTarget* target);
};

#endif