#include <SFML/Graphics.hpp>
#include "RichText.hpp"
#include <string>

int main()
{
    sf::RenderWindow window(sf::VideoMode(300, 160), "RichText test");
    window.setFramerateLimit(30);

    sf::Font font;
    font.loadFromFile("font.ttf");

    RichText::initializeColors();
    RichText text("Ceci *est #red #ffaa00 un ~test* #blue de \n_la #yellow ~classe R_ich#green Text.\n\nHe#magenta llo World !", font);
    text.setPosition(50, 15);
    text.setNewLineSize(1.1);

    sf::RectangleShape rect;
    rect.setFillColor(sf::Color::Transparent);
    rect.setOutlineColor(sf::Color::Red);
    rect.setOutlineThickness(2);
    rect.setPosition(50, 15);

    uint32_t count = 0;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if(count == 0) text.setCharacterSize(18);
        if(count == 10) text.setCharacterSize(19);
        if(count == 20) text.setCharacterSize(20);
        if(count == 30) text.setCharacterSize(21);
        if(count == 40) text.setCharacterSize(22);
        if(count == 50) text.setCharacterSize(23);
        if(count == 60) text.setCharacterSize(24);

        window.clear(sf::Color::Black);
        window.draw(text);
        sf::FloatRect tmp = text.getLocalBounds();
        rect.setSize(sf::Vector2f(tmp.width, tmp.height));
        window.draw(rect);
        window.display();
        count = (count + 1) % 70;
    }

    return 0;
}
