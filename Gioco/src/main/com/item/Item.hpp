#ifndef Item_hpp
#define Item_hpp
#include <string>

class Item
{
public:
    Item(std::string name);
    std::string getName();

private:
    std::string name;
};

#endif
