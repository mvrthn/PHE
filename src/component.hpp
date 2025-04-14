#pragma once


#include <SFML/Graphics/RenderTarget.hpp>

#include "vectors.hpp"


namespace PHEApp {

class Component {
public:
    virtual void update() = 0;
    virtual void display(sf::RenderTarget&) = 0;
    virtual void evalForce(PHE::Vector2f&) = 0;
};

} // namespace PHEApp