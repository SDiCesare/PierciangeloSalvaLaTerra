#ifndef Item_hpp
#define Item_hpp
#include <string>

class Item
{
public:
    /**
     * @brief The constructor of the Class Item
     * 
     * @param name The rapresentative name of the Item
     * */
    Item(std::string name);

    /**
     * @return The name of the Item
     * */
    std::string getName();

private:
    std::string name;
};

#endif
