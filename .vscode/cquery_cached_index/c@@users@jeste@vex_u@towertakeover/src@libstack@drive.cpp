#include "main.h"

using namespace okapi;

static std::shared_ptr<okapi::ChassisControllerIntegrated> chassis;
std::unique_ptr<okapi::Motor> dl1, dl2, dl3;
std::unique_ptr<okapi::Motor> dr1, dr2, dr3;

const int DRIVE_L_1 = DRIVE_LEFT_1;
const int DRIVE_L_2 = DRIVE_LEFT_2;
const int DRIVE_L_3 = DRIVE_LEFT_3;
const int DRIVE_R_1 = DRIVE_RIGHT_1;
const int DRIVE_R_2 = DRIVE_RIGHT_2;
const int DRIVE_R_3 = DRIVE_RIGHT_3;

const auto WHEEL_DIAMETER = 3_in;
const auto CHASSIS_WIDTH = 15_in;

namespace drive {

	void init() {
		// creating a ChassisControl object using the MotorGroups defined above,
		// setting the gearset to red (36:1, 100rpm),
		// setting the wheel diameter to 3.5in,
		// and setting the drivetrain width to 24in
		chassis = ChassisControllerFactory::createPtr(
			{DRIVE_L_1, DRIVE_L_2, DRIVE_L_3},
			{DRIVE_R_1, DRIVE_R_2, DRIVE_R_3},
			AbstractMotor::gearset::green,
			{WHEEL_DIAMETER, CHASSIS_WIDTH}
		);

		dl1 = std::make_unique<okapi::Motor>(DRIVE_L_1);
		dl2 = std::make_unique<okapi::Motor>(DRIVE_L_2);
		dl3 = std::make_unique<okapi::Motor>(DRIVE_L_3);
		dr1 = std::make_unique<okapi::Motor>(DRIVE_R_1);
		dr2 = std::make_unique<okapi::Motor>(DRIVE_R_2);
		dr3 = std::make_unique<okapi::Motor>(DRIVE_R_3);
	}

	/** arcade drive control:
	 *  left joystick controls throttle,
	 *  right joystick controls rotation
	 */
	void arcadeDrive(double throttle, double rotation) {
		chassis->arcade(throttle, rotation);
	}

	/** tank drive control:
	 *  left joystick controls left side,
	 *  right joystick controls right side
	 */
	void tankDrive(double left, double right) {
		chassis->tank(left, right);
	}
}
