#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <cstdlib>
using namespace std;
using namespace sf;
int main()
{
    const int width = 1000, height = 800;
    RenderWindow window(VideoMode(width, height), "UFO");
    Event event;
    srand(time(NULL));
    while (window.isOpen())
    {
        // closing
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        // STARS
        // random position
        int x = rand() % width;
        int y = rand() % height;
        // random color
        int r = rand() % 256;
        int g = rand() % 256;
        int b = rand() % 256;
        // draw stars
        Vertex pixel(Vector2f(x, y), Color(r, g, b));
        // UFO
        CircleShape ufo(50.f, 20.f);
        ufo.setPointCount(100);
        ufo.setScale(3, 1);
        float xPos = width / 4, yPos = height / 4;
        ufo.setPosition(xPos, yPos);
        ufo.setFillColor(Color::White);
        // Cabin
        CircleShape cabin(30.f, 30.f);
        cabin.setPointCount(100);
        cabin.setScale(1.5, 1);
        cabin.setPosition(ufo.getPosition().x + 100.f, ufo.getPosition().y - 40.f);
        cabin.setFillColor(Color::White);
        window.draw(&pixel, 1, Points);
        window.draw(ufo);
        window.draw(cabin);
        window.display();
    }
}
