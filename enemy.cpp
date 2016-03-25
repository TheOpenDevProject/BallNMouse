#include "enemy.h"
#include <time.h>
#include <stdlib.h>
Enemy::Enemy()
{

}

void Enemy::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(this->_enemyEntity,states);
}

void Enemy::spawn(int x,int y)
{
    srand(time(NULL));
    sf::Vector2f p1(rand() % 200 + 100,rand() % 200 + 100);
    sf::Vector2f p2(rand() % 200 + 100,rand() % 200 + 100);
    sf::Vector2f p3(rand() % 200 + 100,rand() % 200 + 100);
    int spwnDirection = rand() % 4;
    switch(spwnDirection)
    {
       case 0:
        this->xVal = 1;
        this->yVal = -1;
        break;

       case 1:
        this->xVal = -1;
        this->yVal = 1;
          break;

       case 2:
        this->xVal = -1;
        this->yVal = -1;
          break;

       case 3:
        this->xVal = 1;
        this->yVal = -1;
          break;
    }
    this->_enemyEntity.setPointCount(3);
    this->_enemyEntity.setPoint(0, p1);
    this->_enemyEntity.setPoint(1, p2);
    this->_enemyEntity.setPoint(2, p3);
    this->_enemyEntity.setOutlineThickness(0);
    this->_enemyEntity.setPosition(x + this->_enemyEntity.getScale().x,y + this->_enemyEntity.getScale().y);
}

void Enemy::tick()
{
    this->_enemyEntity.move(this->xVal,this->yVal);
}

sf::Vector2f Enemy::getPos() const{
    return this->_enemyEntity.getPosition();
}
