#include "Widgets.h"

#define ESCAPE_KEY 36
#define DELETE_KEY 8
#define ENTER_KEY 58

class TextBox {
private:
    sf::Text text;

public:
    TextBox(sf::Vector2f position, sf::Font& font) {
        text.setFont(font);
        text.setCharacterSize(20);
        text.setFillColor(sf::Color::Black);
        text.setPosition(position);
    }

    void setText(std::string str) {
        text.setString(str);
    }

    void draw(sf::RenderWindow& window) {
        window.draw(text);
    }
};
