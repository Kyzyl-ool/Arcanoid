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

class GameObject
{
protected:
    int x, y;
    sf::Sprite sprite;
    sf::Texture texture;
    
public:
    sf::Sprite* GetSprite();
    virtual void update(float) {;}
    virtual void draw(sf::RenderWindow* window) {;}
//    GameObject();
//    ~GameObject();
};

sf::Sprite* GameObject::GetSprite()
{
    return &sprite;
}
