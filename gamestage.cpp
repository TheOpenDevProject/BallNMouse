#include "gamestage.h"
#include "playerentity.h"
#include "enemyspawner.h"
GameStage::GameStage(): gameWindow(new sf::RenderWindow(sf::VideoMode(800,800),"WTF!",sf::Style::Default,renderWindowSettings))
{

    gameWindow->setMouseCursorVisible(false);

}

void GameStage::startGame() const{
    PlayerEntity player;
    EnemySpawner spawner;
    EnemySpawner spawner_2;
    sf::Clock updateStage;
    sf::Clock spawnRate;
    sf::Clock spawnRate_2;
    sf::Clock playerPulseTimer;
    //Player Cant Enter This Zone
    sf::RectangleShape noEntryZone;
    noEntryZone.setSize(sf::Vector2f(300,300));
    noEntryZone.setOutlineColor(sf::Color::Green);
    noEntryZone.setOutlineThickness(3);
    noEntryZone.setPosition(400,400);
    noEntryZone.setOrigin(150,150);
    while(this->gameWindow->isOpen()){
        sf::Event event;
        while(this->gameWindow->pollEvent(event)){
            if(event.type == sf::Event::Closed){
                return;
            }
        }

        //New Enemy Spawn Rate

        if(spawnRate.getElapsedTime().asMilliseconds() >= 1000){
            spawner.createEnemy();

            spawnRate.restart();

        }

        if(spawnRate.getElapsedTime().asMilliseconds() >= 2000){
            spawner_2.createEnemy();
            spawnRate_2.restart();

        }
        //Update frame
        if(updateStage.getElapsedTime().asMilliseconds() >= 10){
            spawner.tick();
            spawner_2.tick();
            noEntryZone.rotate(10);
            updateStage.restart();
        }


        //Update frame
        if(playerPulseTimer.getElapsedTime().asMilliseconds() >= 1000){
            if(player.shouldGrow()){
                player.growMe();
            }

            playerPulseTimer.restart();
        }


        //Draw the game
        this->gameWindow->clear();
        player.tick(*this->gameWindow.get());
        this->gameWindow->draw(noEntryZone);
        this->gameWindow->draw(player);
        this->gameWindow->draw(spawner);
         this->gameWindow->draw(spawner_2);
        this->gameWindow->display();
    }
}
