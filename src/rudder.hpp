#pragma once


#include "component.hpp"


constexpr int len = 16;


namespace PHEApp {

class Rudder : Component {
public:
    void update();
    void display(sf::RenderTarget&);
    void evalForce(PHE::Vector2f&);

private:
    int angle = 0;
};

} // namespace PHEApp