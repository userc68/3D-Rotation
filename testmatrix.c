#include <math.h>
#include <stdio.h>
#include <string.h>

#define M_PI 3.14159265358979323846
#define ERROR 1

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
    case 1: // x
      return x;
    case 2: // y
      return (0 * x) + (cos(radians) * y) + (-sin(radians) * z);
    case 3: // z
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
    case 1: // x
      return (cos(radians) * x) + (0 * y) + (sin(radians) * z);
    case 2: // y
      return y;
    case 3: // z
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
    case 1: // x
      return (cos(radians) * x) + (-sin(radians) * y) + (0 * z);
    case 2: // y
      return (sin(radians) * x) + (cos(radians) * y) + (0 * z);
    case 3: // z
      return z;
    default:
      return ERROR;
  }
}

int main() {
  double x, y, z, theta;
  char axis[1];

  printf("X: ");
  scanf("%lf", &x);

  printf("Y: ");
  scanf("%lf", &y);

  printf("Z: ");
  scanf("%lf", &z);

  printf("Theta: ");
  scanf("%lf", &theta);

  printf("Axis: ");
  scanf("%s", axis);

  if (strcmp(axis, "x") == 0 || strcmp(axis, "X") == 0) {
    printf("OUTPUT: (%f, %f, %f)",
      rmx(1, x, y, z, theta),
      rmx(2, x, y, z, theta),
      rmx(3, x, y, z, theta));
  }
  else if (strcmp(axis, "y") == 0 || strcmp(axis, "Y") == 0) {
    printf("OUTPUT: (%f, %f, %f)",
      rmy(1, x, y, z, theta),
      rmy(2, x, y, z, theta),
      rmy(3, x, y, z, theta));
  }
  else if (strcmp(axis, "z") == 0 || strcmp(axis, "Z") == 0) {
    printf("OUTPUT: (%f, %f, %f)",
      rmz(1, x, y, z, theta),
      rmz(2, x, y, z, theta),
      rmz(3, x, y, z, theta));
  }
  else {
    printf("ERROR: Invalid axis of Rotation");
  }
  return 0;
}