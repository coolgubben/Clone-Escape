//
//  Character.h
//  Clone Escape
//
//  Created by Erik Stoltenberg on 2014-01-08.
//  Copyright (c) 2014 Erik Stoltenberg. All rights reserved.
//

#ifndef __Clone_Escape__Character__
#define __Clone_Escape__Character__

#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "collision.h"

// Here is a small helper for you ! Have a look.
#include "ResourcePath.hpp"

class Character{

public:

    //Character(sf::Texture& texture);
    
    void move();
    
    void move2();
    
    void checkCollision(sf::Sprite sprite);
    
    void checkCollision2(sf::Sprite sprite);
    
    sf::Sprite getPlayer();
    
    void walkCycle();
    
    void updateDT();
    
    void setcanWalk(int x);
    bool getcanWalk();
    
    int getSpeedY();
    int getSpeedX();
    
    bool isColliding(sf::Sprite sprite);
    
    

protected:
    
    sf::Vector2f speed;
    bool direction;  // 0 = right, 1 = left
    bool touching;
    const float gravity = 980.f;
    sf::RectangleShape player;
    sf::Sprite spritePlayer;
    sf::Clock frametime;
    int frames;
    int walk;
    int walkX;
    int walkY;
    int spriteX;
    int spriteY;
    int CHARACTERSWITDH;
    int CHARATCTERHEIGHT;
    int array [4];
    bool canWalk;
    // Get delta time for frame-rate depended movement
    float dt;
    
    
};

#endif /* defined(__Clone_Escape__Character__) */
