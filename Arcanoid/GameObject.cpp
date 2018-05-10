//
//  GameObject.cpp
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

#include <iostream>

enum GameObject_t
{
    BALL,
    SUPPORT,
    BLOCK,
    WALL,
    ABYSS
};

class GameObject
{
protected:
    int x, y;
    GameObject_t type;
    sf::Sprite sprite;
    sf::Texture texture;
    
public:
    sf::Sprite* GetSprite();
    virtual void update(float) {;}
    virtual void draw(sf::RenderWindow* window) {;}
    virtual bool collideCheck(GameObject* obj) {;}
    virtual void collideResponse(GameObject* obj) {;}
    
    int getX();
    int getY();
    
    GameObject_t who();
//    GameObject();
//    ~GameObject();
};

sf::Sprite* GameObject::GetSprite()
{
    return &sprite;
}

GameObject_t GameObject::who()
{
    return type;
}

int GameObject::getX()
{
    return x;
}

int GameObject::getY()
{
    return y;
}
