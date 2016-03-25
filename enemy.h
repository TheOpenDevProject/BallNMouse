#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Graphics.hpp>

class Enemy : public sf::Drawable
{
public:
    Enemy();
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    void spawn();
protected:
    sf::ConvexShape _enemyEntity;
};

#endif // ENEMY_H
