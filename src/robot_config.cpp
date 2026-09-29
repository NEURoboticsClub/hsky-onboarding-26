#include "robot_config.hpp"

#include <hskylib/robot_specs.h>
#include <hskylib/subsystems/pneumatics.h>
#include <hskylib/utils/utils.h>

#include "pros/adi.hpp"
#include "pros/motors.h"
#include "pros/motor_group.hpp"

#define ROBOT_1

HskyController controller(pros::E_CONTROLLER_MASTER);

//---------------------------------------------------
// ##################### Robot 1 #####################
//---------------------------------------------------

#ifdef ROBOT_1

//===================== CONFIG =====================

//===================== DEVICES =====================
pros::MotorGroup leftDriveMotors({1, 2, 3});
pros::MotorGroup rightDriveMotors({4, 5, 6});


//==================== SUBSYSTEMS ====================
// TankDrive driveBase(leftDriveMotors, rightDriveMotors,
// 					pros::E_MOTOR_BRAKE_COAST, pros::E_MOTOR_GEAR_600, 1.0,
// 					0.75);

//---------------------------------------------------
// ##################### Robot 2 #####################
//---------------------------------------------------

#elifdef ROBOT_2

//===================== CONFIG =====================

//===================== DEVICES =====================

//==================== SUBSYSTEMS ====================

#endif

//====================== UTILS ======================

void deviceInit() {}

void opcontrolInit() {
    controller.ButtonA.onPressed([]{} { leftDriveMotors.move(62); });
    controller.ButtonB.onPressed([]{} { rightDriveMotors.move(62); });
    
    controller.ButtonA.onReleased([]() { leftDriveMotors.move(0); });
    controller.ButtonB.onReleased([]() { rightDriveMotors.move(0); });
}

void robotInit() { deviceInit(); }