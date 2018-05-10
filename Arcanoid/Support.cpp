//
//  Support.cpp
//  Arcanoid
//
//  Created by Кежик Кызыл-оол on 01.05.2018.
//  Copyright © 2018 Кежик Кызыл-оол. All rights reserved.
//
#ifndef DEFINES_INCLUDED
#define DEFINED_INCLUDED
#include "defines.cpp"
#endif

#ifndef SFML_G
#define SFML_G
#include <SFML/Graphics.hpp>
#endif

#ifndef GAME_OBJECT_INCLUDED
#define GAME_OBJECT_INCLUDED
#include "GameObject.cpp"
#endif



enum support_length
{
    SUPPORT_SHORT = 44,
    SUPPORT_NORMAL = 88,
    SUPPORT_LONG = 132,
    SUPPORT_VERY_LONG = 176
};

class Support: public GameObject
{
private:
    sf::Sprite sprite2;
    int length;
    int screen_size;
    double velocity;
    

public:
    Support();
    
    void draw(sf::RenderWindow* window);
    
    double getVelocity();
    
    void setVelocity(double v);
    
    void update(float dt);
    void reduceVelocity();
    
    void dump();
};

Support::Support():
length(SUPPORT_NORMAL),
screen_size(DEFAULT_SCREEN_WIDTH)
{
    type = SUPPORT;
    
    x = 0;
    y = DEFAULT_SCREEN_HEIGHT - SUPPORT_HEIGHT;
    
    texture.loadFromFile(BOARD_FILE);
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, 44, 22));
    
    sprite2.setTexture(texture);
    sprite2.setTextureRect(sf::IntRect(0, 0, 44, 22));
    sprite2.setScale(-1, 1);
}

double Support::getVelocity()
{
    return velocity;
}

void Support::update(float dt)
{
    if (x >= 0 && x + length <= screen_size)
        x += velocity*dt;
    else
    {
        velocity = 0;
        if (x < 0)
            x = 0;
        else
            x = screen_size - length;
    }
    
    sprite.setPosition(x, y);
    sprite2.setPosition(x+length, y);
}

void Support::dump()
{
    std::cout << "vel: " << velocity << std::endl;
}


//КОРЯВАЯ ФУНКЦИЯ
void Support::reduceVelocity()
{
    velocity = velocity / 4;
}

void Support::setVelocity(double v)
{
    velocity = v;
}

void Support::draw(sf::RenderWindow* window)
{
    window->draw(sprite);
    window->draw(sprite2);
}
