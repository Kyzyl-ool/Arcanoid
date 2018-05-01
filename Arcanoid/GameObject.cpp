//
//  GameObject.cpp
//  Arcanoid
//
//  Created by Кежик Кызыл-оол on 01.05.2018.
//  Copyright © 2018 Кежик Кызыл-оол. All rights reserved.
//

#ifndef SFML_G
#define SFML_G
#include <SFML/Graphics.hpp>
#endif

class GameObject
{
protected:
    int x, y;
    sf::Sprite sprite;
    sf::Texture texture;
    
public:
    void draw();
    sf::Sprite* GetSprite();
//    GameObject();
//    ~GameObject();
};

sf::Sprite* GameObject::GetSprite()
{
    return &sprite;
}
