//
//  GraphicsManager.cpp
//  Arcanoid
//
//  Created by Кежик Кызыл-оол on 01.05.2018.
//  Copyright © 2018 Кежик Кызыл-оол. All rights reserved.
//
#define AMOUNT_OF_GAME_OBJECTS 10

#ifndef SFML_G
#define SFML_G
#include <SFML/Graphics.hpp>
#endif

#ifndef RES_PATH_INCLUDED
#define RES_PATH_INCLUDED
#include "ResourcePath.hpp"
#endif

#ifndef BRICK_INCLUDED
#define BRICK_INCLUDED
#include "Brick.cpp"
#endif

#ifndef SUPPORT_INCLUDED
#define SUPPORT_INCLUDED
#include "Support.cpp"
#endif

#ifndef BACKGROUND_INCLUDED
#define BACKGROUND_INCLUDED
#include "Background.cpp"
#endif

GraphicsManager::GraphicsManager(sf::RenderWindow* window_pointer):
window(window_pointer),
amount_of_game_objects(0)
{
    
}

void GraphicsManager::AddSprite(sf::Sprite *spr)
{
    Sprites[amount_of_game_objects++] = spr;
}

void GraphicsManager::DrawAllObjects()
{
    for (int i = 0; i < amount_of_game_objects; i++)
    {
        window->draw(*Sprites[i]);
    }
}

void GraphicsManager::AddSprite(GameObject* obj)
{
    Sprites[amount_of_game_objects++] = obj->GetSprite();
}


