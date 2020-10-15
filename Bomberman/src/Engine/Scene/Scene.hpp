#ifndef SCENE_HPP
#define SCENE_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

class Scene {
    public:
        Scene(const sf::RenderWindow* targetWindow);
        ~Scene();

        void Render();
    private:
};

#endif
