#include "yacht.hpp"

#include <functional>


namespace PHEApp {

Yacht::Yacht(const PHE::Vector2f& pos) : PHE::Object::Object(Model::mass, Model::inertia, pos) {
    std::vector<PHE::Force> forces;
    forces.reserve(4);

    using namespace std::placeholders;

    forces.emplace_back(Model::rudderPos, std::bind(&Rudder::evalForce, rudder, _1, _2));
    forces.emplace_back(Model::propellerPos, std::bind(&Engine::evalForce, engine, _1, _2));
    forces.emplace_back(Model::centerOfProgDrag, std::bind(HydroDrag::evalProgForce, _1, _2));
    forces.emplace_back(Model::centerOFRotaDrag, std::bind(HydroDrag::evalRotaForce, _1, _2));

    PHE::Object::setForces(forces);

    texture.loadFromFile("../../res/yacht.png");
    texture.setSmooth(true);
    sprite.setTexture(texture);
    sprite.setScale({SCALE, SCALE});
    sprite.setOrigin({MID_X, MID_Y});
}

void Yacht::update() {
    PHE::Object::update(0.01);
    sprite.setPosition(*((sf::Vector2f*) &getPosition()));
    sprite.setRotation(getRotationAngle());
}

void Yacht::display(sf::RenderWindow& window) {
    window.draw(sprite);
}

} // namespace PHEApp