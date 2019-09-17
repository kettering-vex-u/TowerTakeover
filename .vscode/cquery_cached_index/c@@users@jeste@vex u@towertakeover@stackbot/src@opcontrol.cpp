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
	// arcade controls
	double throttle;
	double rotation;
	while(true) {
		throttle = master.getAnalog(okapi::ControllerAnalog::leftY);
		rotation = master.getAnalog(okapi::ControllerAnalog::rightX);
		drive::arcadeDrive(-rotation, -throttle);
	}

	// // tank controls
	// double left;
	// double right;
	// while(true) {
	// 	left = master.getAnalog(okapi::ControllerAnalog::leftY);
	// 	right = master.getAnalog(okapi::ControllerAnalog::rightY);
	// 	drive::tankDrive(-left, right);
	// }
}
