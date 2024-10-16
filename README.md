# 3D Rotation in C
A Matrix is a algebraic type of table or array comparable to a 2D array in programming.
We can use matrices (3 for each axis) for calculating the rotation of a vertex around an axis with degrees or radians. 
(whatever your trigonometry functions are set at) <br>
Example:
```c
cos(90) = 0 / sin(90) = 1
          [  1       0        0     ] [ 0 ]   [ 0 ] ( 1*0  +  0*1  +  0*0 )
 Rx(90) = [  0    cos(90) -sin(90)  ] [ 1 ] = [ 0 ] ( 0*0  +  0*1  + -1*0 )
          [  0    sin(90)  cos(90)  ] [ 0 ]   [ 1 ] ( 0*0  +  1*1  +  0*0 )

      [ 0 ]   [ 0 ] X Coordinate
Rx(90)[ 1 ] = [ 0 ] Y Coordinate
      [ 0 ]   [ 1 ] Z Coordinate
so the output would be (0, 0, 1) 
```

* testmatrix.c - For your own authentication of the functions I provide in the header
* rmatrix.h - For the functions
## The Functions
#1:
```c
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
```
RMX is short for Rotation Matrix - X Axis Rotation <br>
Since a function cant return 3 values, thats where the output parameter comes in, if output=1 you will get the x, output=2 you will get the y, output=3 you will get the z. <br>
Theta is the degrees of rotation. <br>
#2:
```c
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
```
RMY is short for Rotation Matrix - Y Axis Rotation <br>
#3:
```c

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
```
RMZ is short for Rotation Matrix - Z Axis Rotation <br>
