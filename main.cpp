#include <SFML/Graphics.hpp>
#include <sstream>
#include <typeinfo>

int main()
{
    int WWidth  = 1024;
    int WHeight = 768;

    int playerSpeed = 400.f;

    // Create the new Window
    sf::RenderWindow window(sf::VideoMode(WWidth, WHeight), "SFML works!");
    // Set max framerate
    window.setFramerateLimit(60);

    /* Create visual elements */

    // Players
    sf::Vector2f playerSize(50.f,200.f);
    sf::Vector2f player1Movement(0.f,0.f);
    sf::Vector2f player2Movement(0.f,0.f);
    sf::RectangleShape player1(playerSize);
    sf::RectangleShape player2(playerSize);
    player1.setFillColor(sf::Color::White);
    player2.setFillColor(sf::Color::White);
    sf::Vector2f player1Pos( WWidth-50, (WHeight/2)-100);
    sf::Vector2f player2Pos(0.f, (WHeight/2)-100);
    player1.setPosition(player1Pos);
    player2.setPosition(player2Pos);

    // Ball
    sf::CircleShape ball(50.f);
    ball.setFillColor(sf::Color::Cyan);
    ball.setPosition( (WWidth/2)-50, (WHeight/2)-50 );

    // Debug text
    sf::Font font;
    font.loadFromFile("arial.ttf");
    sf::Text text("...", font);

    // Create help vars
    // Delta time vars
    sf::Clock deltaClock;
    sf::Time dtt;
    float dt;

    // Controller vars
    bool player1Up;
    bool player1Down;
    bool player2Up;
    bool player2Down;

    // Main loop
    while (window.isOpen())
    {
        // Calculate delta time
        dtt = deltaClock.restart();
        dt = dtt.asSeconds();

        // Handle Close event
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Handle Controls
        player1Up   = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
        player1Down = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
        player2Up   = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
        player2Down = sf::Keyboard::isKeyPressed(sf::Keyboard::S);

        if(player1Up && !player1Down)
            player1Movement.y = -playerSpeed*dt;
        else if(!player1Up && player1Down)
            player1Movement.y = playerSpeed*dt;
        else
            player1Movement.y = 0;

        if(player2Up && !player2Down)
            player2Movement.y = -playerSpeed*dt;
        else if(!player2Up && player2Down)
            player2Movement.y = playerSpeed*dt;
        else
            player2Movement.y = 0;

        // Move Players
        player1.move(player1Movement);
        player2.move(player2Movement);

        // Move Ball
        

        // Draw debug text
        text.setCharacterSize(30);
        text.setStyle(sf::Text::Bold);
        text.setColor(sf::Color::Red);
        
        // Clear screen, draw everything and display
        window.clear();
        window.draw(text);
        window.draw(player1);
        window.draw(player2);
        window.draw(ball);
        window.display();
    }

    return 0;
}