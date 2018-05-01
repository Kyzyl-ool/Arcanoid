//
//  Ball.cpp
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

#define BALL_SIZE 44

class Ball: public GameObject
{
private:
    double Vx, Vy;
    int type;
    bool free = false;
    
    
public:
    Ball();
    
    void update(float dt);
    void draw(sf::RenderWindow* window);
    
    void release();
};

int get_ball_coord_x(int the_type)
{
    return (the_type%3)*BALL_SIZE*5;
}

int get_ball_coord_y(int the_type)
{
    return 588+(the_type/3)*BALL_SIZE*5;
}

Ball::Ball()
{
    texture.loadFromFile("blocks2.png");
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(
                                      get_ball_coord_x(0),
                                      get_ball_coord_y(0),
                                      BALL_SIZE,
                                      BALL_SIZE));
    x = sf::Mouse::getPosition().x;
    y = sf::Mouse::getPosition().y;
    Vx = 0;
    Vy = 0;
    sprite.setPosition(x, y);
}

void Ball::draw(sf::RenderWindow* window)
{
    if (!free)
    {
        x = sf::Mouse::getPosition().x - window->getPosition().x - BALL_SIZE/2;
        y = sf::Mouse::getPosition().y - window->getPosition().y - 1600 - BALL_SIZE/2;
    }
    window->draw(sprite);
    
//    std::cout << sf::Mouse::getPosition().x - window->getPosition().x << ", " << sf::Mouse::getPosition().y - window->getPosition().y - 1600 << std::endl;
}

void Ball::update(float dt)
{
    if (free)
    {
        x += Vx*dt;
        y += Vy*dt;
    }
    
    sprite.setPosition(x, y);
    
//    std::cout << x << ", " << y << std::endl;
}

void Ball::release()
{
    free = true;
}
