#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({800, 600}), "title");

    window.clear();

    sf::RectangleShape shape1;
    shape1.setSize({80, 220});
    shape1.setPosition({20, 20});
    shape1.setFillColor(sf::Color(0x43, 0x43, 0x43));
    window.draw(shape1);

    sf::CircleShape shape2(30);
    shape2.setPosition({30, 35});
    shape2.setFillColor(sf::Color(0x0, 0xFF, 0x0));
    window.draw(shape2);

    sf::CircleShape shape3(30);
    shape3.setPosition({30, 100});
    shape3.setFillColor(sf::Color(0xFF, 0xCC, 0x26));
    window.draw(shape3);

    sf::CircleShape shape4(30);
    shape4.setPosition({30, 165});
    shape4.setFillColor(sf::Color(0xF2, 0x0, 0x0));
    window.draw(shape4);

    window.display();

    sf::sleep(sf::seconds(5));
}