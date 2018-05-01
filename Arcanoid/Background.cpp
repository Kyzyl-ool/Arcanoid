//
//  Background.cpp
//  Arcanoid
//
//  Created by Кежик Кызыл-оол on 01.05.2018.
//  Copyright © 2018 Кежик Кызыл-оол. All rights reserved.
//

#define BACKGROUND_TEXTURE_SIZE 60
#define BACKGROUND_DISTANCE 2

#ifndef GAME_OBJECT_INCLUDED
#define GAME_OBJECT_INCLUDED
#include "GameObject.cpp"
#endif

#ifndef SFML_G
#define SFML_G
#include <SFML/Graphics.hpp>
#endif


#include <string>
#include <iostream>


class Background: public GameObject
{
private:
    int type;

public:
    Background(int the_type);
    
    void draw(sf::RenderWindow* window);
};

int get_background_coord_x(int the_type)
{
    return (((the_type % 8)+1)*BACKGROUND_DISTANCE + BACKGROUND_TEXTURE_SIZE*(the_type % 8));
}

int get_background_coord_y(int the_type)
{
    return ((the_type / 8)+1)*BACKGROUND_DISTANCE + BACKGROUND_TEXTURE_SIZE*(the_type / 8);
}

Background::Background(int the_type)
{
    type = the_type;
    x = get_background_coord_x(type);
    y = get_background_coord_y(type);
    
    
    texture.loadFromFile("backgrounds.png");
    
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(x, y, BACKGROUND_TEXTURE_SIZE, BACKGROUND_TEXTURE_SIZE));
    
    sprite.setPosition(0, 0);
}

void Background::draw(sf::RenderWindow* window)
{
    sf::Vector2u WindowSize = window->getSize();
    
    for (int i = 0; i < WindowSize.x / BACKGROUND_TEXTURE_SIZE + 1; i++)
        for (int j = 0; j < WindowSize.y / BACKGROUND_TEXTURE_SIZE + 1; j++)
        {
            sprite.setPosition(i*BACKGROUND_TEXTURE_SIZE, j*BACKGROUND_TEXTURE_SIZE);
            window->draw(sprite);
        }
}
