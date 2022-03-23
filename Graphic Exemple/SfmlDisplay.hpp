/*
** EPITECH PROJECT, 2022
** archi
** File description:
** SfmlDisplay
*/

#include "../Module Wrappers/IDisplayModule.hpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <map>
#include <SFML/Graphics/Sprite.hpp>

namespace arcade {

class SfmlDisplay : arcade::IDisplayModule
{
    //PROPERTIES:
        public:
            sf::RenderWindow *window;
            std::map<KeyCode, bool> pressedKeys;


            //LOGIC:
            SfmlDisplay()
            {
                window = new sf::RenderWindow();

                for (int i = 0; i < KeyCount; i++)
                    pressedKeys[static_cast<KeyCode>(i)];
            }

            void setResolution(unsigned int x, unsigned int y) override
            {
                window->setSize((sf::Vector2u){x, y});
            }

            void setWindowTitle(std::string title)
            {
                window->setTitle(title);
            }

            bool isOpen() override
            {
                return window->isOpen();
            }

            void clearWindow() override
            {
                window->clear(sf::Color::Black);
            }
            
            void displayWindow() override
            {
                window->display();
            }

            bool isTextMode()
            {
                return false;
            }
            //////////////////////////////////////////
        
        
        
        
            //INPUT:
            void fetchInputs()
            {
                
                // Mouse Input            
                pressedKeys[arcade::KeyCode::MouseButton1] = sf::Mouse::isButtonPressed(sf::Mouse::Left);
                pressedKeys[arcade::KeyCode::MouseButton2] = sf::Mouse::isButtonPressed(sf::Mouse::Middle);
                pressedKeys[arcade::KeyCode::MouseButton3] = sf::Mouse::isButtonPressed(sf::Mouse::Right);
                
                // keyboard inputs
                for (int i = 0; i < arcade::KeyCount; ++i)
                    pressedKeys[(arcade::KeyCode)i] = sf::Keyboard::isKeyPressed((sf::Keyboard::Key)i);
                
                //(bind with smfl sf::Key for keyboard and sf::Button for mouse)
                //TODO: need to see if binding is the same for sdl and others
            }
            bool isKeyPressed(arcade::KeyCode key)
            {
                return pressedKeys[key];
            }
            unsigned int getMouseXPosition() override 
            {
                return sf::Mouse::getPosition().x;
            }

            unsigned int getMouseYPosition() override 
            {
                return sf::Mouse::getPosition().y;
            }
            //////////////////////////////////////////
            // DRAW LOGIC:
            void draw(arcade::ISpriteModule *spriteModule) override
            {
                sf::Sprite *temp((sf::Sprite *)spriteModule->getSprite());
                window->draw(*temp);
            }
    };
}