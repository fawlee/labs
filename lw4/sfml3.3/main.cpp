#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <cmath>
#include <iostream>

float toGrees(float radians){ return float(double(radians) * 180.0 / M_PI); }
sf::Vector2f relativePos(sf::Vector2f posRoot, sf::Vector2f absolPos){ return absolPos-posRoot; }

constexpr float HeightEye = 100;			
constexpr float WidthEye = 70;			 
constexpr float RadiusPupil = 15;		 
constexpr float DistBetEyeAndPupil = 20; 
constexpr float DistanceBetweenEye = 50; 
constexpr float Points = 100;			 
constexpr unsigned WINDOW_WIDTH = 800;   
constexpr unsigned WINDOW_HEIGHT = 600; 
const sf::Color ColorApple = sf::Color(0xFF, 0x0, 0x0);  
const sf::Color ColorPupil = sf::Color(0x00, 0x0, 0x0);  

struct Eye{
	sf::ConvexShape eyeApple;
	sf::CircleShape eyePupil; 
	sf::Vector2f position;	

	void init(sf::Vector2f position,sf::Vector2f size);
	void draw(sf::RenderWindow &window);
	void update(sf::Vector2f &mousePosition);
private:
	float calcAngle(sf::Vector2f relativeMousePosition);
	int mouseOnEye(sf::Vector2f relativeMousePosition, float angle);
};

int Eye::mouseOnEye(sf::Vector2f relativeMousePosition, float angle)
{
	float x1 = (HeightEye-DistBetEyeAndPupil) * std::cos(angle);
	float x2 = (HeightEye-DistBetEyeAndPupil) * std::cos(angle+M_PI);
	float y1 = (HeightEye-DistBetEyeAndPupil) * std::sin(angle);
	float y2 = (WidthEye-DistBetEyeAndPupil) * std::sin(angle+M_PI);

	if ((std::max(x1, x2) >= relativeMousePosition.x) &&
		(std::min(x1, x2) <= relativeMousePosition.x) &&
		(std::max(y1, y2) >= relativeMousePosition.y) && 
		(std::min(y1, y2) <= relativeMousePosition.y))
	{return 1;}
	else
	{return 0;}
}

float Eye::calcAngle(sf::Vector2f relativeMousePosition)
{
	const sf::Vector2f modifiedDelta = sf::Vector2f({relativeMousePosition.x / (WidthEye-DistBetEyeAndPupil), relativeMousePosition.y / (HeightEye-DistBetEyeAndPupil)});
	return std::atan2(modifiedDelta.y, modifiedDelta.x);
};

void Eye::update(sf::Vector2f &mousePosition)
{
	const sf::Vector2f delta = relativePos(this->position, mousePosition);
	float angle = calcAngle(delta);
	if (0 == this->mouseOnEye(delta, angle))
	{
		sf::Vector2f pepe = sf::Vector2f{
			(WidthEye-DistBetEyeAndPupil) * std::cos(angle),
			(HeightEye-DistBetEyeAndPupil) * std::sin(angle)
		};
		this->eyePupil.setPosition(this->position + pepe);
	}
	else
	{
		this->eyePupil.setPosition(mousePosition);
	}
}

void Eye::draw(sf::RenderWindow &window)
{
	window.draw(eyeApple);
	window.draw(eyePupil);
}

void Eye::init(sf::Vector2f position,sf::Vector2f size)
{
	this->eyeApple.setPosition(position); 
	this->position = position;		
	this->eyeApple.setPointCount(Points); 
	for (int pointNo = 0; pointNo < Points; ++pointNo)
	{
		float angle = float(2 * M_PI * pointNo) / float(Points);	 
		sf::Vector2f point = sf::Vector2f{							 
			size.x * std::cos(angle),  
			size.y * std::sin(angle)}; 
		this->eyeApple.setPoint(pointNo, point);
	}
	this->eyePupil.setRadius(RadiusPupil);
	this->eyePupil.setOrigin(RadiusPupil, RadiusPupil);									  
	this->eyePupil.setPosition(position);
	this->eyeApple.setFillColor(ColorApple);
	this->eyePupil.setFillColor(ColorPupil);
}

void onMouseMove(const sf::Event::MouseMoveEvent &event, sf::Vector2f &mousePosition) 
{
	mousePosition = {float(event.x), float(event.y)}; 
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

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}),
							"These EYES see your cursor",
							sf::Style::Default,
							settings);
	sf::Vector2f mousePosition;

	Eye eyeLeft;
	Eye eyeRight;
	eyeLeft.init(sf::Vector2f({WINDOW_WIDTH/2 - (WidthEye+(DistanceBetweenEye/2)), WINDOW_HEIGHT/2}),sf::Vector2f({WidthEye, HeightEye}));
	eyeRight.init(sf::Vector2f({WINDOW_WIDTH/2 + (WidthEye+(DistanceBetweenEye/2)), WINDOW_HEIGHT/2}),sf::Vector2f({WidthEye, HeightEye}));
	
	while (window.isOpen())
	{
		pollEvents(window, mousePosition);
		eyeLeft.update(mousePosition);
		eyeRight.update(mousePosition);
		window.clear();
		eyeLeft.draw(window);
		eyeRight.draw(window);
		window.display();
	}
}