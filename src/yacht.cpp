#include "yacht.hpp"

#include <functional>


namespace PHEApp {

Yacht::Yacht() : PHE::Object::Object(model.mass, model.inertia, model.centerofMass) {
    std::vector<PHE::Force> forces;
    forces.reserve(4);

    using namespace std::placeholders;

    forces.emplace_back(model.centerOfProgDrag, std::bind(&Yacht::evalDragProgForce, this, _1));
    forces.emplace_back(model.rudderPos, std::bind(&Rudder::evalForce, rudder, _1));
    forces.emplace_back(model.propellerPos, std::bind(&Engine::evalForce, engine, _1));
    forces.emplace_back(model.centerOFRotDrag, std::bind(&Yacht::evalDragRotForce, this, _1));

    PHE::Object::setForces(forces);

    texture.loadFromFile("../../res/yacht.png");
    sprite.setTexture(texture);
    sprite.setScale({0.5, 0.5});
    sprite.setOrigin({193, 513});
}

void Yacht::update() {
    PHE::Object::update(0);
    PHE::Vector2f vp = getPosition();
    sf::Vector2f v = *((sf::Vector2f*) &vp);
    sprite.setPosition(v);
    sprite.setRotation(getRotationAngle());
}

void Yacht::display(sf::RenderWindow& window) {
    window.draw(sprite);
}

void Yacht::evalDragProgForce(PHE::Vector2f& vector) {
    vector.x = 1;
    vector.y = 1;
}

void Yacht::evalDragRotForce(PHE::Vector2f& vector) {

}

} // namespace PHEApp