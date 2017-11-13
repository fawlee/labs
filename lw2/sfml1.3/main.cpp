#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({800, 600}), "title");

    window.clear();

    sf::RectangleShape shape1;
    shape1.setSize({220, 180});
    shape1.setFillColor(sf::Color(139, 69, 19));
    shape1.setPosition({290, 320});
    window.draw(shape1);

    sf::ConvexShape trapeze;
    trapeze.setFillColor(sf::Color(139, 0, 0));
    trapeze.setPosition(400, 300);
    trapeze.setPointCount(4);
    trapeze.setPoint(0, {-90, 0});
    trapeze.setPoint(1, {+90, 0});
    trapeze.setPoint(2, {+160, 60});
    trapeze.setPoint(3, {-160, 60});
    window.draw(trapeze);

    sf::RectangleShape shape2;
    shape2.setSize({50, 90});
    shape2.setFillColor(sf::Color(47, 79, 79));
    shape2.setPosition({320, 410});
    window.draw(shape2);

    sf::RectangleShape shape3;
    shape3.setSize({25, 50});
    shape3.setFillColor(sf::Color(105, 105, 105));
    shape3.setPosition({430, 280});
    window.draw(shape3);

    sf::RectangleShape shape4;
    shape4.setSize({45, 20});
    shape4.setFillColor(sf::Color(105, 105, 105));
    shape4.setPosition({420, 270});
    window.draw(shape4);

    sf::CircleShape shape5(10);
    shape5.setPosition({435, 250});
    shape5.setFillColor(sf::Color(192, 192, 192));
    window.draw(shape5);

    sf::CircleShape shape6(15);
    shape6.setPosition({445, 228});
    shape6.setFillColor(sf::Color(192, 192, 192));
    window.draw(shape6);

    sf::CircleShape shape7(20);
    shape7.setPosition({455, 200});
    shape7.setFillColor(sf::Color(192, 192, 192));
    window.draw(shape7);

    sf::CircleShape shape8(20);
    shape8.setPosition({465, 170});
    shape8.setFillColor(sf::Color(192, 192, 192));
    window.draw(shape8);

    window.display();

    sf::sleep(sf::seconds(5));
}