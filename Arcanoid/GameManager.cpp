#define AMOUNT_OF_GAME_OBJECTS 10

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

class GameManager
{
private:
    sf::RenderWindow* window;
    sf::Sprite* Sprites[AMOUNT_OF_GAME_OBJECTS];
    int amount_of_game_objects;
    
    
public:
    GameManager(sf::RenderWindow* window_pointer);
    //    ~GameManager();
    
    void AddSprite(sf::Sprite* spr);
    void AddSprite(GameObject* obj);
    void DrawAllObjects();
};

GameManager::GameManager(sf::RenderWindow* window_pointer):
window(window_pointer),
amount_of_game_objects(0)
{
    
}

void GameManager::AddSprite(sf::Sprite *spr)
{
    Sprites[amount_of_game_objects++] = spr;
}

void GameManager::DrawAllObjects()
{
    for (int i = 0; i < amount_of_game_objects; i++)
    {
        window->draw(*Sprites[i]);
    }
}

void GameManager::AddSprite(GameObject* obj)
{
    Sprites[amount_of_game_objects++] = obj->GetSprite();
}

