#include "Window.hpp"

Window::Window(const int& windowWidth, const int& windowHeight, std::string windowTitle) {
    this->mainVideoMode = new sf::VideoMode(windowWidth, windowHeight);
    this->mainWindow = new sf::RenderWindow(*(this->mainVideoMode), windowTitle);

    this->mainEventHandler = new EventHandler();
}

Window::~Window() {
    delete this->mainWindow;
    delete this->mainVideoMode;
    delete this->mainEventHandler;
}

void Window::Update() {
    this->mainEventHandler->handleEvents(this->mainWindow);    

    Display();
}

void Window::Display() {
    this->mainWindow->clear();
    this->mainWindow->display();
}
