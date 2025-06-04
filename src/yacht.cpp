#include "yacht.hpp"


namespace PHEApp {

Yacht::Yacht(const PHE::Vector2f& pos) : PHE::Object::Object(Model::mass, Model::inertia, pos) {
    std::vector<PHE::Force> forces;
    forces.reserve(4);

    forces.emplace_back(Model::rudderPos, rudder);
    forces.emplace_back(Model::propellerPos, engine);
    forces.emplace_back(Model::centerOfProgDrag, hdp);
    forces.emplace_back(Model::centerOFRotaDrag, hdr);

    PHE::Object::setForces(forces);

    texture.loadFromFile("../../res/yacht.png");
    texture.setSmooth(true);
    sprite.setTexture(texture);
    sprite.setScale({SCALE, SCALE});
    sprite.setOrigin({MID_X, MID_Y});
}

void Yacht::update(InputType& it, float dt) {
    if(it & InputType::RUDDER) {
        rudder.update(it);
    }
    if(it & InputType::ENGINE) {
        engine.update(it);
    }

    PHE::Object::update(dt);
    sprite.setPosition(*((sf::Vector2f*) &getPosition()));
    sprite.setRotation(getRotationAngle());
}

void Yacht::display(sf::RenderWindow& window) {
    window.draw(sprite);
}

} // namespace PHEApp