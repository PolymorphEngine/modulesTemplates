/*
** EPITECH PROJECT, 2022
** archi
** File description:
** SfmlSprite
*/

#include "../Module Wrappers/ISpriteModule.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

namespace arcade {
    class SflmSprite : arcade::ISpriteModule
    {
        //PROPERTIES:
        public:
            sf::Sprite *sprite;
            sf::Texture *texture;
    
    
    
            // LOGIC
    
            SflmSprite()
            {
                texture = new sf::Texture();
                sprite = new sf::Sprite();
            }
    
            void *getSprite() override
            {
                return sprite;
            }
    
            void setSprite(std::string filePath) override
            {
                texture->loadFromFile(filePath);
    
                sprite->setTexture(*texture);
            }
    
            void setPosition(float x, float y) override
            {
                sprite->setPosition((sf::Vector2f){x, y});
            }
    
            void setCrop(int x, int y, int width, int height) override
            {
                sprite->setTextureRect((sf::IntRect){x, y, width, height});
            }
    };
}