#ifndef _SWERVE_HPP_
#define _SWERVE_HPP_

#include "main.h"

namespace swerve {
    void init();
    void swerveDrive(double throttle, double strafe, double rotation);
}

#endif
