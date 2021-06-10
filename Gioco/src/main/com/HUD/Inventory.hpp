#ifndef Inventory_hpp
#define Inventory_hpp
#include <SFML/Graphics.hpp>

#include "../item/Item.hpp"

/**
 * Struct that contains an item and unsigned number representing the quantity of item
 */
struct InvItem {
    InvItem(Item i, size_t q){
        item = i;
        quantity = q;
    }
    InvItem(){}
    Item item;
    size_t quantity = 0;
};

/**
 * @class Inventory
 * Class for keep items in a inventory and display them on screen in SFML
 */
class Inventory : public sf::Transformable, public sf::Drawable {
   public:

   /**
    * @brief Default constructor
    * 
    * Set icon size to 80, for correct operation is needed to call setTable and
    * setFont methods
    */
    Inventory();

    /**
     * @brief Construct a invetory of the specified size
     * 
     * @param columns The number of inventory columns
     * @param rows The number of inventory rows
     * @param font The font with which the number of quantity will be displayed
     */
    Inventory(size_t columns, size_t rows, const sf::Font& font);

    /**
     * @brief Return the pointer of the selected item
     * 
     * @param x the X coordinate of the item in the inventory
     * @param y the Y coordinate of the item in the inventory
     * 
     * @return The struct InvItem containing the item and the quantity
     */
    InvItem* getItem(size_t x, size_t y);

    /**
     * @brief Remove the item and order the inventory
     * 
     * @param x the X coordinate of the item in the inventory
     * @param y the Y coordinate of the item in the inventory
     */
    void removeItem(size_t x, size_t y);

    /**
     * @brief Use the item
     * 
     * It will decrase its quantity and if it reaches 0 it will be removed
     * @param x the X coordinate of the item in the inventory
     * @param y the Y coordinate of the item in the inventory
     */
    void useItem(size_t x, size_t y);

    /**
     * @brief Set the size of inventory
     * 
     * If the size was alredy set it will delete all items in inventory and
     * it will change its size
     * 
     * @param columns The number of inventory columns
     * @param rows The number of inventory rows
     */
    void setTable(size_t columns, size_t rows);

    /**
     * @brief Set the font with which the number of item quantity will be displayed
     * 
     * @param font The font to use
     */
    void setFont(const sf::Font& font);

    /**
     * @brief Set the icons size
     * 
     * The default value is 80
     * 
     * @param size The icons size
     */
    void setSizeIcons(size_t size);

    /**
     * @brief Add Item in the inventory
     * 
     * If item is not present in the inventory it will try to add at the first free space
     * in the invetory, in case the inventory is full it will not add the item and will
     * return false
     * 
     * @param item The item to add in the inventory
     * @return If the item was added
     */
    bool addItem(Item item);
    virtual ~Inventory();

   private:
    size_t c;
    size_t r;
    InvItem** items;
    sf::Font font;
    size_t size;
    size_t maxSize;
    float sizeIcons;

    //necessary to avoid problem in cleaning memory
    bool hasBeenInitialize = false;
    InvItem* getItemConst(size_t row, size_t col) const;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void rmItem(size_t idx, InvItem* itemPtrIdx=NULL);
};

#endif