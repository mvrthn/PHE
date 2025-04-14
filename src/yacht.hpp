#pragma once


#include <SFML/Graphics.hpp>

#include "engine.hpp"
#include "rudder.hpp"
#include "object.hpp"


namespace PHEApp {

namespace Model {
    constexpr float mass = 1;
    constexpr float inertia = 1;
    constexpr PHE::Vector2f rudderPos = {0, 128};
    constexpr PHE::Vector2f propellerPos = {0, 96};
    constexpr PHE::Vector2f centerOfProgDrag = {0, 0};
    constexpr PHE::Vector2f centerOFRotDrag = {0, 0};
} // namespace Model


class Yacht : public PHE::Object {
public:
    Yacht(const PHE::Vector2f&);

    void update();
    void display(sf::RenderWindow&);

private:
    Engine engine;
    Rudder rudder;

    sf::Texture texture;
    sf::Sprite sprite;

private:
    void evalDragProgForce(PHE::Vector2f&);
    void evalDragRotForce(PHE::Vector2f&);
};

} // namespace PHEApp