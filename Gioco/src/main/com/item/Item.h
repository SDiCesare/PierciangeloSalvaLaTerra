#ifndef Item_h
#define Item_h
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
