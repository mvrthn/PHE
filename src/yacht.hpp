#pragma once


#include <SFML/Graphics.hpp>

#include "engine.hpp"
#include "rudder.hpp"
#include "object.hpp"
#include "hydroDrag.hpp"
#include "model.hpp"

namespace PHEApp {

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

    static constexpr float SCALE = 0.25;
    static constexpr int MID_X = 192;
    static constexpr int MID_Y = 512;
};

} // namespace PHEApp