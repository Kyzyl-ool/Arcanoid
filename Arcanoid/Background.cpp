//
//  Background.cpp
//  Arcanoid
//
//  Created by Кежик Кызыл-оол on 01.05.2018.
//  Copyright © 2018 Кежик Кызыл-оол. All rights reserved.
//

#include "GameObject.cpp"

#ifndef SFML_G
#define SFML_G
#include <SFML/Graphics.hpp>
#endif


#include <string>


typedef enum background_types
{
    BACKGROUND_DEFAULT = 0,
    
}background_type;



class Background: public GameObject
{
private:
    background_type type;

public:
    Background(background_type the_type);
    ~Background();
};

int get_background_coord_x(background_type the_type)
{
    return 0;
}

int get_background_coord_y(background_type the_type)
{
    return 0;
}

Background::Background(background_type the_type)
{
    type = the_type;
    texture.loadFromFile("backgrounds.png");
    sprite.setTexture(texture);
    sprite.setPosition(get_background_coord_x(type), get_background_coord_y(type));
}

Background::~Background()
{
    
}
