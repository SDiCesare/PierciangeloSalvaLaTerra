#include "Entity.hpp"
#include <SFML/Graphics.hpp>

class World{
    public:
        Entity *entity;
        void tick();
        void setup();
        void display(sf::RenderWindow *window);

};