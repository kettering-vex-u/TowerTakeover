#include "main.h"
#include <math.h>

using namespace okapi;

std::shared_ptr<okapi::ChassisControllerIntegrated> chassis;
std::unique_ptr<okapi::Motor> driveFL, driveFR, driveRL, driveRR;
std::unique_ptr<okapi::Motor> rotateFL, rotateFR, rotateRL, rotateRR;

const int DRIVE_FL = DRIVE_FRONT_LEFT;
const int DRIVE_FR = DRIVE_FRONT_RIGHT;
const int DRIVE_RL = DRIVE_REAR_LEFT;
const int DRIVE_RR = DRIVE_REAR_RIGHT;

const int ROTATE_FL = ROTATE_FRONT_LEFT;
const int ROTATE_FR = ROTATE_FRONT_RIGHT;
const int ROTATE_RL = ROTATE_REAR_LEFT;
const int ROTATE_RR = ROTATE_REAR_RIGHT;

const double WHEELBASE = 3.0;
const double CHASSIS_WIDTH = 15.0;

namespace swerve {

	double temp;	
	double wheelbase = 3.0;
	double chassisWidth = 15.0;
	double ratio;
	double a, b, c, d;
	double wheelSpeedFrontLeft, wheelSpeedFrontRight,
		   wheelSpeedRearLeft, wheelSpeedRearRight;
	double wheelAngleFrontLeft, wheelAngleFrontRight,
	       wheelAngleRearLeft, wheelAngleRearRight;

	double radToDeg = 180/3.14159265358979;
	double maxSpeed;

	void init() {

	}

	void swerveDrive(double throttle, double strafe, double rotation) {
		temp = (throttle * cos(gyroAngle)) + (strafe * sin(gyroAngle));
		strafe = (-throttle * sin(gyroAngle)) + (strafe * cos(gyroAngle));
		throttle = temp;

		ratio = sqrt(pow(wheelbase, 2) + pow(chassisWidth, 2));
		a = strafe - (rotation * (wheelbase / ratio));
		b = strafe + (rotation * (wheelbase / ratio));
		c = throttle - (rotation * (chassisWidth / ratio));
		d = throttle + (rotation * (chassisWidth / ratio));

		wheelSpeedFrontLeft = sqrt(pow(b, 2) + pow(c, 2));
		wheelSpeedFrontRight = sqrt(pow(b, 2) + pow(d, 2));
		wheelSpeedRearLeft = sqrt(pow(a, 2) + pow(d, 2));
		wheelSpeedRearRight = sqrt(pow(a, 2) + pow(c, 2));

		wheelAngleFrontLeft = atan2(b, c) * radToDeg;
		wheelAngleFrontRight = atan2(b, d) * radToDeg;
		wheelAngleRearLeft = atan2(a, c) * radToDeg;
		wheelAngleRearRight = atan2(a, d) * radToDeg;

		maxSpeed = wheelSpeedFrontLeft;
		if (wheelSpeedFrontRight > maxSpeed) {
			maxSpeed = wheelSpeedFrontRight;
		}
		if (wheelSpeedRearLeft > maxSpeed) {
			maxSpeed = wheelSpeedRearLeft;
		}
		if (wheelSpeedRearRight > maxSpeed) {
			maxSpeed = wheelSpeedRearRight;
		}

		if (maxSpeed > 1) {
			wheelSpeedFrontLeft /= maxSpeed;
			wheelSpeedFrontRight /= maxSpeed;
			wheelSpeedRearLeft /= maxSpeed;
			wheelSpeedRearRight /= maxSpeed;
		}
	}

}
