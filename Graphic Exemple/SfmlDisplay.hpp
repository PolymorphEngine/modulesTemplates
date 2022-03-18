class SfmlDisplay : IDisplayModule
{
    //PROPERTIES:
    sf::window *window;
    std::map<KeyCode, bool> pressedKeys;


    //LOGIC:
    SfmlDisplay()
    {
        window = new sf::Window();

        for (int i = 0; i < KeyCount; i++)
            pressedKeys[i] = false;
    }



        // WINDOW:
        void setResolution(int x, int y) override
        {
            window.setSize(x, y);
        }

        void setWindowTitle(string title)
        {
            window.setTitle(title);
        }
        // etc ...


        bool isOpen() override
        {
            return window.isOpen();
        }

        void clearWindow() override
        {
            window.clear(sf::Black);
        }
        
        void displayWindow() override
        {
            window.display();
        }


        // Window type:
        LibType getType()
        {
            return SFML;
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
            pressedKeys[MouseButton1] = sf::Mouse::isButtonDown(sf::Mouse::Button1)
            pressedKeys[MouseButton2] = sf::Mouse::isButtonDown(sf::Mouse::Button2)
            pressedKeys[MouseButton3] = sf::Mouse::isButtonDown(sf::Mouse::Button3) 
            
            // keyboard inputs
            for (int i = 0; i < KeyCount; ++i)
                pressedKeys[i] = sf::KeyBoard::isKeyPressed(i);
            
            //(bind with smfl sf::Key for keyboard and sf::Button for mouse)
            //TODO: need to see if binding is the same for sdl and others
        }

        bool isKeyPressed(KeyCode key)
        {
            return pressedKeys[key];
        }

        int getMouseXPosition() override 
        {
            return sf::Mouse::getMousePositon().x;
        }

        int getMouseYPosition() override 
        {
            return sf::Mouse::getMousePositon().y;
        }

        //////////////////////////////////////////






        // DRAW LOGIC:
        void draw(ISpriteModule *spriteModule) override
        {
            window->draw(dynamic_cast<sf::sprite *>spriteModule->GetSprite());
        }
        // etc ...
        ////////////////////////////////////////////

}