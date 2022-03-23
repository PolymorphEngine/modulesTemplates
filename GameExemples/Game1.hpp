/*
** EPITECH PROJECT, 2022
** archi
** File description:
** Game1
*/

#include "../IGameModule.hpp"
#include "../Module Wrappers/IAudioModule.hpp"
#include "../Module Wrappers/ISpriteModule.hpp"
#include "../Module Wrappers/ITextModule.hpp"
#include "../Module Wrappers/IDisplayModule.hpp"

namespace arcade {
    class Game1 : arcade::IGameModule
    {
        Game1()
        {
            void *(*createDisplay)();//dlsym stuff
            display = (arcade::IDisplayModule *)createDisplay();
        }

        int run()
        {
            void *(*createSprite)();//dlsym stuff
            void *(*createText)();//dlsym stuff

            arcade::ITextModule *Score = (arcade::ITextModule *)createText();
            arcade::ISpriteModule *Player = (arcade::ISpriteModule *)createSprite();
            arcade::ISpriteModule *Ennemy = (arcade::ISpriteModule *)createSprite();

            // Some Game data initialisation
            // settings sprites sources / positions / text fonts or some other shits :p

            while (display->isOpen())
            {
                display->clearWindow(); // clears the window

                display->fetchInputs(); // fetches events



                // Arcade idea to switch to next/previous game
                if (display->isKeyPressed(arcade::KeyCode::Right))
                    return 1;
                if (display->isKeyPressed(arcade::KeyCode::Left))
                    return -1;
                ////////////////////////////////////////////////////



                // Some Game Logic update
                if (display->isKeyPressed(arcade::KeyCode::Z))
                    Player->move(0, 1);
                if (display->isKeyPressed(arcade::KeyCode::S))
                    Player->move(0, -1);
                if (display->isKeyPressed(arcade::KeyCode::Q))
                    Player->move(-1, 0);
                if (display->isKeyPressed(arcade::KeyCode::D))
                    Player->move(1, 0);
                //////////////////////////////////////////////////

                // Some game logic draw
                display->draw(Score);
                display->draw(Player);
                display->draw(Ennemy);
                //////////////////////////////////////////////////

                display->displayWindow();

            }
            return 0;
        }
        IDisplayModule *display;
    };
}