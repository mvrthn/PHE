#pragma once


#include <cassert>


namespace PHEApp {

enum InputType : int {
    NONE = 0,
    RUDDER = 1,
    RUDDER_LEFT = 2 + RUDDER,
    RUDDER_RIGHT = 4 + RUDDER,
    RUDDER_ZERO = 8 + RUDDER,
    ENGINE = 16,
    RPM_UP = 32 + ENGINE,
    RPM_DOWN = 64 + ENGINE,
    GEAR_UP = 128 + ENGINE,
    GEAR_DOWN = 256 + ENGINE
};

constexpr InputType operator~(InputType it) { return InputType(~int(it)); }
constexpr InputType operator|(InputType it1, InputType it2) { return InputType(int(it1) | int(it2)); }
constexpr InputType& operator|=(InputType& it1, InputType it2) { return it1 = it1 | it2; }
constexpr InputType operator&(InputType it1, InputType it2) { return InputType(int(it1) & int(it2)); }
constexpr InputType& operator&=(InputType& it1, InputType it2) { return it1 = it1 & it2; }

template<int LOW, int HIGH, int STEP>
class Var {
public:
    inline void up() { dest = std::min(dest + STEP, HIGH); }
    inline void down() { dest = std::max(dest - STEP, LOW); }
    inline void set(int d) { assert(d >= LOW && d <= HIGH); dest = d; }
    inline void update() { 
        if(value < dest) value = std::max(value - STEP, dest); 
        else value = std::min(value + STEP, dest); 
    }

private:
    int value;
    int dest;
};

} // namespace PHEApp