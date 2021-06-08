#include "Inventory.hpp"

#include <algorithm>
#include <iostream>

Inventory::Inventory() {
    sizeIcon = 80.f;
}

Inventory::Inventory(size_t columns, size_t rows, sf::Font& font) {
    items = new InvItem[rows * columns];
    c = columns;
    r = rows;
    this->font = font;
    size = 0;
    hasBeenInitialize = true;
    sizeIcon = 80.f;
}

InvItem* Inventory::getItem(size_t x, size_t y) {
    if (x >= c || y >= r)
        //TODO create exception
        throw(2);

    return items + x + r * y;
}

InvItem* Inventory::getItemConst(size_t row, size_t col) const {
    if (col >= c || row >= r)
        //TODO create exception
        throw(2);

    return items + col + row * c;
}

void Inventory::setFont(sf::Font& font) {
    this->font = font;
}

void Inventory::setTable(size_t columns, size_t rows) {
    if (hasBeenInitialize)
        delete[] items;
    items = new InvItem[rows * columns];
    c = columns;
    r = rows;
    size = 0;
    hasBeenInitialize = true;
}

bool Inventory::addItem(Item item) {
    if (size >= c * r - 1)
        return false;

    sf::Vector2f itemBounds = item.getSize();
    float max;
    if (itemBounds.y > itemBounds.x)
        max = itemBounds.y;
    else
        max = itemBounds.x;

    float toScale = sizeIcon / max;
    item.setScale(toScale, toScale);
    float sizeX = static_cast<float>(size % c);
    float sizeY = static_cast<float>(size / c);

    item.setPosition(sizeX * sizeIcon, sizeY * sizeIcon);
    (items + size)->item = item;
    (items + size)->quantity = 1;
    size++;
    return true;
}

void Inventory::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    sf::Text invNum;
    sf::Vector2f position;
    invNum.setFont(font);
    invNum.setCharacterSize(20);
    // invNum.setOutlineColor(sf::Color::Black);
    invNum.setOutlineThickness(4.f);
    invNum.setPosition(0.f, 0.f);
    for (size_t i = 0; i < r; i++) {
        for (size_t j = 0; j < c; j++) {
            position.x = static_cast<float>(j) * sizeIcon;
            position.y = static_cast<float>(i) * sizeIcon;

            InvItem* invItem = getItemConst(i, j);
            if (invItem->quantity == 0) {
                invNum.setString("EMPTY");
                invNum.setPosition(position.x + 4.f, position.y);
            } else {
                target.draw(invItem->item, states);

                invNum.setString(std::to_string(invItem->quantity));
                invNum.setPosition(position.x + 4.f, position.y);
            }

            target.draw(invNum, states);
        }
    }
}

Inventory::~Inventory() {
    delete[] items;
}
