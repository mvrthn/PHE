#include "rudder.hpp"


namespace PHEApp {

void Rudder::update() {

}

void Rudder::display(sf::RenderTarget& window) {
    
}

void Rudder::evalForce(PHE::Vector2f& vector, const PHE::Object& object) {
    vector = {1000, 1000};
}

} // namespace PHEApp