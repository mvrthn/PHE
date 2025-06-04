#include "evaluator.hpp"

#include <cmath>


namespace PHE {

void Evaluator::evalForce(Vector2f& vector, const Object& object) const {
    eval(vector, object);
    float rad = object.getRotationAngle() * DEG_TO_RAD;
    float sin = std::sin(rad);
    float cos = std::cos(rad);
    vector.x = vector.x * cos - vector.y * sin;
    vector.y = vector.x * sin + vector.y * cos;
}

} // namespace PHE