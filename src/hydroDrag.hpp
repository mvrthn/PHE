#pragma once


#include "object.hpp"


namespace PHEApp {

namespace HydroDrag {

void evalProgForce(PHE::Vector2f&, const PHE::Object&);
void evalRotaForce(PHE::Vector2f&, const PHE::Object&);

} // namespace HydroDrag

} // namespace PHEApp
