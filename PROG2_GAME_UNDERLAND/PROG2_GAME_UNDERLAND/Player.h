#pragma once
#include "Entity.h"

class Player :
    public Entity
{
private:    
    void initVariables();
    void initComponents();
public:
    Player(float x, float y, sf::Texture& sprite_sheet);
    virtual ~Player();

    //Functions
    virtual void update(const float& dt);
};

