#include "World.hpp"
#include "entity\\Enemy.hpp"
#include "tile\\Rock.hpp"
#include <iostream>
#include "Game.hpp"

World::World() : deathTextBox(100, 100, 350.f, 250.f), winTextBox(100, 100, 350.f, 250.f)
{
    //load a font to pass to other class
    if (!font.loadFromFile("..\\resources\\fonts\\ArialUnicodeMS.ttf"))
    {
        // TODO create exception class
        throw 2;
    }
    generateWorld();
    //TextBox Element
    deathTextBox.setString("DEFEAT");
    deathTextBox.setCharTime(300);
    deathTextBox.setFont(font);
    winTextBox.setString("WIN");
    winTextBox.setCharTime(500);
    winTextBox.setFont(font);

    sf::String temp[] = {"porcaporca", "porca", "porca", "porcaporca", "porca", "porca", "porca"};
    menu.setVoices(temp, 7);
    menu.setPosition(100.f, 200.f);
    menu.setDimension(400, 400);
    menu.setDisposition(3, 2);
    menu.setSelectedVoiceSize(24);
    menu.setSelectedVoiceColor(sf::Color::Red);
    menu.selectVoice(2);
    menu.setFont(font);

    end = false;
    healthBar.setPosition(10.f, 10.f);
    healthBar.setFont(font);
    counter = 0; //debugging
    healthBar.setMaxHealth(70);
    healthBar.setBar(sf::Vector2f(200.f, 30.f));
}

void World::generateWorld()
{
    //Add Player to world
    player = new Player();
    player->setPosition(300, 100);
    entities.push_back(player);
    //Add n[1-4] enemy to world
    int numEnemy = Game::getRandInt(1, 4);
    std::cout << "Adding " << numEnemy << " enemy\n";
    for (int i = 0; i < numEnemy; i++)
    {
        Enemy *enemy = new Enemy();
        float x = Game::getRandInt(0, Game::width);
        float y = Game::getRandInt(0, Game::height);
        std::cout << "Adding Enemy to " << x << "," << y << "\n";
        enemy->setPosition(x, y);
        entities.push_back(enemy);
    }
    //Tile Injection
    std::cout << "Adding 10 Rock\n";
    for (int i = 0; i < 10; i++)
    {
        Rock *rock = new Rock();
        float x = Game::getRandInt(0, Game::width);
        float y = Game::getRandInt(0, Game::height);
        std::cout << "Adding Rock to " << x << "," << y << "\n";
        rock->setPosition(x, y);
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
        if (!canMove(*entity, entity->getPosition().x, entity->getPosition().y, entity->getWidth(), entity->getHeight()))
        {
            entity->setPosition(entity->getOldPosition().x, entity->getOldPosition().y);
        }
    }
    //TODO Add Entity to block, and iter only those who has one

    checkCollision();
    this->healthBar.setHealthStat(player->getHealth(), player->getMaxHealth());
}

//Check if an entity e can move to (x, y)
bool World::canMove(Entity &e, float x, float y, float width, float height)
{
    for (Tile *tile : tiles)
    {
        float x1 = tile->getPosition().x;
        float y1 = tile->getPosition().y;
        float width1 = tile->getWidth();
        float height1 = tile->getHeight();
        if (collideRect(x, y, width, height, x1, y1, width1, height1) && tile->isSolid())
        {
            e.onHit(*tile);
            if (tile->isBreakableTo(e))
            {
                tile->onBreak(e);
            }
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
                entity->onHit(*e);
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
    float x1 = e1.getPosition().x;
    float y1 = e1.getPosition().y;
    float width1 = e1.getWidth();
    float height1 = e1.getHeight();

    float x2 = e2.getPosition().x;
    float y2 = e2.getPosition().y;
    float width2 = e2.getWidth();
    float height2 = e2.getHeight();

    return collideRect(x1, y1, width1, height1, x2, y2, width2, height2);
}

void World::display(sf::RenderWindow &window)
{
    // debugging
    if (++counter % 240 == 0)
    {

        counter = 0;
    }

    else if (counter % 120 == 0)
    {
    }
    // end debugging section
    //menu.makeMenu();
    //window.draw(menu);
    if (end)
    {
        if (player->isAlive())
        {
            winTextBox.typewriter();
            window.draw(winTextBox);
        }
        else
        {
            deathTextBox.typewriter();
            window.draw(deathTextBox);
        }
        return;
    }
    //Render Entities and Tiles
    
    for (Entity *entity : entities)
    {
        window.draw(*entity);
    }
    for (Tile *tile : tiles)
    {
        window.draw(*tile);
    }
    //Render GUI
    window.draw(healthBar);
}

void World::addEntity(Entity &entity)
{
    if (entities.size() == entities.max_size() - 1)
    {
        std::cout << "Too Much Entity!\n";
        return;
    }
    entities.push_back(&entity);
}