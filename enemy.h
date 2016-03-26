#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Graphics.hpp>

class Enemy : public sf::Drawable
{
public:
    Enemy();
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    void spawn(int x, int y);
    void tick();

    sf::Vector2f getPos() const;
protected:
    sf::ConvexShape _enemyEntity;
    int xVal;
    int yVal;
};

#endif // ENEMY_H
