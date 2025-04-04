#pragma once


#include <SFML/Graphics.hpp>

#include "vectors.hpp"
#include "force.hpp"

constexpr int WIDTH = 1600;
constexpr int HEIGHT = 1000;


namespace PHEApp {

class App {
public:
    void run();

private:
    sf::RenderWindow window = sf::RenderWindow({WIDTH, HEIGHT}, "Yacht Sim", sf::Style::Close);
};

} // namespace PHEApp