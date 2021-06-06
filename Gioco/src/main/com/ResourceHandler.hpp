#ifndef ResourceHandler_hpp
#define ResourceHandler_hpp

#include <SFML\\Graphics.hpp>
#include <iostream>
#include <string>
#include <map>

class ResourceHandler
{
public:
    static std::vector<std::string> TEXTURES_LOCATION;
    static std::vector<sf::Texture> TEXTURES;
    static sf::Texture DEFAULT_TEXTURE;

    /**
     * @brief Loads the default resources used in case of missing one
     * */
    static void loadDefault()
    {
        if (DEFAULT_TEXTURE.loadFromFile("..\\resources\\textures\\default.png"))
        {
            std::cout << "Loaded Default Texture\n";
        }
    }

    /**
     * @brief Loads a Texture presents in vector TEXTURES.
     *        If the Texture is not present in the vector, It try to load from the resources path.
     * 
     * @param textureDir The Texture Specific Directory
     * @param textureName The Texture Name without the extension
     * 
     * @return The specified texture of the path if exists, the DEFAULT texture otherwise
     * */
    static sf::Texture getOrCreate(std::string textureDir, std::string textureName)
    {
        std::string texturePath = "..\\resources\\textures\\" + textureDir + "\\" + textureName + ".png";
        int size = TEXTURES_LOCATION.size();
        for (int i = 0; i < size; i++)
        {
            std::string texture = TEXTURES_LOCATION[i];
            if (texture == texturePath)
            {
                //Find Texture
                return TEXTURES[i];
            }
        }
        //Load and Add texture
        sf::Texture texture = sf::Texture();
        if (texture.loadFromFile(texturePath))
        {
            TEXTURES.push_back(texture);
            TEXTURES_LOCATION.push_back(texturePath);
            return texture;
        }
        else
        {
            std::cout << "Can't find or load texture: " << texturePath << "\n";
            return DEFAULT_TEXTURE;
        }
    }
};
#endif