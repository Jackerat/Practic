#include "include/Widgets.h"

int main() {

    sf::RenderWindow window(sf::VideoMode(1024, 720), "SFML Button and TextBox");

    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
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
    std::uniform_int_distribution<int> storyDist(0, 4);
    std::string characterAttributes = "Character Attributes:\n\n";

    std::string races[4] = {"Human", "Elf", "Dwarf", "Golubchik"};
    std::string genders[2] = {"Male", "Female"};
    std::string storylines[5] = {
        "The character is a descendant of an ancient dragon, whose blood grants them special abilities and magical heritage.\n They set out on a journey to find their progenitor and learn more about their origins.",
        "The hero was exiled from a mysterious order of monks for breaking their tenets and sent out into\n a world they know little about. Now they must find their place and true purpose.",
        "The character is a lost prince or princess from a forgotten kingdom consumed by darkness.\n Their goal is to reclaim their heritage and free their people.",
        "The hero is a seeker of forgotten knowledge and the secrets of ancient civilizations.\n They strive to uncover the mysteries of lost worlds and face dangers on their path to truth.",
        "The character is a cursed knight whose weapon carries power but also brings suffering to those around them.\n They must find a way to break the curse and redeem their sins."
    };
}
