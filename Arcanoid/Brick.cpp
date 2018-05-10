//
//  Brick.cpp
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

class Brick: public GameObject
{
private:
    int sort;
    int health;
    int x2, y2;
    
public:
    Brick(int the_sort, int ix, int iy);
    
    void update();
    void draw(sf::RenderWindow* window);
};

int get_brick_coord_x(int sort)
{
    return sort*BLOCK_WIDTH/2;
}
int get_brick_coord_y(int health)
{
    return (health-1)*BLOCK_HEIGHT/2;
}

Brick::Brick(int the_sort, int ix, int iy):
sort(the_sort),
health(3)
{
    x = ix + 10;
    y = iy;
    x2 = x + BLOCK_WIDTH;
    y2 = y + BLOCK_HEIGHT;
    texture.loadFromFile(DEFAULT_BLOCKS_FILE);
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(
                                      get_brick_coord_x(sort),
                                      get_brick_coord_y(health),
                                      BLOCK_WIDTH/2,
                                      BLOCK_HEIGHT/2));
    sprite.setScale(2, 2);
    sprite.setPosition(x, y);
}

void Brick::update()
{
    sprite.setTextureRect(sf::IntRect(
                                      get_brick_coord_x(sort),
                                      get_brick_coord_y(health),
                                      BLOCK_WIDTH/2,
                                      BLOCK_HEIGHT/2));
}

void Brick::draw(sf::RenderWindow* window)
{
    window->draw(sprite);
    
    
}
