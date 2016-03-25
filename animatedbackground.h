#ifndef ANIMATEDBACKGROUND_H
#define ANIMATEDBACKGROUND_H
#include <SFML/Graphics.hpp>

class AnimatedBackground : public sf::Drawable
{
public:
    AnimatedBackground();
     virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    void tick();
private:
    std::vector<std::unique_ptr<sf::RectangleShape>> _squares;
};

#endif // ANIMATEDBACKGROUND_H
