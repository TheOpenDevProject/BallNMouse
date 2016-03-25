#include "enemyspawner.h"

EnemySpawner::EnemySpawner()
{
    this->_enemies.push_back(std::unique_ptr<Enemy>(new Enemy()));
}

void EnemySpawner::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    for(auto const& cEnemy : this->_enemies){
        target.draw(*cEnemy);
    }
}

void EnemySpawner::tick()
{

}

