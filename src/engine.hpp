#pragma once


#include "component.hpp"


namespace PHEApp {

class Engine : Component {
public:
    void update();
    void display(sf::RenderTarget&);
    void evalForce(PHE::Vector2f&, const PHE::Object&);
};

} // namespace PHEApp