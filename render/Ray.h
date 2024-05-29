#ifndef _RAY_H_
#define _RAY_H_

#include "Vec.h"

class Ray
{
public:
    Vec3d origin_pos;
    Vec3d direction;
    Ray() = default;
    Ray(Vec3d orgn, Vec3d dir) : origin_pos(orgn), direction(dir)
    {
    }

    const Point3d origin() const
    {
        return origin_pos;
    }
    const Vec3d dir() const
    {
        return direction;
    }
    Point3d at(double t) const
    {
        return origin_pos + t * direction;
    }
};

#endif