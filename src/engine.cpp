#include "engine.hpp"


namespace PHEApp {

void Engine::update(InputType& it) {
    if(it & InputType::RPM_UP) {
        rpm = std::min(rpm + STEP, MAX_RPM);
    }
    else if(it & InputType::RPM_DOWN) {
        rpm = std::max(rpm + STEP, MIN_RPM);
    }
    else if(it & InputType::GEAR_UP) {
        gear = std::min(gear + 1, 1);
    }
    else if(it & InputType::GEAR_DOWN) {
        gear = std::max(gear - 1, -1);
    }
}

void Engine::display(sf::RenderTarget& window) {
    
}

void Engine::eval(PHE::Vector2f& vector, const PHE::Object& object) const {
    vector = {1000, 1000};
}

} // namespace PHEApp