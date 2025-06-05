#include "rudder.hpp"


namespace PHEApp {

void Rudder::update(InputType& it) {
    if(it & InputType::RUDDER_LEFT) {
        angle = std::max(angle - STEP, -MAX_ANGLE);
    }
    else if(it & InputType::RUDDER_RIGHT) {
        angle = std::min(angle + STEP, MAX_ANGLE);
    }
}

void Rudder::display(sf::RenderTarget& window) const {
    
}

void Rudder::eval(PHE::Vector2f& vector, const PHE::Object& object) const {
    vector = {0, 0};
}

} // namespace PHEApp