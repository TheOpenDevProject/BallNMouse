#include "gamestage.h"
#include "playerentity.h"
#include "enemyspawner.h"
#include "animatedbackground.h"
GameStage::GameStage(): gameWindow(new sf::RenderWindow(sf::VideoMode(800,800),"WTF!",sf::Style::Default,renderWindowSettings))
{

    gameWindow->setMouseCursorVisible(false);

}

void GameStage::startGame() const{
    AnimatedBackground bg_background;

    PlayerEntity player;
    EnemySpawner spawner;
    EnemySpawner spawner_2;
    sf::Clock updateStage;
    sf::Clock spawnRate;
    sf::Clock spawnRate_2;
    sf::Clock playerPulseTimer;
    //Player Cant Enter This Zone
    sf::RectangleShape noEntryZone;
    sf::RectangleShape noEntryZone_innerShape;
    noEntryZone_innerShape.setSize(sf::Vector2f(150,150));
    noEntryZone_innerShape.setOutlineColor(sf::Color::Blue);
    noEntryZone_innerShape.setFillColor(sf::Color::Black);
    noEntryZone_innerShape.setOutlineThickness(3);
    noEntryZone_innerShape.setPosition(400,400);
    noEntryZone_innerShape.setOrigin(75,75);


    noEntryZone.setSize(sf::Vector2f(300,300));
    noEntryZone.setOutlineColor(sf::Color::Green);
    noEntryZone.setOutlineThickness(3);this->gameWindow->draw(noEntryZone);
    noEntryZone.setPosition(400,400);
    noEntryZone.setOrigin(150,150);
    while(this->gameWindow->isOpen()){
        this->handleEvents();
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
            noEntryZone_innerShape.rotate(-10);
            bg_background.tick();
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
        this->gameWindow->draw(bg_background);
        this->gameWindow->draw(player);
        this->gameWindow->draw(spawner);
        this->gameWindow->draw(spawner_2);
        this->gameWindow->draw(noEntryZone);
        this->gameWindow->draw(noEntryZone_innerShape);
        this->gameWindow->display();
    }
}

void GameStage::handleEvents() const
{
    sf::Event event;
    while(this->gameWindow->pollEvent(event)){
        if(event.type == sf::Event::Closed){
            this->gameWindow->close();
        }
    }
}
