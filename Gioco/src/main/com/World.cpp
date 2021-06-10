#include "World.hpp"
#include "entity\\Enemy.hpp"
#include "tile\\Rock.hpp"
#include <iostream>
#include "Game.hpp"
#include "room\\MapGenerator.hpp"

World::World() : deathTextBox(100, 100, 350.f, 250.f), winTextBox(100, 100, 350.f, 250.f) {
    //load a font to pass to other class
    if (!font.loadFromFile("..\\resources\\fonts\\ArialUnicodeMS.ttf")) {
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
    counter = 0;  //debugging
    healthBar.setMaxHealth(70);
    healthBar.setBar(sf::Vector2f(200.f, 30.f));

    inventory.setTable(4, 3);
    inventory.setPosition(100.f, 20.f);
    inventory.setFont(font);

    itemTexture.loadFromFile("..\\resources\\textures\\item\\gun.png");
    item = Item("abaco", "gun");
    item.setPosition(50.f, 100.f);
    inventory.addItem(item);
    inventory.addItem(item);
    inventory.addItem(Item("paolo", "idk"));
    inventory.addItem(item);
    inventory.addItem(item);
}

void World::generateWorld() {
    //Add Player to world
    player = new Player();
    player->setPosition(200, 150);
    entities.push_back(player);
    //Add n[1-4] enemy to world
    int numEnemy = 1; //Game::getRandInt(1, 4);
    std::cout << "Adding " << numEnemy << " enemy\n";
    for (int i = 0; i < numEnemy; i++) {
        Enemy *enemy = new Enemy();
        float x = Game::getRandInt(0, Game::width);
        float y = Game::getRandInt(0, Game::height);
        std::cout << "Adding Enemy to " << x << "," << y << "\n";
        enemy->setPosition(x, y);
        entities.push_back(enemy);
    }
    //Tile Injection
    this->tiles = MapGenerator::generateRoom(7);
}

void World::tick() {
    if (end) {
        return;
    }
    if (!player->isAlive() || entities.size() == 1) {
        end = true;
        return;
    }

    for (Entity *entity : entities) {
        entity->tick();
        if (!entity->isAlive())
        {
            entities.remove(entity);
        }
        //TODO Check if Can move
    }

    checkCollision();
    this->healthBar.setHealthStat(player->getHealth(), player->getMaxHealth());
}

void World::checkPositions()
{
    for (Entity *entity : entities)
    {
        for (Tile *t : tiles)
        {
            if (!t->isSolid())
            {
                continue;
            }
            bool collide = entity->getTextureBox().getBounds().intersects(t->getTextureBox().getBounds());
            if (collide)
            {
                entity->onHit(*t);
                entity->resetPosition();
            }
        }
    }
}

void World::checkCollision()
{
    //Check Entities Collision with another one
    for (Entity *entity : entities)
    {
        for (Entity *e : entities)
        {
            bool collide = entity->getTextureBox().getBounds().intersects(e->getTextureBox().getBounds());
            if (collide)
            {
                entity->onHit(*e);
            }
        }
    }
    this->checkPositions();
}

void World::display(sf::RenderWindow &window) {
    // debugging
    if (++counter % 240 == 0) {
        counter = 0;
    }

    else if (counter % 120 == 0) {
    }
    // end debugging section
    // menu.makeMenu();
    //window.draw(menu);
    if (end) {
        if (player->isAlive()) {
            winTextBox.typewriter();
            window.draw(winTextBox);
        } else {
            deathTextBox.typewriter();
            window.draw(deathTextBox);
        }
        return;
    }
    //Render Entities and Tiles
    for (Tile *tile : tiles)
    {
        window.draw(*tile);
    }
    for (Entity *entity : entities)
    {
        window.draw(*entity);
    }
    //Render GUI
    window.draw(healthBar);
    // window.draw(inventory);
    // window.draw(item);
}

void World::addEntity(Entity &entity) {
    if (entities.size() == entities.max_size() - 1) {
        std::cout << "Too Much Entity!\n";
        return;
    }
    entities.push_back(&entity);
}