#include <SFML/Graphics.hpp>

#include "Engine/Window/Window.hpp"

int main() {
    // TODO [J0sueTM] make screen resolution and add intro menu
    Window mainWindow(256, 224, "Bomberman");

    mainWindow.Update();
}
