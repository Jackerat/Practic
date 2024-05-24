#include "Tools.h"


class Button {
private:
    sf::RectangleShape shape;
    sf::Text text;
    bool isChecked;

public:
    Button(sf::Vector2f position, sf::Vector2f size, sf::Font& font, std::string buttonText) {
        shape.setPosition(position);
        shape.setSize(size);
        shape.setFillColor(sf::Color::White);
        shape.setOutlineThickness(2.f);
        shape.setOutlineColor(sf::Color::Black);

        text.setFont(font);
        text.setCharacterSize(20);
        text.setFillColor(sf::Color::Black);
        text.setPosition(position);
        text.setString(buttonText);

        isChecked = false;
    }

    void draw(sf::RenderWindow& window) {
        window.draw(shape);
        window.draw(text);
    }

    bool isHovered(sf::Vector2f mousePos) {
        if (shape.getGlobalBounds().contains(mousePos)) {
            shape.setFillColor(sf::Color(192,192,192));
            return true;
        }
        else {
            shape.setFillColor(sf::Color(242,243,244));
            return false;
        }
    }

    bool isClicked(sf::Vector2f mousePos) {
        if (shape.getGlobalBounds().contains(mousePos)) {
            isChecked = !isChecked;
            shape.setFillColor(sf::Color(192,192,192));
            return true;
        }
        return false;
    }

    bool isCheckedState() {
        return isChecked;
    }
};
