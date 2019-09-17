#include "main.h"

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *p
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */

okapi::Controller master(master);

// opcontrol:
// allows the user to control the robot
// setting drive controls and mechanism controls
void opcontrol() {

	// initalizing all buttons
	okapi::ControllerButton buttonA(okapi::ControllerDigital::A);
	okapi::ControllerButton buttonB(okapi::ControllerDigital::B);
	okapi::ControllerButton buttonX(okapi::ControllerDigital::X);
	okapi::ControllerButton buttonY(okapi::ControllerDigital::Y);

	// arcade controls
	double throttle;
	double rotation;
	while(true) {
		throttle = master.getAnalog(okapi::ControllerAnalog::rightX);
		rotation = master.getAnalog(okapi::ControllerAnalog::leftY);
		drive::arcadeDrive(-throttle, rotation);
	}

	if(buttonA.isPressed()) {
		manipulator::intake(7500);
	}

	else if(buttonB.isPressed()) {
		manipulator::outtake(7500);
	}

	else {
		manipulator::stopManipulator();
	}

	// // tank controls
	// double left;
	// double right;
	// while(true) {
	// 	left = master.getAnalog(okapi::ControllerAnalog::leftY);
	// 	right = master.getAnalog(okapi::ControllerAnalog::rightY);
	// 	drive::tankDrive(left, right);
	// }
}
