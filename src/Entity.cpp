#include "Entity.h"

/***********************************************
*  Constructor                                 *
***********************************************/
Entity::Entity()
{
	this->shape.setSize(sf::Vector2f(50.f, 50.f));
	this->shape.setFillColor(sf::Color::White);
	this->movementSpeed = 100.f;
}


/***********************************************
*  Regular functions                           *
***********************************************/
// Moving function
void Entity::move(const float& dt, const float dir_x, const float dir_y)
{
	this->shape.move(dir_x * this->movementSpeed * dt, dir_y * this->movementSpeed * dt);
}


/***********************************************
*  Render                                      *
***********************************************/
void Entity::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}


/***********************************************
*  Update                                      *
***********************************************/
// Updating movement according to the pressed key
void Entity::update(const float& dt)
{

}


/***********************************************
*  Destructor                                  *
***********************************************/
Entity::~Entity()
{

}