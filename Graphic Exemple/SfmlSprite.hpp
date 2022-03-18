class SflmSprite : ISpriteModule
{
    //PROPERTIES:
    sf::sprite *sprite;
    sf::texture *texture;



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
    
    void setSprite(string filePath) override
    {
        texture.loadFromFile(filePath);

        sprite.setTexture(texture);
    }

    void setPosition(int x, int y) override
    {
        sprite.setPosition(x, y);
    }

    void setCrop(int x, int y, int width, int height) override
    {
        sprite.setTextureRect(x, y, width, height);
    }
    
    
}