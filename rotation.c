//
// Created by kaylor on 8/14/21.
//
#include "rotation.h"

double norm(vector3D *v) {
    return sqrt(v->x * v->x + v->y * v->y + v->z * v->z);
}

vector3D unitVector(vector3D *v) {
    vector3D result;
    double mod = norm(v);
    result.x = v->x / mod;
    result.y = v->y / mod;
    result.z = v->z / mod;
    return result;
}

matrix33 rotationMatrix(vector3D *v, double theta) {
    vector3D u = unitVector(v);
    double halfTheta_rad = M_PI * theta / 360.0;
    double a = cos(halfTheta_rad);
    double b = sin(halfTheta_rad) * u.x;
    double c = sin(halfTheta_rad) * u.y;
    double d = sin(halfTheta_rad) * u.z;
    matrix33 res;
    res.array[0][0] = 1 - 2 * c * c - 2 * d * d;
    res.array[0][1] = 2 * b * c - 2 * a * d;
    res.array[0][2] = 2 * a * c + 2 * b * d;
    res.array[1][0] = 2 * b * c + 2 * a * d;
    res.array[1][1] = 1 - 2 * b * b - 2 * d * d;
    res.array[1][2] = 2 * c * d - 2 * a * b;
    res.array[2][0] = -2 * a * c + 2 * b * d;
    res.array[2][1] = 2 * c * d + 2 * a * b;
    res.array[2][2] = 1 - 2 * b * b - 2 * c * c;
    return res;
}

vector3D rotationResult(matrix33 *M, vector3D *v) {
    vector3D res;
    res.x = M->array[0][0] * v->x + M->array[0][1] * v->y + M->array[0][2] * v->z;
    res.y = M->array[1][0] * v->x + M->array[1][1] * v->y + M->array[1][2] * v->z;
    res.z = M->array[2][0] * v->x + M->array[2][1] * v->y + M->array[2][2] * v->z;
    return res;
}
