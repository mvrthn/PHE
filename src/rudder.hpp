#pragma once


#include "component.hpp"
#include "evaluator.hpp"


namespace PHEApp {

class Rudder : Component, public PHE::Evaluator {
public:
    void update(InputType&);
    void display(sf::RenderTarget&);
    void eval(PHE::Vector2f&, const PHE::Object&) const;

private:
    int angle = 0;

    static constexpr int MAX_ANGLE = 45;
    static constexpr int STEP = 1;
};

} // namespace PHEApp