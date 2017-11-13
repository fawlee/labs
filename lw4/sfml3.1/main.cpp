#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <cmath>
#include <iostream>

float time1 = 0;

float invert(float x)
{
    if (x < 0)
    {
        return 360 + x;
    }
    else
    {
        return x;
    }
}

float onMouseMove(const sf::Event::MouseMoveEvent &event, sf::Vector2f &mousePosition)
{
    mousePosition = {float(event.x), float(event.y)};
}

float toGrees(float radians)
{
    return float(double(radians) * 180.0 / M_PI);
}

float rotateIs(const float angle, float pointerRotate)
{
    if (angle > pointerRotate)
    {
        if (angle - pointerRotate > 180)
        {
            return (-1.f);
        }
        else
        {
            return (1.f);
        }
    }
    else if (pointerRotate > angle)
    {
        if (pointerRotate - angle > 180)
        {
            return (1.f);
        }
        else
        {
            return (-1.f);
        }
    }
    else if (pointerRotate = angle)
    {
        return 0;
    }
}

void turn(sf::ConvexShape &pointer, float time, float speed, float angle)
{
    const float direction = rotateIs(angle, pointer.getRotation());

    if (direction == 0)
    {
        pointer.setRotation(angle);
    }
    else
    {
        pointer.setRotation(pointer.getRotation() + (speed * time * direction));
    }
}

void init(sf::ConvexShape &pointer)
{
    pointer.setPointCount(3);
    pointer.setPoint(0, {40, 0});
    pointer.setPoint(1, {-20, -20});
    pointer.setPoint(2, {-20, 20});
    pointer.setPoint(2, {-20, 20});
    pointer.setPosition({400, 300});
    pointer.setFillColor(sf::Color(0xFF, 0x80, 0x0));
}

void pollEvents(sf::RenderWindow &window, sf::Vector2f &mousePosition)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::MouseMoved:
            onMouseMove(event.mouseMove, mousePosition);
            break;
        default:
            break;
        }
    }
}

void update(const sf::Vector2f &mousePosition, sf::ConvexShape &pointer, float time, float speed)
{
    const sf::Vector2f delta = mousePosition - pointer.getPosition();
    const float tg = atan2(delta.y, delta.x);
    const float angle = invert(toGrees(tg));
    turn(pointer, time, speed, angle);
}

void redrawFrame(sf::RenderWindow &window, sf::ConvexShape &pointer)
{
    window.clear();
    window.draw(pointer);
    window.display();
}

int main()
{
    constexpr unsigned WINDOW_WIDTH = 800;
    constexpr unsigned WINDOW_HEIGHT = 600;

    float speed = 15.0;

    sf::Clock clock;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}),
                            "Pointer",
                            sf::Style::Default,
                            settings);
    sf::ConvexShape pointer;
    sf::Vector2f mousePosition;

    init(pointer);
    while (window.isOpen())
    {
        pollEvents(window, mousePosition);
        update(mousePosition, pointer, clock.restart().asSeconds(), speed);
        redrawFrame(window, pointer);
    }
}