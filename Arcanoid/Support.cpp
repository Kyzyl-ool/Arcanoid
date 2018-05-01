//
//  Support.cpp
//  Arcanoid
//
//  Created by Кежик Кызыл-оол on 01.05.2018.
//  Copyright © 2018 Кежик Кызыл-оол. All rights reserved.
//

#ifndef SFML_G
#define SFML_G
#include <SFML/Graphics.hpp>
#endif

class abstract_support
{
private:
    int x, y;   //coordinates
    int length;
    int height;
    sf::Sprite sprite;
    

public:
    abstract_support();
    ~abstract_support();
};

class Common_Support: public abstract_support
{
    
};
