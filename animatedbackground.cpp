#include "animatedbackground.h"
#include <time.h>
AnimatedBackground::AnimatedBackground()
{
    srand(time(NULL));
    int lastX = 0;
    int lastY = 0;
    for(int i = 0; i < 8; i++){

        for(int i = 0; i < 8;i++){
           const int r = rand() % 255 + 1;
           const int g = rand() % 255 + 1;
           const int b = rand() % 255 + 1;
           this->_squares.push_back(std::unique_ptr<sf::RectangleShape>(new sf::RectangleShape()));
           this->_squares.back()->setSize(sf::Vector2f(100,100));
           this->_squares.back()->setPosition(lastX,lastY);
           this->_squares.back()->setFillColor(sf::Color(r,g,b));
           lastX += 100;
       }
        lastY += 100;
        lastX = 0;

    }


}

void AnimatedBackground::draw(sf::RenderTarget &target, sf::RenderStates states) const
{

    for(auto const& block : this->_squares){
    target.draw(*block,states);
    }
}

void AnimatedBackground::tick()
{
    srand(time(NULL));

    for(auto &block : this->_squares){
        const int r = rand() % 255 + 1;
        const int g = rand() % 255 + 1;
        const int b = rand() % 255 + 1;
        block->setFillColor(sf::Color(r,g,b));
    }
}

