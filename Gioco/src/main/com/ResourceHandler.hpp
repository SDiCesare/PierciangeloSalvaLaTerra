#ifndef ResourceHandler_hpp
#define ResourceHandler_hpp

#include <SFML\\Graphics.hpp>
#include <iostream>
#include <string>
#include <map>
#include <fstream>

class ResourceHandler
{
public:
    static std::vector<std::string> TEXTURES_LOCATION;
    static std::vector<sf::Texture> TEXTURES;
    static std::vector<std::string> ROOM_LOCATIONS;
    static std::vector<std::string> ROOMS;
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
    static sf::Texture &getOrCreate(std::string textureDir, std::string textureName)
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
            return TEXTURES[TEXTURES.size() - 1];
        }
        else
        {
            return DEFAULT_TEXTURE;
        }
    }

    static std::string getOrCreateRoom(std::string roomName)
    {
        std::string path = "..\\resources\\room\\" + roomName + ".txt";
        int size = ROOM_LOCATIONS.size();
        for (int i = 0; i < size; i++)
        {
            std::string room = ROOM_LOCATIONS[i];
            if (room == path)
            {
                //Find Room
                return ROOMS[i];
            }
        }
        std::ifstream file;
        file.open(path);
        if (file.is_open())
        {
            std::string fileText = "";
            std::string line = "";
            while (std::getline(file, line))
            {
                fileText += line + "\n";
            }
            ROOM_LOCATIONS.push_back(path);
            ROOMS.push_back(fileText);
            return fileText;
        }
        else
        {
            std::cout << "Can't Load Room " + roomName + "\n";
            return NULL;
        }
    }
};
#endif