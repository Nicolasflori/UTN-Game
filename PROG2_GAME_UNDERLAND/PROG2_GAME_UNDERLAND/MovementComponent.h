#pragma once

#include<iostream>
#include<ctime>
#include<cstdlib>
#include<fstream>
#include<sstream>
#include<stack>
#include<map>
#include<vector>

#include"SFML\Graphics.hpp"
#include"SFML\Window.hpp"
#include"SFML\System.hpp"
#include"SFML\Audio.hpp"
#include"SFML\Network.hpp"

class MovementComponent
{
private:
	sf::Sprite& sprite;
	float maxSpeed;
	sf::Vector2f speed;
	float acceleration;
	float deceleration;

public:
	MovementComponent(sf::Sprite& sprite, float maxSpeed, float acceleration, float deceleration);
	virtual ~MovementComponent();

	const sf::Vector2f getSpeed() const;

	void move(const float x, const float y, const float& dt);
	void update(const float& dt);
};

