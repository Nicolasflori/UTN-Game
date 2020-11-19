#include "AnimationComponent.h"

//Constructor
AnimationComponent::AnimationComponent(sf::Sprite& sprite, sf::Texture& sprite_sheet)
	:sprite(sprite), textureSheet(sprite_sheet)
{

}

//Destructor
AnimationComponent::~AnimationComponent()
{
	for (auto& i : this->animations)
	{
		delete i.second;
	}
}

void AnimationComponent::addAnimation(
	const std::string key,
	float animation_speed,
	int start_frame_x, int start_frame_y, int frames_x, int frames_y, int width, int height
)
{
	this->animations[key] = new Animation(
		this->sprite, this->textureSheet, animation_speed, 
		start_frame_x, start_frame_y, frames_x, frames_y, width, height
	);
}

void AnimationComponent::play(const std::string key, const float& dt)
{
	this->animations[key]->play(dt);
}

