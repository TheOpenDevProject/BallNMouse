#include "collisionengine.h"

CollisionEngine::CollisionEngine()
{

}

bool CollisionEngine::hasCollision(std::vector<std::unique_ptr<sf::Shape> > &cEnemies, PlayerEntity &player)
{
    for(auto const& c_enemy : cEnemies){

    }
}

float CollisionEngine::findDotProduct(sf::Vector2f &v1, sf::Vector2f &v2)
{
    //This gives us the dot product of two vectors. A Scalar VALUE!!
    float dProduct = v1.x * v2.x + v1.y * v2.y;
    return dProduct;
}

sf::Vector2f CollisionEngine::findProjectionVector(sf::Vector2f &vec)
{
    //Thanks to some dude on SFML for showing me his code
    //This is an implementation of the following math
    // proj(u->V) = ( u . v / ||v||^2) x v

    return vec / std::sqrt(findDotProduct(vec, vec));
}

