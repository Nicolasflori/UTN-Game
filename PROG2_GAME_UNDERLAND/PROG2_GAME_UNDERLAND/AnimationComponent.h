#pragma once

#include<iostream>
#include<string>
#include<map>

#include"SFML\Graphics.hpp"
#include"SFML\Window.hpp"
#include"SFML\System.hpp"
#include"SFML\Audio.hpp"
#include"SFML\Network.hpp"

class AnimationComponent{
private:
	class Animation {
	public:
		sf::Sprite& sprite;
		sf::Texture& textureSheet;
		float animationSpeed;
		float timer;
		int width;
		int height;
		sf::IntRect startRect;
		sf::IntRect currentRect;
		sf::IntRect endRect;

		Animation(sf::Sprite& sprite, sf::Texture& sprite_sheet, 
			float animation_speed,
			int start_frame_x, int start_frame_y, int frames_x, int frames_y, int width, int height)
			: sprite(sprite), textureSheet(sprite_sheet), animationSpeed(animation_speed), width(width), height(height)
		{
			this->timer = 0.f;
			this->startRect = sf::IntRect(start_frame_x * width, start_frame_y * height, width, height);
			this->currentRect = this->startRect;
			this->endRect = sf::IntRect(frames_x * width, frames_y * height, width, height);

			this->sprite.setTexture(this->textureSheet, true);
			this->sprite.setTextureRect(this->startRect);
		}

		void play(const float& dt)
		{
			//Update Timer
			this->timer += 100.f * dt;
			if (this->timer >= this->animationSpeed)
			{
				//Reset the timer
				this->timer = 0.f;

				//Animate
				if (this->currentRect != this->endRect)
				{
					this->currentRect.left += this->width;
				}
				else //Reset
				{
					this->currentRect.left = this->startRect.left;
				}
				this->sprite.setTextureRect(this->currentRect);
			}
		}

		void reset()
		{
			this->timer = 0.f;
			this->currentRect = this->startRect;
		}

	};

	sf::Sprite& sprite;
	sf::Texture& textureSheet;
	std::map<std::string, Animation*> animations;

public:
	AnimationComponent(sf::Sprite& sprite, sf::Texture& sprite_sheet);
	virtual ~AnimationComponent();

	void addAnimation(const std::string key, 
		float animation_speed, int start_frame_x, int start_frame_y, int frames_x, int frames_y, 
		int width, int height);
	void play(const std::string key, const float& dt);
};

