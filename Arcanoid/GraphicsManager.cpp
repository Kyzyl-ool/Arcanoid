//
//  GraphicsManager.cpp
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

#ifndef BALL_INCLUDED
#define BALL_INCLUDED
#include "Ball.cpp"
#endif

#include <cassert>

class GraphicsManager
{
private:
    sf::RenderWindow* window;
    GameObject* gameobjects[AMOUNT_OF_GAME_OBJECTS] = {nullptr};
    int amount_of_game_objects;
    
    
public:
    GraphicsManager(sf::RenderWindow* window_pointer);
    //    ~GraphicsManager();
    
    void AddGameObject(GameObject* obj);
    void DrawAllObjects();
};

GraphicsManager::GraphicsManager(sf::RenderWindow* window_pointer):
window(window_pointer),
amount_of_game_objects(0)
{
    
}

void GraphicsManager::DrawAllObjects()
{
    for (int i = 0; i < amount_of_game_objects; i++)
    {
        gameobjects[i]->draw(window);
    }
}

void GraphicsManager::AddGameObject(GameObject *obj)
{
    assert(amount_of_game_objects <= AMOUNT_OF_GAME_OBJECTS);
    gameobjects[amount_of_game_objects++] = obj;
}


