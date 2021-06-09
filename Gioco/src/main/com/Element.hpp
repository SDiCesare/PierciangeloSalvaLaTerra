#ifndef Element_hpp
#define Element_hpp

#include <vector>
#include <string>

class Element
{

public:
    static Element FIRE;
    static Element WATER;
    static Element GRASS;

public:
    Element(std::string name, int id, std::vector<int> weak, std::vector<int> strong);
    std::string getName();

protected:
    std::string name;
    int id;
    std::vector<int> weak;
    std::vector<int> strong;

public:
    float damageMultiplierOn(Element e);
};

#endif