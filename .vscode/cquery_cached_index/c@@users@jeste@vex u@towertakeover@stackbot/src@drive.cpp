#include "main.h"
#include "robot.h"
#include "okapi/api.hpp"

using namespace okapi;

std::shared_ptr<ChassisControllerIntegrated> controller;
std::unique_ptr<Motor> dl1, dl2, dl3;
std::unique_ptr<Motor> dr1, dr2, dr3;
std::unique_ptr<Controller> master;

namespace drive {

	void init() {
		// creating a ChassisControl object using the MotorGroups defined above,
		// setting the gearset to red (36:1, 100rpm),
		// setting the wheel diameter to 3.5in,
		// and setting the drivetrain width to 24in
		controller = ChassisControllerFactory::createPtr(
			{DRIVE_LEFT_1, DRIVE_LEFT_2, DRIVE_LEFT_3},
			{DRIVE_RIGHT_1, DRIVE_RIGHT_2, DRIVE_RIGHT_3},
			AbstractMotor::gearset::red,
			{3.5_in, 24_in}
		);

		dl1 = std::make_unique<Motor>(DRIVE_LEFT_1);
		dl2 = std::make_unique<Motor>(DRIVE_LEFT_2);
		dl3 = std::make_unique<Motor>(DRIVE_LEFT_3);
		dr1 = std::make_unique<Motor>(DRIVE_RIGHT_1, true);
		dr2 = std::make_unique<Motor>(DRIVE_RIGHT_2, true);
		dr3 = std::make_unique<Motor>(DRIVE_RIGHT_3, true);
	}

	// arcade drive control:
	// left joystick controls throttle,
	// right joystick controls rotation
	void arcadeDrive(double throttle, double rotation) {
		controller->arcade(throttle, rotation);
	}

	// tank drive control:
	// left joystick controls left side,
	// right joystick controls right side
	void tankDrive(double left, double right) {
		controller->tank(left, right);
	}
}
