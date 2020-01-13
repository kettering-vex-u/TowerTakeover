#include "main.h"

using namespace okapi;

std::shared_ptr<okapi::ChassisControllerIntegrated> chassis;
std::unique_ptr<okapi::Motor> driveFL, driveFR, driveRL, driveRR;
std::unique_ptr<okapi::Motor> pivotFL, pivotFR, pivotRL, pivotRR;

const int DRIVE_FL = DRIVE_FRONT_LEFT;
const int DRIVE_FR = DRIVE_FRONT_RIGHT;
const int DRIVE_RL = DRIVE_REAR_LEFT;
const int DRIVE_RR = DRIVE_REAR_RIGHT;

const int PIVOT_FL = PIVOT_FRONT_LEFT;
const int PIVOT_FR = PIVOT_FRONT_RIGHT;
const int PIVOT_RL = PIVOT_REAR_LEFT;
const int PIVOT_RR = PIVOT_REAR_RIGHT;

const auto WHEEL_DIAMETER = 3_in;
const auto CHASSIS_WIDTH = 15_in;

namespace swerve {

	void init() {
		// creating a ChassisControl object using the MotorGroups defined above,
		// setting the gearset to red (36:1, 100rpm),
		// setting the wheel diameter to 3.5in,
		// and setting the drivetrain width to 24in
		
}
