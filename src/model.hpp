#pragma once


#include "vectors.hpp"


namespace PHEApp {

namespace Model {

constexpr float mass = 1;
constexpr float inertia = 1;
constexpr PHE::Vector2f rudderPos = {0, 128};
constexpr PHE::Vector2f propellerPos = {0, 96};
constexpr PHE::Vector2f centerOfProgDrag = {0, 0};
constexpr PHE::Vector2f centerOFRotaDrag = {0, 0};

} // namespace Model

} // namesapce PHEApp