#include "main.h"

using namespace okapi;

std::unique_ptr<okapi::Motor> manipulator_l;
std::unique_ptr<okapi::Motor> manipulator_r;

const int MANIPULATOR_L = MANIPULATOR_LEFT;
const int MANIPULATOR_R = MANIPULATOR_RIGHT;

namespace manipulator {

    void init() {
        manipulator_l = std::make_unique<okapi::Motor>(MANIPULATOR_LEFT);
        manipulator_r = std::make_unique<okapi::Motor>(MANIPULATOR_RIGHT);
    }

    /** manipulator:
     *  spin the left motor clockwise
     *  spin the right motor counterclockwise
     */
     void intake(double velocity) {
         manipulator_l->moveVelocity(velocity);
         manipulator_l->moveVelocity(-velocity);
     }

     /** outtake:
      *  spin the left motor counterclockwise
      */
      void outtake(double velocity) {
          manipulator_l->moveVelocity(-velocity);
          manipulator_r->moveVelocity(velocity);
      }

      void stopManipulator() {
          manipulator_l->moveVelocity(0);
          manipulator_r->moveVelocity(0);
      }
}
