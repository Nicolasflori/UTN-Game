#include "MovementComponent.h"

//Contructor
MovementComponent::MovementComponent(sf::Sprite& sprite, float maxSpeed, float acceleration, float deceleration)
	: sprite(sprite), maxSpeed(maxSpeed), acceleration(acceleration), deceleration(deceleration)
{
	this->maxSpeed = maxSpeed;
}

//Destructor
MovementComponent::~MovementComponent()
{

}

//Functions
const sf::Vector2f MovementComponent::getSpeed() const
{
	return this->speed;
}

void MovementComponent::move(const float dir_x, const float dir_y, const float& dt)
{
	//Acceleration
	this->speed.x += this->acceleration * dir_x;

	this->speed.y += this->acceleration * dir_y;
}


void MovementComponent::update(const float& dt)
{
	//Aceleration and Deceleration x
	if (this->speed.x > 0.f) //positive x
	{
		//Max Speed x positive
		if (this->speed.x > this->maxSpeed)
			this->speed.x = this->maxSpeed;

		//Deceleration x positive
		this->speed.x -= deceleration;
		if (this->speed.x < 0.f)
			this->speed.x = 0.f;
	}
	else if (this->speed.x < 0.f) //negative x
	{
		//Max Speed x negative
		if (this->speed.x < -this->maxSpeed)
			this->speed.x = -this->maxSpeed;

		//Deceleration x negative
		this->speed.x += deceleration;
		if (this->speed.x > 0.f)
			this->speed.x = 0.f;
	}

	//Aceleration and Deceleration y
	if (this->speed.y > 0.f) //positive y
	{
		//Max Speed y positive
		if (this->speed.y > this->maxSpeed)
			this->speed.y = this->maxSpeed;

		//Deceleration y positive
		this->speed.y -= deceleration;
		if (this->speed.y < 0.f)
			this->speed.y = 0.f;
	}
	else if (this->speed.y < 0.f) //negative y
	{
		//Max Speed y negative
		if (this->speed.y < -this->maxSpeed)
			this->speed.y = -this->maxSpeed;

		//Deceleration y negative
		this->speed.y += deceleration;
		if (this->speed.y > 0.f)
			this->speed.y = 0.f;
	}
	
	//Final Speed
	this->sprite.move(this->speed * dt);
}
