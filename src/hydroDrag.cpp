#include "hydroDrag.hpp"


namespace PHEApp {

void HydroDrag::evalProgForce(PHE::Vector2f& vector, const PHE::Object& object) {
    const PHE::Vector2f& v = object.getVelocity();
    const float p = 0.5;
    vector = {-p * v.x * v.x, -p * v.y * v.y};
}

void HydroDrag::evalRotaForce(PHE::Vector2f& vector, const PHE::Object& object) {
    const float v = object.getRotationSpeed();
    const float p = 0.5;
    vector = {0, 0};
}

} // namespace PHEApp