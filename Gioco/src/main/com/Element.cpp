#include "Element.hpp"

Element Element::FIRE = Element("fire", 0, std::vector<int>(1, 0), std::vector<int>(2));
Element Element::WATER = Element("water", 1, std::vector<int>(2, 1), std::vector<int>(0));
Element Element::GRASS = Element("nature", 2, std::vector<int>(0, 2), std::vector<int>(1));

Element::Element(std::string name, int id, std::vector<int> weak, std::vector<int> strong)
{
    this->name = name;
    this->id = id;
    this->weak = weak;
    this->strong = strong;
}

float Element::damageMultiplierOn(Element e)
{
    for (int i = 0; i < this->weak.size(); i++)
    {
        if (this->weak[i] == e.id)
        {
            return 0.5f;
        }
    }
    for (int i = 0; i < this->strong.size(); i++)
    {
        if (this->strong[i] == e.id)
        {
            return 1.5f;
        }
    }
    return 1.f;
}

std::string Element::getName()
{
    return this->name;
}