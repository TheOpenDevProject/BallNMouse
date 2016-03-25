#include "gamestage.h"
#include "playerentity.h"
#include "enemyspawner.h"
GameStage::GameStage(): gameWindow(new sf::RenderWindow(sf::VideoMode(800,800),"WTF!",sf::Style::Default,renderWindowSettings))
{
    renderWindowSettings.antialiasingLevel = 8;
    gameWindow->setMouseCursorVisible(false);
    gameWindow->setFramerateLimit(60);
}

void GameStage::startGame() const{
    PlayerEntity player;
    EnemySpawner spwaner;

    while(this->gameWindow->isOpen()){
        sf::Event event;
        while(this->gameWindow->pollEvent(event)){
            if(event.type == sf::Event::Closed){
                return;
            }
        }

        //Draw the game
        this->gameWindow->clear();
        player.tick(*this->gameWindow.get());
        this->gameWindow->draw(player);
        this->gameWindow->draw(spwaner);
        this->gameWindow->display();
    }
}
