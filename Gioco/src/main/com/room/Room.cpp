#include "Room.hpp"
#include "..\\ResourceHandler.hpp"

Room::Room(std::string fileRoom, Element e) : element(e)
{
    std::string room = ResourceHandler::getOrCreateRoom(fileRoom);
    this->load(room);
    this->tileSheet = ResourceHandler::getOrCreate("tile\\tileset", e.getName());
}

void Room::load(std::string room)
{
    std::cout << "Room Load\n";
    std::string size = room.substr(0, room.find("\n"));
    this->width = std::stoi(size.substr(0, size.find("x")));
    this->height = std::stoi(size.substr(size.find("x") + 1, size.length()));
    std::string matrixText = room.substr(room.find("\n") + 1, room.length());
    this->tiles = (int **)std::malloc(width * sizeof(int *));
    for (int i = 0; i < this->width; i++)
    {
        std::string line = matrixText.substr(0, matrixText.find("\n"));
        this->tiles[i] = (int *)std::malloc(height * sizeof(int));
        for (int j = 0; j < this->height; j++)
        {
            int index = line.find(",");
            int var = std::stoi(line.substr(0, index));
            this->tiles[i][j] = var;
            line = line.substr(index + 1, line.length());
        }
        matrixText = matrixText.substr(matrixText.find("\n") + 1, matrixText.length());
    }
}

void Room::print()
{
    std::cout << "==================\n";
    std::cout << width << " x " << height << "\n";
    for (int i = 0; i < this->width; i++)
    {
        for (int j = 0; j < this->height; j++)
        {
            std::cout << this->tiles[i][j] << ",";
        }
        std::cout << "\n";
    }
    std::cout << "==================\n";
}

void Room::makeEntrance(int index)
{
    switch (index)
    {
    case 0:
    {
        this->tiles[0][this->height / 2 - 1] = 0;
        this->tiles[0][this->height / 2] = 0;
        break;
    }
    case 1:
    {
        this->tiles[this->width / 2][this->height - 1] = 0;
        this->tiles[this->width / 2 + 1][this->height - 1] = 0;
        break;
    }
    case 2:
    {
        this->tiles[this->width - 1][this->height / 2 - 1] = 0;
        this->tiles[this->width - 1][this->height / 2] = 0;
        break;
    }
    case 3:
    {
        this->tiles[this->width / 2 - 1][0] = 0;
        this->tiles[this->width / 2][0] = 0;
        break;
    }
    }
}

Tile *Room::getTileFromValue(int index)
{
    return new Tile("null");
}

int **Room::getTiles()
{
    return this->tiles;
}

int Room::getWidth()
{
    return this->width;
}

int Room::getHeight()
{
    return this->height;
}