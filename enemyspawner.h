#ifndef ENEMYSPAWNER_H
#define ENEMYSPAWNER_H
#include <SFML/Graphics.hpp>
#include "enemy.h"
class EnemySpawner : public sf::Drawable
{
public:
    EnemySpawner();
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    void tick();

private:
    std::vector<std::unique_ptr<Enemy>> _enemies;
};

#endif // ENEMYSPAWNER_H
