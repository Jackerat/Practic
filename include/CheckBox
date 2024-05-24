#include "Widgets.h"

class CheckBox {
private:
    sf::RectangleShape shape;
    sf::Text text;
    sf::Font font;
    bool isChecked;

public:
    CheckBox(float x, float y, float size, std::string checkBoxText) {
        shape.setPosition(sf::Vector2f(x, y));
        shape.setSize(sf::Vector2f(size, size));
        shape.setFillColor(sf::Color::White);
        shape.setOutlineThickness(2);
        shape.setOutlineColor(sf::Color::Black);
        font.loadFromFile("Comfortaa-Regular.ttf");
        text.setFont(font);
        text.setString(checkBoxText);
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::Black);
        text.setPosition(sf::Vector2f(x + size + 10, y));
        isChecked = false;
    }

    void draw(sf::RenderWindow& window) {
        window.draw(shape);
        window.draw(text);
    }

    bool isMouseOver(sf::RenderWindow& window) {
        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
        sf::Vector2f checkBoxPosition = shape.getPosition();
        sf::Vector2f checkBoxSize = shape.getSize();

        if (mousePosition.x >= checkBoxPosition.x && mousePosition.x <= checkBoxPosition.x + checkBoxSize.x &&
            mousePosition.y >= checkBoxPosition.y && mousePosition.y <= checkBoxPosition.y + checkBoxSize.y) {
            return true;
            }
        return false;
    }

    bool isClickedOn(sf::RenderWindow& window, sf::Event event) {
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            if (isMouseOver(window)) {
                isChecked = !isChecked;
                return true;
            }
        }
        return false;
    }

    bool getIsChecked() {
        return isChecked;
    }

    void setIsChecked(bool checked) {
        isChecked = checked;
    }
};

