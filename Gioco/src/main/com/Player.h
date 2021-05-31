#include "Entity.hpp"

class Player : public Entity
{

public:
    Player();
    void tick();

private:
    sf::Vector2f speed;
};