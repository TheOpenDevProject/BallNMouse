#ifndef PLAYERENTITY_H
#define PLAYERENTITY_H
#include <SFML/Graphics.hpp>

class PlayerEntity : public sf::Drawable
{
public:
    PlayerEntity();
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    void tick();
private:
    sf::Vector2f _playerPos;
    sf::CircleShape _player;
};

#endif // PLAYERENTITY_H
