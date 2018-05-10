//
//  PhysicsManager.cpp
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

const float dt = 0.01;
//sf::Clock clocks;

class PhysicsManager
{
private:
    GameObject* gameobjects[AMOUNT_OF_GAME_OBJECTS] = {nullptr};
    int amount_of_game_objects;
    
public:
    PhysicsManager();
    
    void AddGameObject(GameObject* obj);
    void UpdateAllObjects();
};

PhysicsManager::PhysicsManager():
amount_of_game_objects(0)
{
    
}

void PhysicsManager::AddGameObject(GameObject* obj)
{
    gameobjects[amount_of_game_objects++] = obj;
}

void PhysicsManager::UpdateAllObjects()
{
    //    dt = clocks.getElapsedTime().asMicroseconds();
    //    clocks.restart();
    //    dt /= GAME_SLOWLESS;
    
    //    std::cout << "dt = " << dt << std::endl;
    
    
    for (int i = 0; i < amount_of_game_objects; i++)
        for (int j = i + 1; j < amount_of_game_objects; j++)
        {
            if (gameobjects[i]->collideCheck(gameobjects[j]))
            {
                gameobjects[i]->collideResponse(gameobjects[j]);
            }
        }
    for (int i = 0; i < amount_of_game_objects; i++)
    {
        gameobjects[i]->update(dt);
    }
    
}
