#include "main.h"

using namespace okapi;

std::unique_ptr<okapi::Motor> manipulatorLeft;
std::unique_ptr<okapi::Motor> manipulatorRight;

namespace manipulator {

    void init() {
        manipulatorLeft = std::make_unique<okapi::Motor>(MANIPULATOR_LEFT);
        manipulatorRight = std::make_unique<okapi::Motor>(MANIPULATOR_RIGHT);
    }

    /** manipulator:
     *  spin the left motor clockwise
     *  spin the right motor counterclockwise
     */
     void intake(double velocity) {
         manipulatorLeft->moveVelocity(velocity);
         manipulatorLeft->moveVelocity(-velocity);
     }

     /** outtake:
      *  spin the left motor counterclockwise
      */
      void outtake(double velocity) {
          manipulatorLeft->moveVelocity(-velocity);
          manipulatorRight->moveVelocity(velocity);
      }

      void stopManipulator() {
          manipulatorLeft->moveVelocity(0);
          manipulatorRight->moveVelocity(0);
      }
}
