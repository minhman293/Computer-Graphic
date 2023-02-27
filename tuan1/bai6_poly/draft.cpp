#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

int main()
{
    // Create a window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML");

    // Create a polygon shape with four points
    ConvexShape polygon;
    polygon.setPointCount(4);
    polygon.setPoint(0, sf::Vector2f(200, 200));
    polygon.setPoint(1, sf::Vector2f(354, 100));
    polygon.setPoint(2, sf::Vector2f(400, 400));
    polygon.setPoint(3, sf::Vector2f(300, 250));

    // Set the color of the polygon
    polygon.setFillColor(sf::Color::Red);

    // Run the program as long as the window is open
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear screen
        window.clear();

        // Draw the polygon
        window.draw(polygon);

        // Update the window
        window.display();
    }

    return 0;
}
