#define AMOUNT_OF_GAME_OBJECTS 10
#define GAME_SLOWLESS 80000

#ifndef SFML_A
#define SFML_A
#include <SFML/Audio.hpp>
#endif

#ifndef SFML_G
#define SFML_G
#include <SFML/Graphics.hpp>
#endif

#include "ResourcePath.hpp"

#include "Brick.cpp"
#include "Support.cpp"
#include "Background.cpp"

float dt;
sf::Clock clocks;


class GraphicsManager
{
private:
    sf::RenderWindow* window;
    sf::Sprite* Sprites[AMOUNT_OF_GAME_OBJECTS];
    int amount_of_game_objects;
    
    
public:
    GraphicsManager(sf::RenderWindow* window_pointer);
    //    ~GraphicsManager();
    
    void AddSprite(sf::Sprite* spr);
    void AddSprite(GameObject* obj);
    void DrawAllObjects();
};



class PhysicsManager
{
private:
    GameObject* gameobjects[AMOUNT_OF_GAME_OBJECTS];
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
    dt = clocks.getElapsedTime().asMicroseconds();
    clocks.restart();
    dt /= GAME_SLOWLESS;
    dt = 0.1;
    
//    std::cout << "dt = " << dt << std::endl;
    for (int i = 0; i < amount_of_game_objects; i++)
    {
        gameobjects[i]->update(dt);
    }
}












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

