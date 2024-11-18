#pragma once


#include <cmath>
#include <iostream>


namespace PHE {

struct Vector2f {
    float x;
    float y;

    Vector2f() = default;
    Vector2f(float _x, float _y): x(_x), y(_y) {};
    Vector2f(const Vector2f& other): x(other.x), y(other.y) {};

    // value of vector
    constexpr float operator()() const { return sqrt(pow(this->x, 2) + pow(this->y, 2)); };
};

constexpr Vector2f operator-(const Vector2f& v) { return Vector2f(-v.x, -v.y); }

constexpr Vector2f operator+(const Vector2f& v1, const Vector2f& v2) { return Vector2f(v1.x + v2.x, v1.y + v2.y); }
constexpr Vector2f operator-(const Vector2f& v1, const Vector2f& v2) { return Vector2f(v1.x - v2.x, v1.y - v2.y); }

constexpr Vector2f& operator+=(Vector2f& v1, const Vector2f& v2) { return v1 = v1 + v2; }
constexpr Vector2f& operator-=(Vector2f& v1, const Vector2f& v2) { return v1 = v1 - v2; }

constexpr Vector2f operator*(float a, const Vector2f& v) { return Vector2f(a * v.x, a * v.y); }
constexpr Vector2f operator*(const Vector2f& v, float a) { return Vector2f(a * v.x, a * v.y); }
constexpr Vector2f operator/(float a, const Vector2f& v) { return Vector2f(a / v.x, a / v.y); }
constexpr Vector2f operator/(const Vector2f& v, float a) { return Vector2f(a / v.x, a / v.y); }

constexpr Vector2f& operator*=(Vector2f& v, float a) { return v = v * a; };
constexpr Vector2f& operator/=(Vector2f& v, float a) { return v = v / a; };

constexpr float operator*(const Vector2f& v1, const Vector2f& v2) { return v1.x * v2.x + v1.y * v2.y; }

// vector product: v(x, y, 0) & u(x, y, 0) = (0, 0, z)
constexpr float operator&(const Vector2f& v1, const Vector2f& v2) { return v1.x * v2.y - v1.y * v2.x; }

constexpr std::ostream& operator<<(std::ostream& os, const Vector2f& v) {
    os << "[" << v.x << ", " << v.y << "]";
    return os;
}

} // namespace PHE