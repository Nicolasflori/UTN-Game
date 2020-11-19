#include "Button.h"

//Constructor
Button::Button(float x, float y, float width, float height, sf::Font* font, 
	std::string text, unsigned character_size, 
	sf::Color text_idle_color, sf::Color text_hover_color, sf::Color text_active_color, 
	sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor)
{
	//Default button state
	this->buttonState = BTN_IDLE;

	//Button Shape
	this->shape.setPosition(sf::Vector2f(x, y));
	this->shape.setSize(sf::Vector2f(width, height));
	this->shape.setFillColor(idleColor);

	//Font Configuration
	this->font = font;
	this->text.setFont(*this->font);
	this->text.setString(text);
	this->text.setFillColor(text_idle_color);
	this->text.setCharacterSize(character_size);
	this->text.setPosition(
		this->shape.getPosition().x + (this->shape.getGlobalBounds().width / 2.f) - this->text.getGlobalBounds().width / 2.f,
		this->shape.getPosition().y + (this->shape.getGlobalBounds().height / 2.f) - this->text.getGlobalBounds().height / 2.f
	);

	//Font Color
	this->textIdleColor = text_idle_color;
	this->textHoverColor = text_hover_color;
	this->textActiveColor = text_active_color;

	//Button Color
	this->idleColor = idleColor;
	this->hoverColor = hoverColor;
	this->activeColor = activeColor;

}

//Destructor
Button::~Button()
{
}

const bool Button::isPressed() const
{
	if (this->buttonState == BTN_PRESSED)
		return true;

	return false;
}

void Button::update(const sf::Vector2f mousePos)
{
	//Update button state

	//IDLE
	this->buttonState = BTN_IDLE;
	
	//HOVER
	if (this->shape.getGlobalBounds().contains(mousePos))
	{
		this->buttonState = BTN_HOVER;

		//PRESSED
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			this->buttonState = BTN_PRESSED;
		}
	}

	//Color of the button
	switch (this->buttonState)
	{
	case BTN_IDLE:
		this->shape.setFillColor(this->idleColor);
		this->text.setFillColor(this->textIdleColor);
		break;

	case BTN_HOVER:
		this->shape.setFillColor(this->hoverColor); 
		this->text.setFillColor(this->textHoverColor);
		break;

	case BTN_PRESSED:
		this->shape.setFillColor(this->activeColor);
		this->text.setFillColor(this->textActiveColor);
		break;
	default:
		break;
	}
}

//Button Render
void Button::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
	target->draw(this->text);
}
