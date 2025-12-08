#pragma once

#include "EZ-Template/api.hpp"
#include "api.h"

extern Drive chassis;


inline pros::Motor Intake1(-1);
inline pros::Motor Intake2(-5);

// Sensores
inline pros::Optical ColorSortSensor(10);
inline pros::Imu IMU(2);

// Salidas digitales
inline pros::ADIDigitalOut CenterGoal('A');
inline pros::ADIDigitalOut MatchLoad('D');
inline pros::ADIDigitalOut Descore('C');
// Your motors, sensors, etc. should go here.  Below are examples

// inline pros::Motor intake(1);
// inline pros::adi::DigitalIn limit_switch('A');