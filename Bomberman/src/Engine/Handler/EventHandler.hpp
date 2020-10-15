#ifndef EVENTHANDLER_HPP
#define EVENTHANDLER_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

class EventHandler {
    public:
        EventHandler();
        ~EventHandler();

        void handleEvents(sf::RenderWindow* targetWindow);
    private:
        sf::Event* handlerEvent = nullptr;
};

#endif
