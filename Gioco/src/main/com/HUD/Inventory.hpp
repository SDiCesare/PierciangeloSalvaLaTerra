#ifndef Inventory_hpp
#define Inventory_hpp
#include <SFML/Graphics.hpp>

#include "../item/Item.hpp"

struct InvItem {
    InvItem(Item i, size_t q){
        item = i;
        quantity = q;
    }
    InvItem(){}
    Item item;
    size_t quantity = 0;
};

class Inventory : public sf::Transformable, public sf::Drawable {
   public:
    Inventory();
    Inventory(size_t rows, size_t columns, sf::Font& font);
    InvItem* getItem(size_t row, size_t col);
    void setTable(size_t rows, size_t columns);
    void setFont(sf::Font& font);
    bool addItem(Item item);
    virtual ~Inventory();

   private:
    size_t c;
    size_t r;
    InvItem* items;
    sf::Font font;
    size_t size;
    float sizeIcon;
    bool hasBeenInitialize = false;
    InvItem* getItemConst(size_t row, size_t col) const;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif