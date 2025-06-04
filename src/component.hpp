#pragma once


#include <SFML/Graphics/RenderTarget.hpp>

#include "object.hpp"
#include "types.hpp"


namespace PHEApp {

class Component {
public:
    virtual void update(InputType&) = 0;
    virtual void display(sf::RenderTarget&) const = 0;
};

} // namespace PHEApp