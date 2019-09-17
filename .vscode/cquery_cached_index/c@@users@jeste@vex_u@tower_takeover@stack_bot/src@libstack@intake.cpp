#include "main.h"

using namespace okapi;

std::unique_ptr<okapi::Motor> intake_l;
std::unique_ptr<okapi::Motor> intake_r;

const int INTAKE_L = INTAKE_LEFT;
const int INTAKE_R = INTAKE_RIGHT;

namespace intake {

    void init() {
        intake_l = std::make_unique<okapi::Motor>(INTAKE_L);
        intake_r = std::make_unique<okapi::Motor>(INTAKE_R);
    }

    /** intake:
     *  spin the left motor clockwise
     *  spin the right motor counterclockwise
     */
     void intake(double power) {
         intake_l->move(power);
         intake_l->move(-power);
     }

     /** outtake:
      *  spin the left motor counterclockwise
      *  spin the right motor clockwise
      */
      void outtake(double power) {
          intake_l->move(-power);
          intake_l->move(power);
      }
}
