#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({800, 600}), "title");

    window.clear();

    sf::RectangleShape shape1;
    shape1.setSize({10, 40});
    shape1.setPosition({20, 20});
    shape1.setFillColor(sf::Color(0xFF, 0x0, 0x0));
    window.draw(shape1);

    sf::RectangleShape shape2;
    shape2.setSize({10, 30});
    shape2.setRotation(-60);
    shape2.setPosition({20, 30});
    shape2.setFillColor(sf::Color(0xFF, 0x0, 0x0));
    window.draw(shape2);

    sf::RectangleShape shape3;
    shape3.setSize({10, 25});
    shape3.setRotation(60);
    shape3.setPosition({65, 25});
    shape3.setFillColor(sf::Color(0xFF, 0x0, 0x0));
    window.draw(shape3);

    sf::RectangleShape shape4;
    shape4.setSize({10, 40});
    shape4.setPosition({65, 20});
    shape4.setFillColor(sf::Color(0xFF, 0x0, 0x0));
    window.draw(shape4);

    sf::RectangleShape shape5;
    shape5.setSize({10, 40});
    shape5.setPosition({100, 20});
    shape5.setFillColor(sf::Color(0xFF, 0x0, 0x0));
    window.draw(shape5);

    sf::RectangleShape shape6;
    shape6.setSize({8, 39});
    shape6.setRotation(-60);
    shape6.setPosition({100, 26});
    shape6.setFillColor(sf::Color(0xFF, 0x0, 0x0));
    window.draw(shape6);

    sf::RectangleShape shape7;
    shape7.setSize({8, 37});
    shape7.setRotation(60);
    shape7.setPosition({134, 35});
    shape7.setFillColor(sf::Color(0xFF, 0x0, 0x0));
    window.draw(shape7);

    sf::RectangleShape shape8;
    shape8.setSize({10, 44});
    shape8.setRotation(30);
    shape8.setPosition({180, 20});
    shape8.setFillColor(sf::Color(0xFF, 0x0, 0x0));
    window.draw(shape8);

    sf::RectangleShape shape9;
    shape9.setSize({10, 50});
    shape9.setRotation(-30);
    shape9.setPosition({180, 20});
    shape9.setFillColor(sf::Color(0xFF, 0x0, 0x0));
    window.draw(shape9);

    sf::RectangleShape shape10;
    shape10.setSize({30, 8});
    shape10.setPosition({170, 45});
    shape10.setFillColor(sf::Color(0xFF, 0x0, 0x0));
    window.draw(shape10);

    window.display();

    sf::sleep(sf::seconds(5));
}
