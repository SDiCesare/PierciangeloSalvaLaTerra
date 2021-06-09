#ifndef Item_hpp
#define Item_hpp
#include <SFML/Graphics.hpp>
#include <string>

class Item : public sf::Transformable, public sf::Drawable {
   public:
    Item();
    Item(std::string name);
    Item(std::string name, std::string fileName);
    void setName(std::string name);
    const std::string& getName();
    void setTexture(std::string fileName);
    sf::Texture getTexture();
    const sf::Vector2f getSize();

   private:
    sf::Texture texture;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    std::string name;
    sf::VertexArray textureBox;
};

#endif