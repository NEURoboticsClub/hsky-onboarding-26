#ifndef ROBOT_CONFIG_HPP
#define ROBOT_CONFIG_HPP

#include <vector>

#include "api.h"
#include "hskylib.h"

extern HskyController controller;
// extern TankDrive driveBase;
extern pros::MotorGroup leftDriveMotors;
extern pros::MotorGroup MotorGroup rightDriveMotors;

void opcontrolInit();
void robotInit();

#endif