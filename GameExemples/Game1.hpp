class Game1 : IGameModule
{
    Game1()
    {
        void *(*createDisplay);//dlsym stuff
        display = createDisplay();
    }

    int run()
    {
        void *(*createSprite);//dlsym stuff
        void *(*createText);//dlsym stuff

        ITextModule *Score = createText();
        ISpriteModule *Player = createSprite();
        ISpriteModule *Ennemy createSprite();
        
        // Some Game data initialisation
        // settings sprites sources / positions / text fonts or some other shits :p

        while (display->isOpen())
        {
            display->ClearWindow(); // clears the window

            display->fectchInputs(); // fetches events



            // Arcade idea to switch to next/previous game
            if (display->isKeyPressed(IDisplayModule::RightArrow))
                return 1;
            if (display->isKeyPressed(IDisplayModule::LeftArrow))
                return -1;
            ////////////////////////////////////////////////////



            // Some Game Logic update
            if (display->isKeyPressed(IInputModule::KeyZ))
                Player->Move(0, 1);
            if (display->isKeyPressed(IInputModule::KeyS))
                Player->Move(0, -1);
            if (display->isKeyPressed(IInputModule::KeyQ))
                Player->Move(-1, 0);
            if (display->isKeyPressed(IInputModule::KeyD))
                Player->Move(1, 0);
            //////////////////////////////////////////////////

            // Some game logic draw
            window->Draw(Score);
            window->Draw(Player);
            window->Draw(Ennemy);
            //////////////////////////////////////////////////
            
            display->DisplayWindow();

        }
        return 0;
    }
    IDisplayModule *display;
}