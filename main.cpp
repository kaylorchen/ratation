#include <iostream>
#include "stdio.h"
#include "rotation.h"

int main() {
    vector3D origin = {1 ,1 ,1};
    vector3D v = {-1, 1, 0};
    double theta = 45.0;
    matrix33 M = rotationMatrix(&v,theta);
    vector3D result = rotationResult(&M, &origin);
    printf("result is (%f, %f, %f)\n",result.x, result.y, result.z);
    return 0;
}
