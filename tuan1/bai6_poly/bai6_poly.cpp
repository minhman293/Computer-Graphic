#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
using namespace sf;
using namespace std;
int main()
{
    int n, m;
    const int width = 1000, height = 800;
    vector<ConvexShape> v;
    cout << "so luong da giac: ";
    cin >> m;
    cout << "so canh cua da giac: ";
    cin >> n;
    RenderWindow window(VideoMode(width, height), "Da giac");
    while (window.isOpen())
    {
        // closing
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        // m random poly
        while (m > 0)
        {
            ConvexShape poly;
            poly.setPointCount(n);
            for (int i = 0; i < n; i++)
            {
                // random position x, y
                float x = (float)(1.0f + (rand() % width));
                float y = (float)(1.0f + (rand() % height));
                poly.setPoint(i, Vector2f(x, y));
            }
            // random color
            int r = rand() % 256;
            int g = rand() % 256;
            int b = rand() % 256;
            poly.setFillColor(Color(r, g, b));
            // add multiple poly to a shape vector
            v.push_back(poly);
            m--;
        }
        // clear screen
        window.clear(Color::White);
        // draw multiple poly
        for (int i = 0; i < v.size(); i++)
            window.draw(v[i]);
        window.display();
    }
    return 0;
}