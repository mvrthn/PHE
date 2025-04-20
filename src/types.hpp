#pragma once


namespace PHEApp {

enum InputType {
    RUDDER = 0,
    RUDDER_LEFT,
    RUDDER_RIGHT,
    RUDDER_ZERO,
    RPM = 8,
    RPM_UP,
    RPM_DOWN,
    GEAR = 16,
    GEAR_UP,
    GEAR_DOWN
};

} // namespace PHEApp