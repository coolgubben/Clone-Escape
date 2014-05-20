//
//  Player3.cpp
//  Clone Escape
//
//  Created by Erik Stoltenberg on 2014-05-13.
//  Copyright (c) 2014 Erik Stoltenberg. All rights reserved.
//

#include "Player3.h"

Player3::Player3(sf::Texture& texture){
    spritePlayer.setTexture(texture);
    spritePlayer.setTextureRect(sf::IntRect(634, 214, 160, 436));
    spritePlayer.setScale(0.2, 0.2);
    spritePlayer.setOrigin(160 * spritePlayer.getScale().x / 2, 436 * spritePlayer.getScale().y / 2);
    spritePlayer.setPosition(200, 200);
    touching = 1;
    walk = 0;
    frames = 0;
    direction = 0;
    spriteX = 634;
    spriteY = 214;
    canWalk = true;
    
    
    array [0] = 1034;
    array [1] = 1624;
    array [2] = 2220;
    array [3] = 2790;
    
}