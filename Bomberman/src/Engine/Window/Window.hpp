#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

#include "../Handler/EventHandler.hpp"
#include "../Scene/Scene.hpp"

class Window {
    public:
        // FIXME parse width and heigh as sf::VideoMode instead of two int
        Window(int const &windowWidth, int const &windowHeight, std::string windowTitle);
        ~Window();

        void Update();
        void Display();

    private:
        sf::RenderWindow* mainWindow = nullptr;
        sf::VideoMode* mainVideoMode = nullptr;
        EventHandler* mainEventHandler = nullptr;

        //scenes
        Scene* introScene = nullptr;

};

#endif
