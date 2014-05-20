//
// Disclamer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resource, use the helper
// method resourcePath() from ResourcePath.hpp
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

// Here is a small helper for you ! Have a look.
#include "ResourcePath.hpp"
#include "player.h"
#include "collision.h"
#include "Player.h"
#include "Player2.h"
#include "Player3.h"
#include <sstream>

using namespace std;
using namespace Collision;

int main(int, char const**)
{
    // Create the main window
    
    
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    sf::RenderWindow window2(sf::VideoMode(200, 800), "DeBug");
    
    window.setKeyRepeatEnabled(false);
    
    window2.setPosition(sf::Vector2i(0, 0));

    // Limit frame-rate
    window.setFramerateLimit(60);
    
    
    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile(resourcePath() + "Character_Shorty.png")) {
        return EXIT_FAILURE;
    }
    
    sf::Texture texture2;
    if (!texture2.loadFromFile(resourcePath() + "MainMain.png")) {
        return EXIT_FAILURE;
    }
    
    sf::Texture textureSlender;
    if (!textureSlender.loadFromFile(resourcePath() + "LongnSlendeFrasTestMattiasskabajsapådenhär.png")) {
        return EXIT_FAILURE;
    }
    
    
    sf::Font font;
    if (!font.loadFromFile(resourcePath() + "sansation.ttf")) {
        return EXIT_FAILURE;
    }
    
    //classes
    Player player(texture);
    Player2 player2(texture2);
    Player3 player3(textureSlender);
    
    //character lista
    vector<Character*> charlista;
    
    
        Player* c1=0;
        c1 = new Player(texture);
        if (c1){
            charlista.push_back(c1);
        }
        else {} // err

    
        
        Player2* c2=0;
        c2 = new Player2(texture2);
        if(c2) charlista.push_back(c2);
        else{} //err
        
    
        
        Player3* c3=0;
        c3 = new Player3(textureSlender);
        if(c3) charlista.push_back(c3);
        else{} //err
        
    
    vector<sf::Sprite> spriteLista;
    
    //en kartan
    sf::Texture texture1;
    if (!texture1.loadFromFile(resourcePath() + "LvL.1Meow.png")) {
        return EXIT_FAILURE;
    }
    sf::Sprite sprite;
    sprite.setTexture(texture1);
    
    spriteLista.push_back(sprite);
    
    //Bro
    sf::Texture bro;
    if (!bro.loadFromFile(resourcePath() + "Bro.png")) {
        return EXIT_FAILURE;
    }
    sf::Sprite sprite2;
    sprite2.setTexture(bro);
    sprite2.setOrigin(525, 435);
    sprite2.setPosition(525, 435);
    
    //kontrollrum
    sf::Texture kontrollRum;
    if (!kontrollRum.loadFromFile(resourcePath() + "KontrollRum.png")) {
        return EXIT_FAILURE;
    }
    sf::Sprite sprite3;
    sprite3.setTexture(kontrollRum);
    
    //framsidakontrollrum
    sf::Texture framsidaKontrollRum;
    if (!framsidaKontrollRum.loadFromFile(resourcePath() + "framsidaKontrollRum.png")) {
        return EXIT_FAILURE;
    }
    sf::Sprite sprite4;
    sprite4.setTexture(framsidaKontrollRum);
    
    sf::Texture dorrar;
    if (!dorrar.loadFromFile(resourcePath() + "dörrar.png")) {
        return EXIT_FAILURE;
    }
    sf::Sprite sprite5;
    sprite5.setTexture(dorrar);
    
    
    sf::Texture Kollision;
    if (!Kollision.loadFromFile(resourcePath() + "kollision_mark.png")) {
        return EXIT_FAILURE;
    }
    sf::Sprite markKollision;
    markKollision.setTexture(Kollision);
    
    markKollision.setPosition(0, -2);
    
    sf::Texture Tillbehor;
    if (!Tillbehor.loadFromFile(resourcePath() + "Tillbehor.png")) {
        return EXIT_FAILURE;
    }
    sf::Sprite spriteTillbehor;
    
    spriteTillbehor.setTexture(Tillbehor);
    
    sf::Texture El;
    if (!El.loadFromFile(resourcePath() + "El.png")) {
        return EXIT_FAILURE;
    }
    sf::Sprite spriteEl;
    spriteEl.setTexture(El);
    
    //if menu should be showing
    bool game = 0;
    
    static int counter;
    counter++;
    
    bool showing;
        
    while(window.isOpen())
    {
        // Event handling
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
            
        }
        
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
            window.close();
        }
        
        //Event for DeBug
        sf::Event event2;
        while(window2.pollEvent(event))
        {
            if(event2.type == sf::Event::Closed)
                window2.close();
            
        }
        
        if (event2.type == sf::Event::KeyPressed && event2.key.code == sf::Keyboard::Escape) {
            window2.close();
        }
        
        while(game){
            
            sf::Vector2i localPosition = sf::Mouse::getPosition(window);
            
            // Event handling
            sf::Event event;
            while(window.pollEvent(event))
            {
                if(event.type == sf::Event::Closed)
                    window.close();
            }
            
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
                break;
            }
            
            
            string apa = "Main menu \nPlay! \nQuit!";
            
            //håller musen över Play!
            if(localPosition.x >= 200 && localPosition.x <= 310 && localPosition.y >= 265 && localPosition.y <= 315){
                
                apa = "Main menu \nPlay!!!!!!!!!!! \nQuit!";
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                 
                    game = 0;
                    
                }
                
                
            }
            //håller musen över Quit!
            if(localPosition.x >= 200 && localPosition.x <= 310 && localPosition.y >= 315 && localPosition.y <= 375){
                
                apa = "Main menu \nPlay! \nQuit!!!!!!!!!";
                
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    
                    window.close();
                    game = 1;
                    
                }
                
            }
            
            
            sf::Text text(apa, font, 50);
            text.setPosition(200, 200);
            
            stringstream out;
            out << localPosition.x;
            stringstream out2;
            out2 << localPosition.y;
            apa = out.str() + ", " + out2.str();
            sf::Text text2(apa, font, 50);
            
            window.clear();
            window.draw(text);
            window.draw(text2);
            window.display();
            
            
        }
        
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)){
            
            for (int i=0; i <charlista.size() / 2; i++){
                
                if(charlista.at(i)->getcanWalk()){
                    
                    charlista.at(i)->setcanWalk(0);
                }
                else{
                    
                    charlista.at(i)->setcanWalk(1);
                }
            }
        }
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)){
            for (int i=5; i <10; i++){
                
            if(charlista.at(i)->getcanWalk()){
                
                charlista.at(i)->setcanWalk(0);
            }
            else{
                
                charlista.at(i)->setcanWalk(1);
            }
            }
            
        }
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
            sprite2.rotate(1);
        }
        
        //debug
        string apa;
        stringstream out;
        out << player.getPlayer().getPosition().y;
        apa = "Player position Y: " + out.str();
        out.str(string());
        
        out << player.getPlayer().getPosition().x;
        apa += "\nPlayer position X: " + out.str();
        out.str(string());
        
        out << player.getSpeedX();
        apa += "\nPlayer Speed X: " + out.str();
        out.str(string());
        
        out << player.getSpeedY();
        apa += "\nPlayer Speed Y: " + out.str();
        out.str(string());

        
        out << charlista.size();
        apa += "\nLISTA MAX SIZE!!!!!!: " + out.str();
        out.str(string());
        
        out << player2.getPlayer().getPosition().y;
        apa += "\nPlayer2 position Y: " + out.str();
        
        out << player2.getPlayer().getPosition().x;
        apa += "\nPlayer2 position X: " + out.str();
        out.str(string());
        
        out << player2.getSpeedX();
        apa += "\nPlayer2 Speed X: " + out.str();
        out.str(string());
        
        out << player2.getSpeedY();
        apa += "\nPlayer2 Speed Y: " + out.str();
        out.str(string());
        
        out << player2.getcanWalk();
        apa += "\nPlayer2 canWalk: " + out.str();
        out.str(string());
        
        
        
        sf::Text text(apa, font, 12);
        text.setColor(sf::Color::Black);
        
        
        //Updates
        
        for (int i=0; i <charlista.size(); i++){
         
            charlista.at(i)->updateDT();
            charlista.at(i)->checkCollision(markKollision);
            charlista.at(i)->checkCollision2(sprite);
            charlista.at(i)->checkCollision(sprite2);
            charlista.at(i)->checkCollision2(sprite3);
            if(charlista.at(i)->getcanWalk()){
                charlista.at(i)->move2();
            }
            charlista.at(i)->move();
            
            
        }
        
        
        
        
        player.updateDT();
        //karta
        player.checkCollision(markKollision);
        player.checkCollision2(sprite);
        //Bron
        player.checkCollision(sprite2);
        //kontrollrum
        player.checkCollision2(sprite3);
        if(player.getcanWalk()) {
        player.move2();
        }
        player.move();
        
        
        player2.updateDT();
        //karta
        player2.checkCollision(markKollision);
        player2.checkCollision2(sprite);
        //Bron
        player2.checkCollision(sprite2);
        
        player2.checkCollision2(sprite3);
        if(player2.getcanWalk()){
        player2.move2();
        }
        player2.move();
        
        // Render
        window.clear(sf::Color::White);
        
        window.draw(sprite);
        window.draw(markKollision);
        window.draw(sprite2);
        window.draw(sprite3);
        window.draw(sprite5);
        window.draw(spriteTillbehor);
        
        
        
        
        if(counter == 30){
            
            counter = 0;
            
            if(showing){
                
                showing = false;
                
            }
            
            else if(!showing){
                
                showing = true;
                
            }
            
            else{
                
                showing = true;
                
            }
        
            
        }
        if(showing){
        window.draw(spriteEl);
        }
        
        for (int i=0; i <charlista.size(); i++){
            
            window.draw(charlista.at(i)->getPlayer());
            
        }
        
        //window.draw(player.getPlayer());
        //window.draw(player2.getPlayer());
        
        window.draw(sprite4); //framsida av kontroll rum
         
      
        window.display();
        
        
        
        //render DeBug window
        window2.clear(sf::Color::White);
        
        window2.draw(text);
        
        window2.display();
    }
}
