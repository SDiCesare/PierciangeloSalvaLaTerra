#include "Game.hpp"
#include <stdlib.h>
#include <time.h>
#include "entity\\Enemy.hpp"
#include "room\\MapGenerator.hpp"
#include "HUD/HealthBarNum.hpp"
#include "HUD/Inventory.hpp"
#include "item/Item.hpp"

Game::Game() : window(sf::Vector2f(0, 0))
{
    srand(time(NULL));
    //load a font to pass to other class
    if (!font.loadFromFile("..\\resources\\fonts\\ArialUnicodeMS.ttf"))
    {
        // TODO create exception class
        throw 2;
    }
    this->generateWorld();
    //For Debugging
    counter = 0;

    //create health bar
    HealthBarNum *healthBar = new HealthBarNum();
    healthBar->setPosition(10.f, 10.f);
    healthBar->setFont(font);
    healthBar->setMaxHealth(70);
    healthBar->setBar(sf::Vector2f(200.f, 30.f));
    hud.push_back(healthBar);

    //create inventory
    Inventory *inventory = new Inventory();
    inventory->setTable(4, 3);
    inventory->setPosition(100.f, 20.f);
    inventory->setFont(font);
    Item item = Item("abaco", "gun");
    item.setPosition(50.f, 100.f);
    inventory->addItem(item);
    inventory->addItem(item);
    inventory->addItem(Item("paolo", "idk"));
    inventory->addItem(item);
    inventory->addItem(item);
    hud.push_back(inventory);
}

void Game::generateWorld()
{
    //Add Player to world
    player = new Player();
    player->setPosition(200, 150);
    entities.push_back(player);
    //Add n[1-4] enemy to world
    int numEnemy = 1; //Game::getRandInt(1, 4);
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
    this->tiles = MapGenerator::generateRoom(7);
}

void Game::run()
{
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        processInput();
        tick();
        draw();
    }
}

void Game::tick()
{
    for (Entity *entity : entities)
    {
        entity->tick();
        if (!entity->isAlive())
        {
            entities.remove(entity);
        }
    }
    this->checkPositions();
    this->checkCollision();
}

void Game::checkPositions()
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

void Game::checkCollision()
{
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
}

void Game::draw()
{
    if (++counter % 240 == 0)
    {
        counter = 0;
    }
    else if (counter % 120 == 0)
    {
    }
    this->window.clear();
    this->window.moveGameView(player->getPosition());
    this->window.drawWorld(this->entities, this->tiles);
    this->window.drawHUD(this->hud);
    this->window.display();
}

void Game::processInput()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
    {
        Projectile *projectile = this->player->shoot();
        if (projectile != NULL)
        {
            this->addEntity(*projectile);
        }
    }
    //TODO Check Movement
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        this->player->move(-3, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        this->player->move(3, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        this->player->move(0, -3);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        this->player->move(0, 3);
    }
}

void Game::addEntity(Entity &entity)
{
    if (entities.size() == entities.max_size() - 1)
    {
        std::cout << "Too Much Entity!\n";
        return;
    }
    entities.push_back(&entity);
}

int Game::getRandInt(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}

float Game::getRandFloat()
{
    return static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
}