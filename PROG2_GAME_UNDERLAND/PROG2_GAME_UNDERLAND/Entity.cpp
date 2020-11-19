#include "Entity.h"

//Init
void Entity::initVariables()
{
	this->movementComponent = NULL;
}

//Constructor
Entity::Entity()
{
	this->initVariables();
}

//Destructor
Entity::~Entity()
{
	delete this->movementComponent;
	delete this->animationComponent;
}

//Functions
void Entity::setTexture(sf::Texture& texture)
{
	this->sprite.setTexture(texture);
}

void Entity::createMovementComponent(const float maxSpeed, const float acceleration, const float deceleration)
{
	this->movementComponent = new MovementComponent(this->sprite, maxSpeed, acceleration, deceleration);
}

void Entity::createAnimationComponent(sf::Texture& sprite_sheet)
{
	this->animationComponent = new AnimationComponent(this->sprite, sprite_sheet);
}

void Entity::setPosition(const float x, const float y)
{
		this->sprite.setPosition(x, y);
}

void Entity::move(const float dir_x, const float dir_y, const float& dt)
{
	if (this->movementComponent)
	{
		//Set Speed
		this->movementComponent->move(dir_x, dir_y, dt);
	}
}

void Entity::update(const float& dt)
{
	
}

void Entity::render(sf::RenderTarget* target)
{
		target->draw(this->sprite);
}
