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
    sf::Font font;
    sf::Text text("...", font);
    sf::Vector2f circleMovement(0.f,0.f);
    font.loadFromFile("arial.ttf");
    while (window.isOpen())
    {
        dt = deltaClock.restart();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed)
                if (event.key.code == sf::Keyboard::Right)
                    circleMovement.x = 200.f*dt.asSeconds();
                else if (event.key.code == sf::Keyboard::Left)
                    circleMovement.x = -200.f*dt.asSeconds();
                else if (event.key.code == sf::Keyboard::Up)
                    circleMovement.y = -200.f*dt.asSeconds();
                else if (event.key.code == sf::Keyboard::Down)
                    circleMovement.y = 200.f*dt.asSeconds();

            if (event.type == sf::Event::KeyReleased)
                if (event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::Left)
                    circleMovement.x = 0;
                else if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::Down)
                    circleMovement.y = 0;

        }

        shape.move(circleMovement);

        text.setCharacterSize(30);
        text.setStyle(sf::Text::Bold);
        text.setColor(sf::Color::Red);
        // Draw it

        window.clear();
        window.draw(shape);
        window.draw(text);
        window.display();
    }

    return 0;
}