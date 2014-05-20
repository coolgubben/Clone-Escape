//
//  Character.cpp
//  Clone Escape
//
//  Created by Erik Stoltenberg on 2014-01-08.
//  Copyright (c) 2014 Erik Stoltenberg. All rights reserved.
//

#include "Character.h"
#define MAXSPEED 100
#define CHARACTERSWITDH 200
#define CHARATCTERHEIGHT 500

using namespace Collision;
/*
Character::Character(sf::Texture& texture){
    spritePlayer.setTexture(texture);
    spritePlayer.setTextureRect(sf::IntRect(634, 214, 160, 436));
    //spritePlayer.setTextureRect(sf::IntRect(20, 10, 20, 40));
    spritePlayer.setScale(0.1, 0.1);
    spritePlayer.setOrigin(CHARACTERSWITDH * spritePlayer.getScale().x / 2, CHARATCTERHEIGHT * spritePlayer.getScale().y / 2);
    spritePlayer.setPosition(200.f, 40.f);
    //spritePlayer.setOrigin(20.f, 20.f);
    touching = false;
    walk = 0;
    frames = 0;
    direction = 0;
    
    
    array [0] = 1034;
    array [1] = 1624;
    array [2] = 2220;
    array [3] = 2790;
    
    
}
*/
sf::Sprite Character::getPlayer(){
    
    return spritePlayer;
    
}

void Character::checkCollision(sf::Sprite sprite){
    
    while(PixelPerfectTest(spritePlayer, sprite, 0)){
        
        //else{
        spritePlayer.setPosition(spritePlayer.getPosition().x, spritePlayer.getPosition().y-1);
        touching = 1;
        //}
    }
    
}

void Character::checkCollision2(sf::Sprite sprite){
    
    if(PixelPerfectTest(spritePlayer, sprite, 0)){
        
        
        if(speed.x < 0){
            
            spritePlayer.setPosition(spritePlayer.getPosition().x +10, spritePlayer.getPosition().y);
            
        }
        if(speed.x > 0){
            
            spritePlayer.setPosition(spritePlayer.getPosition().x -10, spritePlayer.getPosition().y);
            
        }
        
        speed.x *= -1;
        
    }
    
    
}

void Character::move2(){
    
    
    // Horizontal movement
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && touching){
        speed.x = 0.f;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && touching && speed.x >= -1 * MAXSPEED){
        speed.x += -30.f;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && touching && speed.x <= MAXSPEED){
        speed.x += 30.f;
    }
    // Jumping
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        if(touching){
            speed.y = -250.f;
            touching = false;
        }
        else{
            speed.y += -5.f;
        }
    }
    
}

void Character::move(){
    
    
    walkCycle();
    
    
    // Slow down horizontal speed
    if(speed.x > 0.f && touching){
        speed.x -= 6.f;
        if(speed.x < 0){
            speed.x = 0;
        }
    }
    else if(speed.x > 6.f){
        speed.x -= 1.f;
    }
    else if(speed.x < 0.f && touching){
        speed.x += 6.f;
        if(speed.x > 0){
            speed.x = 0;
        }
    }
    else if(speed.x < -3.f){
        speed.x += 1.f;
    }
    
    
    // Adjust vertical speed
    if(touching)
        speed.y = 0;
    else if(speed.y < gravity)
        speed.y += 10.f;
    else if(speed.y > gravity)
        speed.y = gravity;
    
    
    
    //så att inte charactären faller ut ur skärmen
    if(spritePlayer.getPosition().x <= 0 && speed.x < 0){
        
        speed.x = 0;
        spritePlayer.setPosition(0, spritePlayer.getPosition().y);
        
    }
    else if(spritePlayer.getPosition().x+20 >= 800 && speed.x > 0){
        
        speed.x = 0;
        spritePlayer.setPosition(800-20, spritePlayer.getPosition().y);
        
    }
    
    
    //för att characteren ska ramla ner
    if(speed.x != 0){
        
        touching = 0;
        
    }
    
    // Move the player
    spritePlayer.setPosition(spritePlayer.getPosition().x + speed.x * dt, spritePlayer.getPosition().y + speed.y * dt);
    
}

void Character::walkCycle(){
    
    if(speed.x == 0){
        
        walkX = spriteX;
        walkY = spriteY;
        walk = 0;
        
        spritePlayer.setTextureRect(sf::IntRect(walkX, walkY, CHARACTERSWITDH, CHARATCTERHEIGHT));
        
    }
    
    else if(speed.x > 0 && frames == 10){
                
        if(spritePlayer.getScale().x < 0){
            spritePlayer.setScale(-spritePlayer.getScale().x, spritePlayer.getScale().y);
        }
        
        if(direction == 1){
            spritePlayer.setPosition(spritePlayer.getPosition().x - spritePlayer.getScale().x * CHARACTERSWITDH, spritePlayer.getPosition().y);
        }

        
        spritePlayer.setOrigin(spritePlayer.getOrigin().x, spritePlayer.getOrigin().y);
        
        direction = 0;
        
        spritePlayer.setTextureRect(sf::IntRect(array [walk], walkY, 250, 436));
        walk++;
        if(walk == 4){
            walk = 0;
            if(walkY == 1000){
                walkY = spriteY;
            }
            else{
                walkY = spriteY+800;
            }
        }
        
        
    }
    
    else if(speed.x < 0 && frames == 10){
        if(direction == 0){
        spritePlayer.setPosition(spritePlayer.getPosition().x + spritePlayer.getScale().x * CHARACTERSWITDH, spritePlayer.getPosition().y);
        }
        if(spritePlayer.getScale().x > 0){
        spritePlayer.setScale(-spritePlayer.getScale().x, spritePlayer.getScale().y);
        }
        direction = 1;
        
        spritePlayer.setTextureRect(sf::IntRect(array [walk], walkY, 250, 436));
        walk++;
        if(walk == 4){
            walk = 0;
            if(walkY == 1000){
                walkY = 214;
            }
            else{
                walkY = 1000;
            }
        }
        
        
    }
}

void Character::setcanWalk(int x){
    
    canWalk = x;
    
}

bool Character::getcanWalk(){
    
    return canWalk;
}



void Character::updateDT(){
    
    dt = frametime.restart().asSeconds();
    
    if(frames == 10){
        frames *= 0;
    }
    frames++;
    
}

int Character::getSpeedY(){
    
    return speed.y;
    
}

int Character::getSpeedX(){
    
    return speed.x;
    
}


bool Character::isColliding(sf::Sprite sprite){
    
    if(PixelPerfectTest(spritePlayer, sprite, 0)){
        
        return 1;
        
    }
    
    return 0;
    
}




