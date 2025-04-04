#pragma once


#include <SFML/Graphics.hpp>

#include "engine.hpp"
#include "rudder.hpp"
#include "object.hpp"


namespace PHEApp {

struct Model {
    const float mass = 1;
    const float inertia = 1;
    const PHE::Vector2f centerofMass = {0, 0};
    const PHE::Vector2f rudderPos = {0, 0};
    const PHE::Vector2f propellerPos = {0, 0};
    const PHE::Vector2f centerOfProgDrag = {0, 0};
    const PHE::Vector2f centerOFRotDrag = {0, 0};
};


class Yacht : public PHE::Object {
public:
    Yacht();

    void update();
    void display(sf::RenderWindow&);

    inline void setPosition(const PHE::Vector2f& pos) { PHE::Object::setPosition(pos); };

private:
    Model model;
    Engine engine;
    Rudder rudder;

    sf::Texture texture;
    sf::Sprite sprite;

private:
    void evalDragProgForce(PHE::Vector2f&);
    void evalDragRotForce(PHE::Vector2f&);
};

} // namespace PHEApp