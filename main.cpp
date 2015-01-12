#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1024, 768), "SFML works!");
    window.setFramerateLimit(60);
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(50.f,50.f);

    sf::Clock deltaClock;
    sf::Time dt;
    while (window.isOpen())
    {
        dt = deltaClock.restart();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //shape.setPosition(shape.getPosition().x+ (1*dt.asSeconds()) ,50.f);
        shape.move(20*dt.asSeconds(),0);

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}