#pragma once


#include <array>

#include "vectors.hpp"
#include "force.hpp"


template<int Size>
struct Model {
    Model(int m, int i, PHE::Vector2f c, std::array<PHE::Force, Size> f): mass(m), inertia(i), center(c), force(f) {};

    const int mass;
    const int inertia;
    const PHE::Vector2f center;
    const std::array<PHE::Force, Size> force;
};

struct ModelX : public Model<3> {
    ModelX(): Model(1, 1, {0, 0}, {PHE::Force({0, 0}, nullptr), PHE::Force({0, 0}, nullptr), PHE::Force({0, 0}, nullptr)}) {}; 
};