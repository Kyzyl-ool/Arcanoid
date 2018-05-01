//
//  Background.cpp
//  Arcanoid
//
//  Created by Кежик Кызыл-оол on 01.05.2018.
//  Copyright © 2018 Кежик Кызыл-оол. All rights reserved.
//

#include <SFML/Graphics.hpp>
#include <string>

typedef enum background_types
{
    BACKGROUND_DEFAULT = 0,
    
}background_type;



class Background
{
private:
    sf::Texture texture;
    sf::Sprite sprite;
    
public:
    Background();
    ~Background();
    
    void load_texture(std::string texture_file);
    void set_sprite();
};

Background::Background()
{
    
}

Background::~Background()
{
    
}

void Background::load_texture(std::string texture_file)
{

}

void Background::set_sprite()
{

}







int background_coordinate_x(background_type number)
{
    return 1;
}

int background_coordinate_y(background_type number)
{
    return 2;
}

