#include "playerentity.h"

PlayerEntity::PlayerEntity()
{
    this->_player.setPosition(200,200);
    this->_player.setFillColor(sf::Color(255,0,0));
    this->_player.setScale(100,100);
}

void PlayerEntity::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(this->_player,states);
}

