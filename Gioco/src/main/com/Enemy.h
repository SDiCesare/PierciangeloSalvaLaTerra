#include "Entity.hpp"

class Enemy : public Entity
{
public:
    Enemy();
    void tick() override;
};