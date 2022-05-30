#include "point2d.h"
#include <stdlib.h>
#include <math.h>

struct _p {
    double x, y;
};

typedef struct _p Point2D;


Point2D *point2D_new(double x, double y) {
    Point2D *p = malloc(sizeof(Point2D));
    p->x = x;
    p->y = y;
    return p;
}


void point2D_destroy(Point2D *p) {
    free(p);    
}

double point2D_get_x(Point2D *p) {
    return p->x;
}

double point2D_get_y(Point2D *p) {
    return p->y;
}

Point2D *point2D_add(Point2D *p1, Point2D *p2) {
    return point2D_new(point2D_get_x(p1) + point2D_get_x(p2), point2D_get_y(p1) + point2D_get_y(p2));
}

double point2D_theta(Point2D *p1, Point2D *p2) {
    return atan2(point2D_get_y(p2) - point2D_get_y(p1), point2D_get_x(p2) - point2D_get_x(p1));
}

Point2D *point2D_scale(Point2D *p, double s) {
    return point2D_new(point2D_get_x(p) * s, point2D_get_y(p) * s);
}

