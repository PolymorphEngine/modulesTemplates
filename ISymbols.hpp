// DL SYMBOLS to create modules

IDisplayModule *createDisplay(unsigned int width, unsigned int height, std::string title);
void deleteDisplay(IDisplayModule *module);

ISpriteModule *createSprite();
void deleteSprite(ISpriteModule *module);

ITextModule *createText();
void deleteText(ITextModule *module);

IAudioModule *createAudio();
void deleteAudio(IAudioModule *module);



////////////////////////////////////////////////////////////
