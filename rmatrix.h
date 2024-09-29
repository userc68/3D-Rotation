#ifndef RMATRIX_H
#define RMATRIX_H

#include <math.h>

#define M_PI 3.14159265358979323846

#define ERROR 1

#define X_OUTPUT 1
#define Y_OUTPUT 2
#define Z_OUTPUT 3

// COS AND SIN FUNCTIONS IN THE STANDARD C LIBRARY EXPECT THE ANGLE TO BE IN RADIANS
// THUS THE REASON FOR CONVERTING DEGREES TO RADIANS

// ROTATION MATRIX FOR AXIS X / RMX
//
//         [  1      0          0    ]
// Rx(θ) = [  0    cos(θ)   -sin(θ)  ]
//         [  0    sin(θ)    cos(θ)  ]
//

double rmx(short output, double x, double y, double z, double theta) {
  double radians = theta * (M_PI / 180);
  switch (output) {
    case X_OUTPUT: // 1
      return x;
    case Y_OUTPUT: // 2
      return (0 * x) + (cos(radians) * y) + (-sin(radians) * z);
    case Z_OUTPUT: // 3
      return (0 * x) + (sin(radians) * y) + (cos(radians) * z);
    default:
      return ERROR;
  }
}

// ROTATION MATRIX FOR AXIS Y / RMY
//
//         [  cos(θ)   0   sin(θ)   ]
// Ry(θ) = [    0      1      0     ]
//         [ -sin(θ)   0   cos(θ)   ]
//

double rmy(short output, double x, double y, double z, double theta) {
  double radians = theta * (M_PI / 180);
  switch (output) {
    case X_OUTPUT: // 1
      return (cos(radians) * x) + (0 * y) + (sin(radians) * z);
    case Y_OUTPUT: // 2
      return y;
    case Z_OUTPUT: // 3
      return (-sin(radians) * x) + (0 * y) + (cos(radians) * z);
    default:
      return ERROR;
  }
}

// ROTATION MATRIX FOR AXIS Z / RMZ 
//
//         [  cos(θ)   -sin(θ)   0   ]
// Rz(θ) = [  sin(θ)    cos(θ)   0   ]
//         [    0         0      1   ]
// 

double rmz(short output, double x, double y, double z, double theta) {
  double radians = theta * (M_PI / 180);
  switch (output) {
    case X_OUTPUT: // 1
      return (cos(radians) * x) + (-sin(radians) * y) + (0 * z);
    case Y_OUTPUT: // 2
      return (sin(radians) * x) + (cos(radians) * y) + (0 * z);
    case Z_OUTPUT: // 3
      return z;
    default:
      return ERROR;
  }
}

#undef X_OUTPUT
#undef Y_OUTPUT
#undef Z_OUTPUT
#undef ERROR

#endif