#pragma once


#include "vectors.hpp"


namespace PHEApp {

class Engine {
public:
    void update();
    void evalForce(PHE::Vector2f&);
};

} // namespace PHEApp