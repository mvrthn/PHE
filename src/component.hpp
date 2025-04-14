#pragma once


#include <SFML/Graphics/RenderTarget.hpp>

#include "object.hpp"


namespace PHEApp {

class Component {
public:
    virtual void update() = 0;
    virtual void display(sf::RenderTarget&) = 0;
    virtual void evalForce(PHE::Vector2f&, const PHE::Object&) = 0;
};

} // namespace PHEApp