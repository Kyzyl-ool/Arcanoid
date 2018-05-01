//
//  Support.cpp
//  Arcanoid
//
//  Created by Кежик Кызыл-оол on 01.05.2018.
//  Copyright © 2018 Кежик Кызыл-оол. All rights reserved.
//
#ifndef SFML_G
#define SFML_G
#include <SFML/Graphics.hpp>
#endif

#ifndef GAME_OBJECT_INCLUDED
#define GAME_OBJECT_INCLUDED
#include "GameObject.cpp"
#endif

#define SUPPORT_HEIGHT 22
#define SUPPORT_EPSILON 0.1

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
    int length;
    double acceleration;
    double velocity;
    

public:
    Support();
    
    double getVelocity();
    
    void setAcceleeration(double acc);
    void setVelocity(double v);
    
    void update(float dt);
    void reduceVelocity();
    
    void dump();
};

Support::Support():
length(SUPPORT_NORMAL)
{
    x = 0;
    y = 0;
    texture.loadFromFile("support.png");
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, 44, 22));
}

void Support::setAcceleeration(double acc)
{
    acceleration = acc;
}

double Support::getVelocity()
{
    return velocity;
}

void Support::update(float dt)
{
    velocity += acceleration*dt;
    x += velocity*dt;
    
    sprite.setPosition(x, y);
    
//    std::cout << "support updated\n";
}

void Support::dump()
{
    std::cout << "acc: " << acceleration << std::endl;
}


//КОРЯВАЯ ФУНКЦИЯ
void Support::reduceVelocity()
{
    velocity /= 8;
    if (velocity < SUPPORT_EPSILON)
    {
        velocity = 0;
    }
}

void Support::setVelocity(double v)
{
    velocity = v;
}
