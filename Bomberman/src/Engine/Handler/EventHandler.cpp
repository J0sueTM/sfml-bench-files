#include "EventHandler.hpp"

EventHandler::EventHandler() {
    this->handlerEvent = new sf::Event;

    this->handlerKeyboard = new sf::Keyboard;
}

EventHandler::~EventHandler() {
    delete this->handlerEvent;
}

// TODO [J0sueTM] add handler to keys for movement
// && refactorize switch to polymorphism
void EventHandler::handleEvents(sf::RenderWindow* targetWindow) {
    while (targetWindow->isOpen()) {
        while (targetWindow->pollEvent(*(this->handlerEvent))) {
            handleWindow();
            handleKeys();
        }
    }
}

void EventHandler::handleWindow() {

}

void EventHandler::handleKeys() {
}
