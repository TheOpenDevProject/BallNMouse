#ifndef COLLISIONENGINE_H
#define COLLISIONENGINE_H
#include <SFML/Graphics.hpp>
#include "playerentity.h"
class CollisionEngine
{
public:
    CollisionEngine();
    bool hasCollision(std::vector<std::unique_ptr<sf::Shape>> &cEnemies,PlayerEntity &player);
private:
    float findDotProduct(sf::Vector2f &v1, sf::Vector2f &v2);
    sf::Vector2f findProjectionVector(sf::Vector2f &vec);
};

#endif // COLLISIONENGINE_H
