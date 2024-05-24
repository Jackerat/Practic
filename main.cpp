#include "tools/Tools.h"

int main() {

    sf::RenderWindow window(sf::VideoMode(1260, 720), "SFML Button and TextBox");

    sf::Font font;
    if (!font.loadFromFile("C:/Users/moonvolk4/Downloads/arial/arial.ttf")) {
        std::cout << "Failed to load font!" << std::endl;
        return -1;
    }


    Button generateButton(sf::Vector2f(100, 100), sf::Vector2f(100, 50), font, "Generate");
    Button finishButton(sf::Vector2f(400, 100), sf::Vector2f(100, 50), font, "Finish");
    Button deleteButton(sf::Vector2f(250, 100), sf::Vector2f(100, 50), font, "Delete");
    TextBox textBox(sf::Vector2f(100, 200), font);


    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> heightDist(150, 200);
    std::uniform_int_distribution<int> strengthDist(1, 10);
    std::uniform_int_distribution<int> genderDist(0, 1);
    std::uniform_int_distribution<int> raceDist(0, 2);
    std::string characterAttributes = "Character Attributes:\n\n";

    std::string races[4] = {"Human", "Elf", "Dwarf", "Golubchik"};
    std::string genders[2] = {"Male", "Female"};
    std::vector<std::string> storylines1 = {
        "The character grew up in a small village near the mountains.",
        "The character has a mysterious past that they are trying to uncover.",
        "The character is on a quest to avenge their fallen loved ones.",
        "The character is known for their exceptional leadership skills.",
        "The character is haunted by nightmares of a long-forgotten prophecy.",
};
    std::vector<std::string> storylines2 = {
        "They were trained in the art of combat from a young age.",
        "They have a deep connection with nature and can communicate with animals.",
        "They have a hidden talent for playing musical instruments.",
        "They possess a powerful artifact that grants them extraordinary powers."
};

    int num_s1 = storylines1.size();
    int num_s2 = storylines2.size();
    std::uniform_int_distribution<int> storyDist1(0, num_s1 - 1);
    std::uniform_int_distribution<int> storyDist2(0, num_s2 - 1);


    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(window));
                    if (generateButton.isClicked(mousePos)) {
                        int height = heightDist(gen);
                        std::string gender = genders[genderDist(gen)];
                        std::string race = races[raceDist(gen)];
                        int strength = strengthDist(gen);
                        std::string characterAttributes = "Character Attributes:\n";

                        characterAttributes += "Height: " + std::to_string(height) + " cm\n";
                        characterAttributes += "Gender: " + gender + "\n";
                        characterAttributes += "Race: " + race + "\n";
                        characterAttributes += "Strength: " + std::to_string(strength) + "\n";
                        std::string characterStoryline = "Character Storyline:\n";
                        characterStoryline += storylines1[storyDist1(gen)] + "\n" + storylines2[storyDist2(gen)] + "\n";

                        textBox.setText(characterAttributes + characterStoryline);
                    }
                    else if (finishButton.isClicked(mousePos)) {
                        window.close();
                    }
                    else if (deleteButton.isClicked(mousePos)) {
                        characterAttributes = "";
                        textBox.setText(characterAttributes);
                    }
                }
            }
            else if (event.type == sf::Event::MouseMoved) {
                sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(window));
                generateButton.isHovered(mousePos);
                finishButton.isHovered(mousePos);
                deleteButton.isHovered(mousePos);
            }
        }


        window.clear(sf::Color(242, 243, 244));


        generateButton.draw(window);
        finishButton.draw(window);
        deleteButton.draw(window);
        textBox.draw(window);


        window.display();
    }

    return 0;
}
