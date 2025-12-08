#pragma once

#include "EZ-Template/api.hpp"
#include "api.h"

extern Drive chassis;


inline pros::Motor Intake1(10);
inline pros::Motor Intake2(-3);

// Sensores
inline pros::Optical ColorSortSensor(9);
inline pros::Imu IMU(15);

// Salidas digitales
inline pros::ADIDigitalOut CenterGoal('A');
inline pros::ADIDigitalOut MatchLoad('B');
inline pros::ADIDigitalOut Descore('C');
// Your motors, sensors, etc. should go here.  Below are examples

// inline pros::Motor intake(1);
// inline pros::adi::DigitalIn limit_switch('A');