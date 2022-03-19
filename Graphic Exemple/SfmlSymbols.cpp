// DL SYMBOLS to create modules

extern "C" IDisplayModule *createDisplay(unsigned int width, unsigned int height, std::string title);
{
    return new SfmlDisplay();
}


extern "C" void deleteDisplay(IDisplayModule *module)
{
    delete module;
}




extern "C" ISpriteModule *createSprite()
{
    return new SfmlSprite();
}


extern "C" void deleteSprite(ISpriteModule *module)
{
    delete module;
}



////////////////////////////////////////////////////////////
