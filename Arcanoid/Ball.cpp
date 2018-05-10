//
//  Ball.cpp
//  Arcanoid
//
//  Created by Кежик Кызыл-оол on 01.05.2018.
//  Copyright © 2018 Кежик Кызыл-оол. All rights reserved.
//
<<<<<<< HEAD

//#define DEBUG

#ifdef DEBUG
int debug_fb = 0;
int debug_lr = 0;
=======
>>>>>>> master
#endif

#ifndef SFML_G
#define SFML_G
#include <SFML/Graphics.hpp>
#endif

#ifndef GAME_OBJECT_INCLUDED
#define GAME_OBJECT_INCLUDED
#include "GameObject.cpp"
#endif

<<<<<<< HEAD
#ifndef BRICK_INCLUDED
#define BRICK_INCLUDED
#include "Brick.cpp"
#endif

#include <iostream>


#define BALL_SIZE 44
=======
>>>>>>> master

enum collide_flag
{
    FRONT,
    LEFT,
    RIGHT,
    BACK
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

Ball::Ball()
{
<<<<<<< HEAD
    type = BALL;
    texture.loadFromFile("blocks2.png");
=======
    texture.loadFromFile(BLOCKS_AND_BALLS_FILE);
>>>>>>> master
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
            break;
            
        default:
            break;
    }
}

void Ball::changeVelocityDependedOnCollide()
{
    switch (f)
    {
        case FRONT:
        case BACK:
            Vy = -Vy;
#ifdef DEBUG
            printf("front or back, fb = %d\n", debug_fb);
            debug_fb++;
#endif
            break;
        case LEFT:
        case RIGHT:
            Vx = -Vx;
#ifdef DEBUG
            printf("left or right, lr = %d\n", debug_lr);
            debug_lr++;
#endif
            break;
        default:
            break;
    }
}

bool Ball::collideCheck(GameObject* obj)
{
    switch (obj->who()) {
        case BLOCK:
        {
            int x0 = obj->getX();
            int y0 = obj->getY();
            double katet1 = x0 - x + (BLOCK_WIDTH - BALL_SIZE)/2;
            double katet2 = y0 - y + (BLOCK_HEIGHT - BALL_SIZE)/2;
//            if (katet1*katet1 + katet2*katet2 <= BLOCK_WIDTH*BLOCK_WIDTH)
            {
                if (abs(y - (y0 + BLOCK_HEIGHT)) <= (BLOCK_HEIGHT + BALL_SIZE)/2)
                    if (Vy > 0)
                    {
                        f = BACK;
                        return true;
                    }
                    else
                    {
                        f = FRONT;
                        return true;
                    }
                
                else return false;
            }
//            else return false;
            break;
        }
        default:
            break;
    }
}
