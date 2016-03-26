#ifndef GAMESTAGE_H
#define GAMESTAGE_H
#include <SFML/Graphics.hpp>
#include <memory>
class GameStage
{
public:
    GameStage();
    void startGame() const;
    void handleEvents() const;
private:
    std::unique_ptr<sf::RenderWindow> gameWindow;
    sf::ContextSettings renderWindowSettings;
};

#endif // GAMESTAGE_H
