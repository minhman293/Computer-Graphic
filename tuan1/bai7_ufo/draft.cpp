#include <SFML/Graphics.hpp>

int main()
{
    const int width = 900, height = 600;
    sf::RenderWindow window(sf::VideoMode(width, height), "Star in SFML");

    sf::ConvexShape star;
    star.setPointCount(10);
    // CORRECT X, Y
    star.setPoint(0, sf::Vector2f(450, 150));
    star.setPoint(1, sf::Vector2f(485, 265));
    star.setPoint(2, sf::Vector2f(605, 265));
    star.setPoint(3, sf::Vector2f(506, 334));
    star.setPoint(4, sf::Vector2f(548, 449));
    star.setPoint(5, sf::Vector2f(450, 380));
    star.setPoint(6, sf::Vector2f(352, 449));
    star.setPoint(7, sf::Vector2f(391, 334));
    star.setPoint(8, sf::Vector2f(296, 265));
    star.setPoint(9, sf::Vector2f(416, 265));
    star.setFillColor(sf::Color::Yellow);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(star);
        window.display();
    }

    return 0;
}
