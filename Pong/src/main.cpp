#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML-pong");
    sf::Vector2u windowBounds = window.getSize();

    bool paused = true;

    //visual
    sf::Color bgColor(58, 47, 92, 36);
    sf::Color laColor(193, 182, 225, 180);
    sf::Color baColor(55, 242, 156, 100);

    sf::Font mainFont;
    if (!mainFont.loadFromFile("src/fnt/arcade.ttf"))
    {
        std::cout << "Font file not found";

        return 0;
    }

    //snd
    sf::SoundBuffer hitB;
    if (!hitB.loadFromFile("src/snd/hit01.wav"))
    {
        std::cout << "Sound file not found";

        return 0;
    }
    sf::Sound hitS;
    hitS.setBuffer(hitB);
    hitS.setVolume(40.f);

    //GUI
    sf::Text greeterT("P R E S S  S P A C E", mainFont, 80);
    greeterT.setStyle(sf::Text::Bold);
    greeterT.setOrigin(greeterT.getLocalBounds().width * 0.5f, greeterT.getLocalBounds().height * 0.5f);

    sf::Vector2u points(0, 0);

    sf::Text lPoints("0", mainFont, 40);
    lPoints.setStyle(sf::Text::Bold); 
    lPoints.setOrigin(lPoints.getLocalBounds().width * 0.5f, lPoints.getLocalBounds().height * 0.5f);

    sf::Text rPoints("0", mainFont, 40);
    rPoints.setStyle(sf::Text::Bold); 
    rPoints.setOrigin(rPoints.getLocalBounds().width * 0.5f, rPoints.getLocalBounds().height * 0.5f);

    //objects
    sf::RectangleShape rLadder(sf::Vector2f(50.f, 200.f));
    sf::RectangleShape lLadder(sf::Vector2f(50.f, 200.f));

    sf::RectangleShape ball(sf::Vector2f(30.f, 30.f));

    rLadder.setOrigin(25.f, 100.f);
    rLadder.setFillColor(laColor);

    lLadder.setOrigin(25.f, 100.f);
    lLadder.setFillColor(laColor);

    ball.setOrigin(15.f, 15.f);
    ball.setFillColor(baColor);

    //movement
    sf::Vector2f rDir(0.f, 0.f);
    sf::Vector2f lDir(0.f, 0.f);

    sf::Vector2f bDir(0.5f, -0.5f);

    //start
    paused = true;

    greeterT.setPosition(windowBounds.x * 0.5f, 140.f);

    rPoints.setPosition(windowBounds.x - 40, 40);
    lPoints.setPosition(40, 40);

    rLadder.setPosition(windowBounds.x - 80, windowBounds.y * 0.5);

    lLadder.setPosition(80, windowBounds.y * 0.5);

    ball.setPosition(windowBounds.x * 0.5, windowBounds.y * 0.5);

   //start
    while (window.isOpen())
    {
        sf::Event e;
        while (window.pollEvent(e))
        {
            switch (e.type)
            {
                case sf::Event::Closed:
                    window.close();

                    break;
                case sf::Event::KeyReleased:
                    if (e.key.code == sf::Keyboard::Space)
                        paused = !paused;

                    break;
            }
        }
        if (!paused)
        {
            //live keyboard
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                rDir.y = -1.f;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                rDir.y = 1.f;

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
                lDir.y = -1.f;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::U))
                lDir.y = 1.f;

            //borders
            if (rLadder.getGlobalBounds().top <= 0)
                rDir.y = 1.f;
            if (lLadder.getGlobalBounds().top <= 0)
                lDir.y = 1.f;

            if (rLadder.getGlobalBounds().top + rLadder.getSize().y >= windowBounds.y)
                rDir.y = -1.f;
            if (lLadder.getGlobalBounds().top + lLadder.getSize().y >= windowBounds.y)
                lDir.y = -1.f;

            //ball
            if (ball.getGlobalBounds().top <= 0 || ball.getGlobalBounds().top + ball.getSize().y >= windowBounds.y)
            {
                hitS.play();
                bDir.y *= -1;
            }
            
            if (ball.getGlobalBounds().left <= 0)
            {
                points.y += 1;

                paused = true;

                greeterT.setPosition(windowBounds.x * 0.5f, 140.f);

                rPoints.setPosition(windowBounds.x - 40, 40);
                lPoints.setPosition(40, 40);

                rLadder.setPosition(windowBounds.x - 80, windowBounds.y * 0.5);

                lLadder.setPosition(80, windowBounds.y * 0.5);

                ball.setPosition(windowBounds.x * 0.5, windowBounds.y * 0.5);
            }

 
            if (ball.getGlobalBounds().left + ball.getSize().x >= windowBounds.x)
            {
                points.x += 1;

                paused = true;

                greeterT.setPosition(windowBounds.x * 0.5f, 140.f);

                rPoints.setPosition(windowBounds.x - 40, 40);
                lPoints.setPosition(40, 40);

                rLadder.setPosition(windowBounds.x - 80, windowBounds.y * 0.5);

                lLadder.setPosition(80, windowBounds.y * 0.5);

                ball.setPosition(windowBounds.x * 0.5, windowBounds.y * 0.5);
            }

 
           //collision ball/ladder
            if (ball.getGlobalBounds().intersects(rLadder.getGlobalBounds()) || ball.getGlobalBounds().intersects(lLadder.getGlobalBounds()))
            {
                hitS.play();
                bDir.x *= -1;
            }

            rLadder.move(rDir);
            rDir = {0.f, 0.f};

            lLadder.move(lDir);
            lDir = {0.f, 0.f};

            ball.move(bDir);

            //GUI
            lPoints.setString(std::to_string(points.x));
            rPoints.setString(std::to_string(points.y));
        }

        window.clear(bgColor);
        if (paused)
            window.draw(greeterT);

        window.draw(lPoints);
        window.draw(rPoints);
        window.draw(rLadder);
        window.draw(lLadder);
        window.draw(ball);
        window.display();
        
    }

    return 0;
}
