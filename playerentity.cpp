#include "playerentity.h"

PlayerEntity::PlayerEntity()
{
    this->_player.setPosition(200,200);
    this->_player.setRadius(25);
    this->_player.setFillColor(sf::Color(255,0,0));
    this->_player.setOrigin(this->_player.getGlobalBounds().width / 2,this->_player.getGlobalBounds().height / 2);
    oldRad = 25;
}

void PlayerEntity::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(this->_player,states);
}

void PlayerEntity::tick(sf::RenderWindow &window)
{

    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        oldRad = this->_player.getRadius();
        this->shrinkMe();
    }else{
        this->growMe(oldRad);
    }
    this->_player.setPosition(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y);
}

sf::Vector2f PlayerEntity::getPos() const{
    return this->_player.getPosition();
}

void PlayerEntity::growMe()
{
    this->_player.setRadius(this->_player.getRadius() + 1);
}

void PlayerEntity::growMe(int ammount)
{
    this->_player.setRadius(ammount);
}

void PlayerEntity::shrinkMe()
{
    this->_player.setRadius(25);
}

bool PlayerEntity::shouldGrow() const{

    if(this->_player.getRadius() <= 80){

    return true;
    }
}



