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

#ifndef SUPPORT_INCLUDED
#define SUPPORT_INCLUDED
#include "Support.cpp"
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
    double reflection_angle;
    bool felt;
    
    
public:
    Ball();
    
    void setVelocity(double iVx, double triVy);
    
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
f(NULL_DESTINATION),
reflection_angle(0),
felt(false)
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
    
    if (x > DEFAULT_SCREEN_WIDTH - BALL_SIZE)
    {
//        exit(0);
        f = LEFT;
        changeVelocityDependedOnCollide();
        
//        Vx = - Vx;
    }
    else if (x < 0)
    {
        f = RIGHT;
        changeVelocityDependedOnCollide();
    }
    if (y < 0)
    {
        f = FRONT;
        changeVelocityDependedOnCollide();
    }
    else if (y > DEFAULT_SCREEN_HEIGHT)
    {
        felt = true;
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
//            std::cout << 11111111 << std::endl;
            if (Vy < 0)
                Vy = -Vy;
            f = NULL_DESTINATION;
            break;
        }
        case BACK:
        {
//            std::cout << 22222222 << std::endl;
            if (Vy > 0)
                Vy = -Vy;
            Vx = reflection_angle;
            reflection_angle = 0;
            f = NULL_DESTINATION;
            break;
        }
        case LEFT:
        {
//            std::cout << 33333333 << std::endl;
            if (Vx > 0)
                Vx = - Vx;
            f = NULL_DESTINATION;
            break;
        }
        case RIGHT:
        {
//            std::cout << 444444444 << std::endl;
            if (Vx < 0)
                Vx = -Vx;
            f = NULL_DESTINATION;
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
            
//            std::cout << katet_y << std::endl;
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
        case SUPPORT:
        {
            double x0 = obj->getX();
            Support* tmp = (Support* )obj;
            int length = tmp->getLength();
            if (y + BALL_SIZE > DEFAULT_SCREEN_HEIGHT - SUPPORT_HEIGHT &&
                x + BALL_SIZE/2 > x0 &&
                x < x0 + length)
            {
                f = BACK;
                reflection_angle = 10*(x - x0 - length/2 + BALL_SIZE/2)/(length);
                changeVelocityDependedOnCollide();
            }
            break;
        }
        default:
            break;
    }
}
