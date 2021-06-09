#include "Item.hpp"
#include "../ResourceHandler.hpp"

Item::Item() : textureBox(sf::TriangleStrip, 4) {
}

//the constructors and other methods copy the string and not take the references so
//it's possible to pass immediatly the value without save it in a varia
Item::Item(std::string name) : textureBox(sf::TriangleStrip, 4) {
    this->name = name;
    setTexture(name);
}

Item::Item(std::string name, std::string fileName) : textureBox(sf::TriangleStrip, 4) {
    this->name = name;
    setTexture(fileName);
}

const std::string& Item::getName() {
    return name;
}

void Item::setTexture(std::string fileName) {
    this->texture = ResourceHandler::getOrCreate("item", fileName);
    int width = this->texture.getSize().x;
    int height = this->texture.getSize().y;
    //set the dimension
    textureBox[0].position = sf::Vector2f(0, 0);
    textureBox[1].position = sf::Vector2f(0, height);
    textureBox[2].position = sf::Vector2f(width, 0);
    textureBox[3].position = sf::Vector2f(width, height);
    //set the texture position
    textureBox[0].texCoords = sf::Vector2f(0, 0);
    textureBox[1].texCoords = sf::Vector2f(0, height);;
    textureBox[2].texCoords = sf::Vector2f(width, 0);
    textureBox[3].texCoords = sf::Vector2f(width, height);
}

sf::Texture Item::getTexture(){
    return texture;
}

const sf::Vector2f Item::getSize() {
    return sf::Vector2f(textureBox[3].position.x, textureBox[3].position.y);
}

void Item::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    states.texture = &texture;
    target.draw(textureBox, states);
}