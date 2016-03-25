#include "enemyspawner.h"

EnemySpawner::EnemySpawner()
{


}

void EnemySpawner::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    for(auto const& cEnemy : this->_enemies){
        target.draw(*cEnemy);
    }
}

void EnemySpawner::tick()
{

    for(auto &cEnemy : this->_enemies){
        cEnemy->tick();
    }
}

void EnemySpawner::createEnemy()
{
    this->_enemies.push_back(std::unique_ptr<Enemy>(new Enemy));
    this->_enemies.back()->spawn(rand() % 500 + 10,rand() % 500 + 10);
}

void EnemySpawner::destoryEnemy()
{

}

