#include "Inventory.hpp"

#include <algorithm>
#include <iostream>

Inventory::Inventory() {
    sizeIcons = 80.f;
}

Inventory::Inventory(size_t columns, size_t rows, sf::Font& font) {
    items = new InvItem*[rows * columns];
    for (int i = 0; i < columns * rows; i++) {
        items[i] = new InvItem();
    }
    c = columns;
    r = rows;
    this->font = font;
    size = 0;
    hasBeenInitialize = true;
    sizeIcons = 80.f;
}

InvItem* Inventory::getItem(size_t x, size_t y) {
    if (x >= c || y >= r)
        //TODO create exception
        throw(2);

    return *(items + x + r * y);
}

InvItem* Inventory::getItemConst(size_t row, size_t col) const {
    if (col >= c || row >= r)
        //TODO create exception
        throw(2);

    return *(items + col + row * c);
}

void Inventory::setFont(sf::Font& font) {
    this->font = font;
}

void Inventory::setSizeIcons(size_t size){
    sizeIcons = size;
}

void Inventory::setTable(size_t columns, size_t rows) {
    if (hasBeenInitialize) {
        for (int i = 0; i < c * r; i++) {
            delete items[i];
        }
    }

    items = new InvItem*[rows * columns];
    for (int i = 0; i < columns * rows; i++) {
        items[i] = new InvItem();
    }
    c = columns;
    r = rows;
    size = 0;
    hasBeenInitialize = true;
}

bool Inventory::addItem(Item item) {
    if (size >= c * r)
        return false;

    sf::Vector2f itemBounds = item.getSize();
    float max;
    if (itemBounds.y > itemBounds.x)
        max = itemBounds.y;
    else
        max = itemBounds.x;

    float toScale = sizeIcons / max;
    item.setScale(toScale, toScale);
    float sizeX = static_cast<float>(size % c);
    float sizeY = static_cast<float>(size / c);

    item.setPosition(sizeX * sizeIcons, sizeY * sizeIcons);
    InvItem* itemPtr = *(items + size);
    itemPtr->item = item;
    itemPtr->quantity = 1;
    size++;
    return true;
}

void Inventory::removeItem(size_t x, size_t y) {
    size_t idx = x + y * c;

    if (idx >= size)
        return;

    InvItem* itemPtrIdx = *(items + idx);
    itemPtrIdx->quantity = 0;
    itemPtrIdx->item = Item();

    if (size != idx) {
        std::rotate(items + idx, items + idx + 1, items + size);

        for (size_t i = idx; i < size - idx; i++) {
            int row = i / c;
            int column = i % c;
            InvItem* itemPtr = *(items + i);
            itemPtr->item.setPosition(static_cast<float>(column) * sizeIcons, static_cast<float>(row) * sizeIcons);
        }
    }
    size--;

    //set last element as default (that will be seen as empty slot by program)
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
            position.x = static_cast<float>(j) * sizeIcons;
            position.y = static_cast<float>(i) * sizeIcons;

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
    for (int i = 0; i < c * r; i++) {
        delete items[i];
    }
}

/*
void Inventory::removeItem(size_t x, size_t y) {
    size_t idx = x + y * c;

    if (idx > size)
        return;

    if (idx < size)
        std::copy(items + idx + 1, items + size, items + idx);
    
    (items + idx)->quantity = 0;
    (items + idx)->item = Item();
}
*/
