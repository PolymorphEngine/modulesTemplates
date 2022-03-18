// DL SYMBOLS to create modules

extern "C" IDisplayModule *createDisplay()
{
    return new SfmlDisplay();
}


extern "C" void deleteDisplay(IDisplayModule *module)
{
    delete dynamic_cast<SfmlDisplay*>(module);
}




extern "C" ISpriteModule *createSprite()
{
    return new SfmlSprite();
}


extern "C" void deleteSprite(ISpriteModule *module)
{
    delete dynamic_cast<SfmlSprite*>(module);
}



////////////////////////////////////////////////////////////
