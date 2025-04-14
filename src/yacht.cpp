#include "yacht.hpp"

#include <functional>


namespace PHEApp {

Yacht::Yacht(const PHE::Vector2f& pos) : PHE::Object::Object(Model::mass, Model::inertia, pos) {
    std::vector<PHE::Force> forces;
    forces.reserve(4);

    using namespace std::placeholders;

    forces.emplace_back(Model::centerOfProgDrag, std::bind(&Yacht::evalDragProgForce, this, _1));
    forces.emplace_back(Model::rudderPos, std::bind(&Rudder::evalForce, rudder, _1));
    forces.emplace_back(Model::propellerPos, std::bind(&Engine::evalForce, engine, _1));
    forces.emplace_back(Model::centerOFRotDrag, std::bind(&Yacht::evalDragRotForce, this, _1));

    PHE::Object::setForces(forces);

    texture.loadFromFile("../../res/yacht.png");
    texture.setSmooth(true);
    sprite.setTexture(texture);
    sprite.setScale({0.25, 0.25});
    sprite.setOrigin({192, 512});
}

void Yacht::update() {
    PHE::Object::update(0.01);
    sprite.setPosition(*((sf::Vector2f*) &getPosition()));
    sprite.setRotation(getRotationAngle());
}

void Yacht::display(sf::RenderWindow& window) {
    window.draw(sprite);
}

void Yacht::evalDragProgForce(PHE::Vector2f& vector) {
    vector = {0, 0};
}

void Yacht::evalDragRotForce(PHE::Vector2f& vector) {
    vector = {0, 0};
}

} // namespace PHEApp