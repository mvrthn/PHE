#pragma once


#include <SFML/Graphics.hpp>

#include "vectors.hpp"


namespace PHEApp {

class Rudder {
public:
    void update();
    void display(sf::RenderTarget&);
    void evalForce(PHE::Vector2f&);

private:
    int angle;
};

} // namespace PHEApp