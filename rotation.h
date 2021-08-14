//
// Created by kaylor on 8/14/21.
//

#ifndef ROTATION_ROTATION_H
#define ROTATION_ROTATION_H

#include "math.h"

typedef struct Vector_3D {
    double x;
    double y;
    double z;
} vector3D;

typedef struct Matrix_33 {
    double array[3][3];
} matrix33;

double norm(vector3D *v);

vector3D unitVector(vector3D *v);

matrix33 rotationMatrix(vector3D *v, double theta);

vector3D rotationResult(matrix33 *M, vector3D *v);

#endif //ROTATION_ROTATION_H
