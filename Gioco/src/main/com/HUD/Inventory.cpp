#include "Inventory.hpp"

#include <algorithm>
#include <iostream>

Inventory::Inventory() {
    sizeIcons = 80.f;
}

Inventory::Inventory(size_t columns, size_t rows, sf::Font& font) {
    maxSize = rows * columns;
    c = columns;
    r = rows;
    //create new pointers array
    items = new InvItem*[rows * columns];

    //set for each pointer a Item instance
    for (int i = 0; i < columns * rows; i++) {
        items[i] = new InvItem();
    }

    
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
    maxSize = rows * columns;
    if (hasBeenInitialize) {
        //remove all associated objects to the pointers
        for (int i = 0; i < c * r; i++) {
            delete items[i];
        }

        //remove the pointers array
        delete[] items;
    }

    //create new pointers array
    items = new InvItem*[maxSize];

    //set for each pointer a Item instance
    for (int i = 0; i < columns * rows; i++) {
        items[i] = new InvItem();
    }
    c = columns;
    r = rows;
    size = 0;
    hasBeenInitialize = true;
    
}

bool Inventory::addItem(Item item) {
    //if inventory is full return false
    if (size >= c * r)
        return false;

    //check if already exist
    for (size_t i = 0; i < maxSize; i++)
    {
        InvItem* itemPtr = *(items+i);
        if(!itemPtr->item.getName().compare(item.getName())){
            itemPtr->quantity++;
            return true;
        }
    }
    

    //get the longest size of item
    sf::Vector2f itemBounds = item.getSize();
    float max;
    if (itemBounds.y > itemBounds.x)
        max = itemBounds.y;
    else
        max = itemBounds.x;

    //scale item in order to get the longest size as long as sizeIcons
    float toScale = sizeIcons / max;
    item.setScale(toScale, toScale);

    //set the position in the invetory drawing
    float sizeX = static_cast<float>(size % c);
    float sizeY = static_cast<float>(size / c);
    item.setPosition(sizeX * sizeIcons, sizeY * sizeIcons);

    //set the item in the array and set quantity to 1
    InvItem* itemPtr = *(items + size);
    itemPtr->item = item;
    itemPtr->quantity = 1;
    size++;
    return true;
}

void Inventory::useItem(size_t x, size_t y) {
     size_t idx = x + y * c;

    if (idx >= size)
        return;

    InvItem* itemPtrIdx = *(items + idx);
    itemPtrIdx->quantity--;
    //if quantity reached 0 remove the item from inventory
    if(itemPtrIdx->quantity > 0)
        return;
    
    rmItem(idx, itemPtrIdx);
}

void Inventory::removeItem(size_t x, size_t y) {
    size_t idx = x + y * c;

    if (idx >= size)
        return;

    InvItem* itemPtrIdx = *(items + idx);
    itemPtrIdx->quantity=0;
    rmItem(idx, itemPtrIdx);
    
}

void Inventory::rmItem(size_t idx, InvItem* itemPtrIdx){
    if(itemPtrIdx == NULL){
        itemPtrIdx = *(items + idx);
    }
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

    delete[] items;
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
