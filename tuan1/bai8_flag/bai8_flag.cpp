#include <SFML/Graphics.hpp>
using namespace sf;
int main()
{
    const int width = 900, height = 600;
    RenderWindow window(VideoMode(width, height), "Flag");
    ConvexShape star;
    star.setPointCount(10);
    star.setPoint(0, Vector2f(450, 150));
    star.setPoint(1, Vector2f(485, 265));
    star.setPoint(2, Vector2f(605, 265));
    star.setPoint(3, Vector2f(506, 334));
    star.setPoint(4, Vector2f(548, 449));
    star.setPoint(5, Vector2f(450, 380));
    star.setPoint(6, Vector2f(352, 449));
    star.setPoint(7, Vector2f(391, 334));
    star.setPoint(8, Vector2f(296, 265));
    star.setPoint(9, Vector2f(416, 265));
    star.setFillColor(Color::Yellow);
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        window.clear(Color::Red);
        window.draw(star);
        window.display();
    }
}
