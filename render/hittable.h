#ifndef _HITTABLE_H_
#define _HITTABLE_H_

#include "Interval.h"
#include "Ray.h"
#include "Vec.h"
class HitRecord
{
public:
    Point3d p;
    Vec3d   normal;
    double  t;

    bool front_face = false;

    void set_face_normal(const Ray& r, const Vec3d& outward_normal)
    {
        front_face = r.dir().dot(outward_normal) < 0;
        normal     = front_face ? outward_normal : -outward_normal;
    }
};

class Hittable
{
public:
    virtual ~Hittable() = default;

    virtual bool hit(const Ray& r, interval ray_t, HitRecord& rec) const = 0;
};

#endif  // _HITTABLE_H_