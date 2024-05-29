#ifndef _SPHERE_H_
#define _SPHERE_H_

#include "hittable.h"
class Sphere : public Hittable
{
public:
    Point3d center;
    double  radius;
    Sphere() = default;
    Sphere(Point3d c, double r) : center(c), radius(r)
    {
    }  // constructor

    bool hit(const Ray& r, interval ray_t, HitRecord& rec) const override
    {
        Vec3d  oc           = r.origin() - center;
        double a            = r.dir().squaredNorm();
        double b            = 2.0 * r.dir().dot(oc);
        double c            = oc.squaredNorm() - radius * radius;
        double discriminant = b * b - 4 * a * c;
        if (discriminant < 0) {
            return false;
        } else {
            double t = (-b - sqrt(discriminant)) / (2.0 * a);
            if (t < ray_t.min || t > ray_t.max) {
                t = (-b + sqrt(discriminant)) / (2.0 * a);
                if (t < ray_t.min || t > ray_t.max) {
                    return false;
                }
            }
            rec.t                = t;
            rec.p                = r.at(t);
            Vec3d outward_normal = (rec.p - center) / radius;
            rec.set_face_normal(r, outward_normal);
            return true;
        }
    }
};

#endif  // _SPHERE_H_