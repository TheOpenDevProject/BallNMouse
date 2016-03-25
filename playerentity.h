#ifndef PLAYERENTITY_H
#define PLAYERENTITY_H
#include <SFML/Graphics.hpp>

class PlayerEntity : public sf::Drawable
{
public:
    PlayerEntity();
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    void tick(sf::RenderWindow &window);
    sf::Vector2f getPos() const;
    void growMe();
    void growMe(int ammount);
    void shrinkMe();

    bool shouldGrow() const;
private:
    sf::Vector2f _playerPos;
    sf::CircleShape _player;
    bool _shouldGrow;
    int oldRad;
};

#endif // PLAYERENTITY_H
