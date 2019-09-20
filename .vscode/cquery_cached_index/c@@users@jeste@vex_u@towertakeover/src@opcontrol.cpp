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
	okapi::ControllerButton buttonB(okapi::ControllerDigital::B);
	okapi::ControllerButton buttonX(okapi::ControllerDigital::X);
	okapi::ControllerButton buttonA(okapi::ControllerDigital::A);
	okapi::ControllerButton buttonY(okapi::ControllerDigital::Y);
	// okapi::ControllerButton buttonLB(E_CONTROLLER_DIGITAL_L1);
	// okapi::ControllerButton buttonLT(E_CONTROLLER_DIGITAL_L2);
	// okapi::ControllerButton buttonRB(E_CONTROLLER_DIGITAL_R1);
	// okapi::ControllerButton buttonRT(E_CONTROLLER_DIGITAL_R2);

	// arcade controls
	double throttle;
	double rotation;
	while(true) {

		// setting throttle to the
		throttle = master.getAnalog(okapi::ControllerAnalog::rightX);
		rotation = master.getAnalog(okapi::ControllerAnalog::leftY);
		drive::arcadeDrive(-throttle, rotation);

		// wait and give unnecessary time to other tasks
		// motor telemetry, joystick values, etc. update every 10ms
		pros::delay(10);
	}

	if(buttonA.isPressed()) {
		// values 0-200
		manipulator::intake(12000);
	}

	else if(buttonB.isPressed()) {
		// values 0-200
		manipulator::outtake(12000);
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
