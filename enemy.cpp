#include "enemy.h"

Enemy::Enemy()
{

}

void Enemy::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(this->_enemyEntity,states);
}

void Enemy::spawn()
{
    this->_enemyEntity.setPointCount(3);
    this->_enemyEntity.setPoint(0, sf::Vector2f(0, 0));
    this->_enemyEntity.setPoint(1, sf::Vector2f(0, 10));
    this->_enemyEntity.setPoint(2, sf::Vector2f(25, 5));
    this->_enemyEntity.setOutlineColor(sf::Color::Red);
    this->_enemyEntity.setOutlineThickness(5);
    this->_enemyEntity.setPosition(10, 20);
}

