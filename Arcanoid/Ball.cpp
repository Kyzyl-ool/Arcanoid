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

#ifndef BRICK_INCLUDED
#define BRICK_INCLUDED
#include "Brick.cpp"
#endif

#include <iostream>

enum collide_flag
{
    NULL_DESTINATION,
    FRONT,
    LEFT,
    RIGHT,
    BACK,
};

class Ball: public GameObject
{
private:
    double Vx, Vy;
    int type;
    bool free = false;
    collide_flag f;
    
    
public:
    Ball();
    
    void setVelocity(double iVx, double iVy);
    
    void update(float dt);
    void draw(sf::RenderWindow* window);
    bool collideCheck(GameObject* obj);
    void collideResponse(GameObject* obj);
    
    void release();
    
    void changeVelocityDependedOnCollide();
};

int get_ball_coord_x(int the_type)
{
    return (the_type%3)*BALL_SIZE*5;
}

int get_ball_coord_y(int the_type)
{
    return 588+(the_type/3)*BALL_SIZE*5;
}

Ball::Ball():
f(NULL_DESTINATION)
{
    type = BALL;
    texture.loadFromFile(BLOCKS_AND_BALLS_FILE);
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

void Ball::setVelocity(double iVx, double iVy)
{
    Vx = iVx;
    Vy = iVy;
}

void Ball::collideResponse(GameObject *obj)
{
    switch (obj->who()) {
        case BLOCK:
            changeVelocityDependedOnCollide();
            f = NULL_DESTINATION;
            break;
        default:
            break;
    }
}

void Ball::changeVelocityDependedOnCollide()
{
//    std::cout << 123123 << std::endl;
    switch (f)
    {
        case FRONT:
        {
            std::cout << 11111111 << std::endl;
            if (Vy < 0)
                Vy = -Vy;
            break;
        }
        case BACK:
        {
            std::cout << 22222222 << std::endl;
            if (Vy > 0)
                Vy = -Vy;
            break;
        }
        case LEFT:
        {
            std::cout << 33333333 << std::endl;
            if (Vx > 0)
                Vx = - Vx;
            break;
        }
        case RIGHT:
        {
            std::cout << 444444444 << std::endl;
            if (Vx < 0)
                Vx = -Vx;
            break;
        }
        default:
            break;
    }
}

bool Ball::collideCheck(GameObject* obj)
{
    switch (obj->who()) {
        case BLOCK:
        {
            double x0 = obj->getX();
            double y0 = obj->getY();
//            double katet_x = abs(x + BALL_SIZE/2 - x0);
            double katet_y = (y - BLOCK_HEIGHT - y0);
            
            std::cout << katet_y << std::endl;
//            std::cout << katet_x - (BLOCK_WIDTH+BALL_SIZE)/2 << std::endl;
//            if (katet1*katet1 + katet2*katet2 <= BLOCK_WIDTH*BLOCK_WIDTH)
            
                if (katet_y <= 0)
                {
                    f = FRONT;
                    return true;
                }
                else
                    return false;
            break;
        }
        default:
            break;
    }
}
