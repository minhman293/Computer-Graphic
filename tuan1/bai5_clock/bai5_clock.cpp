#include <SFML/Graphics.hpp>
#include <ctime>
using namespace sf;
using namespace std;
int main()
{
    // size of window
    const int width = 800;
    const int height = 800;
    // clock
    float clockRadius = 200;
    // position of clock
    float clockX = (width - 2 * clockRadius) / 2;
    float clockY = (height - 2 * clockRadius) / 2;
    CircleShape clock(clockRadius, 360);
    clock.setOutlineColor(Color::Black);
    clock.setOutlineThickness(1);
    clock.setPosition(clockX, clockY);
    // clock center
    float centerRadius = 10;
    // position of clock center
    float centerX = clockX + clockRadius;
    float centerY = clockY + clockRadius;
    CircleShape center(centerRadius, 360);
    center.setPosition(centerX - centerRadius, centerY - centerRadius);
    center.setFillColor(Color::Black);
    // length of hand
    float hourHandLength = (10.0f / 16.0f) * clockRadius;
    float minuteHandLength = (12.0f / 16.0f) * clockRadius;
    float secondHandLength = (14.0f / 16.0f) * clockRadius;
    // width of hand
    float hourHandWidth = 6.0f;
    float minuteHandWidth = 6.0f;
    float secondHandWidth = 3.0f;
    // hour hand
    RectangleShape hourHand;
    hourHand.setSize(Vector2f(hourHandLength, hourHandWidth));
    hourHand.setFillColor(Color::Black);
    hourHand.setPosition(centerX - 0.9 * hourHandWidth, centerY);
    // minute hand
    RectangleShape minuteHand;
    minuteHand.setSize(Vector2f(minuteHandLength, minuteHandWidth));
    minuteHand.setFillColor(Color::Black);
    minuteHand.setPosition(centerX, centerY);
    // second hand
    RectangleShape secondHand;
    secondHand.setSize(Vector2f(secondHandLength, secondHandWidth));
    secondHand.setFillColor(Color::Black);
    secondHand.setPosition(centerX, centerY);
    RenderWindow window(VideoMode(800, 800), "Clock");
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        time_t now = time(nullptr);
        tm *local_time = localtime(&now);
        float hour = (float)local_time->tm_hour;
        float minute = (float)local_time->tm_min;
        float second = (float)local_time->tm_sec;
        float hourHandAngle = (hour / 12.0f) * 360.0f - 90.0f;
        float minuteHandAngle = (minute / 60.0f) * 360.0f - 90.0f;
        float secondHandAngle = (second / 60.0f) * 360.0f - 90.0f;
        hourHand.setRotation(hourHandAngle);
        minuteHand.setRotation(minuteHandAngle);
        secondHand.setRotation(secondHandAngle);
        window.clear(Color::White);
        window.draw(clock);
        window.draw(center);
        window.draw(hourHand);
        window.draw(minuteHand);
        window.draw(secondHand);
        window.display();
    }
}