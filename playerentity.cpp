#include "playerentity.h"

PlayerEntity::PlayerEntity()
{
    this->_player.setPosition(200,200);
    this->_player.setRadius(50);
    this->_player.setFillColor(sf::Color(255,0,0));
    this->_player.setOrigin(this->_player.getGlobalBounds().width / 2,this->_player.getGlobalBounds().height / 2);
}

void PlayerEntity::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(this->_player,states);
}

void PlayerEntity::tick(sf::RenderWindow &window)
{

    this->_player.setPosition(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y);
}

