#include "EventHandler.hpp"

EventHandler::EventHandler() {
    this->handlerEvent = new sf::Event;
}

EventHandler::~EventHandler() {
    delete this->handlerEvent;
}

void EventHandler::handleEvents(sf::RenderWindow* targetWindow) {
    while (targetWindow->isOpen()) {
        while (targetWindow->pollEvent(*(this->handlerEvent))) {
            switch (this->handlerEvent->type) {
                case sf::Event::Closed:

                    targetWindow->close();

                    break;
            }
        }
    }
}
