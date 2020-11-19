#include "Player.h"

//Init Functions
void Player::initVariables()
{
}

void Player::initComponents()
{
}

//Constructor
Player::Player(float x, float y, sf::Texture& sprite_sheet)
{
	this->initVariables();
	this->setPosition(x, y);

	this->createMovementComponent(400.f, 15.f, 5.f);
	this->createAnimationComponent(sprite_sheet);

	this->animationComponent->addAnimation("IDLE_LEFT", 18.f, 0, 0, 5, 0, 192, 251);
}

//Destructor
Player::~Player()
{

}

//Functions
void Player::update(const float& dt)
{
	this->movementComponent->update(dt);

	this->animationComponent->play("IDLE_LEFT", dt);
}
