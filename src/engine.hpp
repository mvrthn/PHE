#pragma once


#include "component.hpp"
#include "evaluator.hpp"


namespace PHEApp {

class Engine : Component, public PHE::Evaluator {
public:
    void update(InputType&);
    void display(sf::RenderTarget&);
    
    void eval(PHE::Vector2f&, const PHE::Object&) const;

private:
    static constexpr int MIN_RPM = 1000;
    static constexpr int MAX_RPM = 3000;
    static constexpr int STEP = 100;

    int rpm = MIN_RPM;
    int gear = 0;
};

} // namespace PHEApp