#ifndef _DRIVE_HPP_
#define _DRIVE_HPP_

#include "main.h"

namespace drive {
    void init();

    void arcadeDrive(double throttle, double rotation);

    void tankDrive(double left, double right);
}

#endif
