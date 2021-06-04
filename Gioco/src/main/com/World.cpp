#include "World.h"
#include "entity\\Enemy.h"
#include "tile\\Rock.h"
#include "tile\\Floor.h"
#include <iostream>
#include "Game.h"

World::World() : deathTextBox(100, 100, 350.f, 250.f), winTextBox(100, 100, 350.f, 250.f)
{
    generateWorld();
    //TextBox Element
    deathTextBox.setString("DEFEAT");
    deathTextBox.setCharTime(0.3f * 1000.f);
    winTextBox.setString("WIN");
    winTextBox.setCharTime(0.5f * 1000.f);
    
    sf::String temp[] = {"porcaporca", "porca", "porca", "porcaporca", "porca", "porca", "porca"};
    menu.setVoices(temp, 7);
    menu.setPosition(40.f, 40.f);
    menu.setDimension(400, 400);
    menu.setDisposition(3, 2);
    menu.setSelectedVoiceSize(24);
    menu.setSelectedVoiceColor(sf::Color::Red);
    winTextBox.setCharTime(0.3f * 1000.f);
    end = false;
    healthBar.setPosition(10.f, 10.f);
    counter = 0; //debugging
    healthBar.setMaxHealth(70);
    healthBar.setBar(sf::Vector2f(200.f, 30.f));
}

void World::generateWorld()
{
    //Add Player to world
    player = new Player(this);
    player->setPos(sf::Vector2f(300, 100));
    entities.push_back(player);
    //Add n[1-4] enemy to world
    int numEnemy = Game::getRandInt(1, 4);
    for (int i = 0; i < numEnemy; i++)
    {
        Enemy *enemy = new Enemy(this);
        float x = Game::getRandInt(0, Game::width);
        float y = Game::getRandInt(0, Game::height);
        std::cout << "Adding Enemy to " << x << "," << y << "\n";
        enemy->setPos(x, y);
        entities.push_back(enemy);
    }
    //Tile Injection
    for (int i = 0; i < Game::width / 16; i++)
    {
        for (int j = 0; j < Game::height / 16; j++)
        {
            Floor *floor = new Floor();
            floor->setPos(i * 16, j * 16);
            tiles.push_back(floor);
        }
    }
    for (int i = 0; i < 10; i++)
    {
        Rock *rock = new Rock();
        float x = Game::getRandInt(0, Game::width);
        float y = Game::getRandInt(0, Game::height);
        std::cout << "Adding Rock to " << x << "," << y << "\n";
        rock->setPos(x, y);
        tiles.push_back(rock);
    }
}

void World::tick()
{
    if (end)
    {
        return;
    }
    if (!player->isAlive() || entities.size() == 1)
    {
        end = true;
        return;
    }

    for (Entity *entity : entities)
    {
        entity->tick();
    }
    //TODO Add Entity to block, and iter only those who has one

    checkCollision();
}

//Check if an entity e can move to (x, y)
bool World::canMove(Entity *e, float x, float y, float width, float height)
{
    for (Tile *tile : tiles)
    {
        sf::Sprite sprite = tile->getSprite();
        float x1 = tile->getPos().x;
        float y1 = tile->getPos().y;
        float width1 = sprite.getTextureRect().width;
        float height1 = sprite.getTextureRect().height;
        if (collideRect(x, y, width, height, x1, y1, width1, height1) && !tile->isAir())
        {
            e->onHit(tile);
            return false;
        }
    }
    return true;
}

void World::checkCollision()
{
    for (Entity *entity : entities)
    {
        for (Entity *e : entities)
        {
            if (e != entity && isHitted(*entity, *e))
            {
                entity->onHit(e);
            }
        }
        if (!entity->isAlive())
        {
            entities.remove(entity);
            std::cout << "Removing Entity!\n";
        }
    }
}

bool World::collideRect(float x1, float y1, float width1, float height1, float x2, float y2, float width2, float height2)
{
    if (x1 < x2 + width2 && x1 + width1 > x2 && y1 < y2 + height2 && y1 + height1 > y2)
    {
        return true;
    }

    return false;
}

bool World::isHitted(Entity e1, Entity e2)
{
    float x1 = e1.getPos().x;
    float y1 = e1.getPos().y;
    float width1 = e1.getWidth();
    float height1 = e1.getHeight();

    float x2 = e2.getPos().x;
    float y2 = e2.getPos().y;
    float width2 = e2.getWidth();
    float height2 = e2.getHeight();

    return collideRect(x1, y1, width1, height1, x2, y2, width2, height2);
}

void World::display(sf::RenderWindow &window)
{
    // debugging
    if(++counter % 240 == 0){
        
        counter = 0;
    }else if(counter% 120 == 0){
    }
    // end debugging section
    
    window.draw(menu.getSprite());
    if (end)
    {
        if (player->isAlive())
        {
            window.draw(winTextBox.typewriter());
        }
        else
        {
            window.draw(deathTextBox.typewriter());
        }
        return;
    }
    for (Tile *tile : tiles)
    {
        window.draw(tile->getSprite());
    }
    for (Entity *entity : entities)
    {
        window.draw(entity->getSprite());
    }
    window.draw(healthBar);
}

void World::addEntity(Entity *entity)
{
    if (entities.size() == entities.max_size() - 1)
    {
        std::cout << "Finito Spazio!\n";
        return;
    }
    entities.push_back(entity);
}