#ifndef _CAMERA_H_
#define _CAMERA_H_
#include <QImage>

#include "Vec.h"
#include "hittable.h"
#include "rt.h"
#define IMAGE_WIDTH  800
#define IMAGE_HEIGHT 600
class camera
{
public:
    camera() : image(IMAGE_WIDTH, IMAGE_HEIGHT, QImage::Format_RGB32)
    {
    }
    void render(const HittableList& world)
    {
        initialize();
        auto viewport_height = 2.0;
        auto aspect_ratio    = double(image.width()) / image.height();
        auto viewport_width  = viewport_height * (image.width() / image.height());

        image.fill(QColor(0, 0, 0));
        for (int j = 0; j < image.height(); j++) {
            for (int i = 0; i < image.width(); i++) {
                auto  pixel_center = pixel00_loc + i * pixel_delta_u + j * pixel_delta_v;
                auto  ray_dir      = pixel_center - center;
                Ray   r(center, ray_dir);
                Color pixel_color = ray_color(r, world);
                setPixel(image, i, j, pixel_color);
            }
        }
    }
    void setPixel(QImage& image, int x, int y, Color color)
    {
        int rbyte = int(255.999 * color.x());
        int gbyte = int(255.999 * color.y());
        int bbyte = int(255.999 * color.z());
        image.setPixel(x, y, qRgb(rbyte, gbyte, bbyte));
    }

private:
    void initialize()
    {
        auto focal_length    = 1.0;
        auto viewport_height = 2.0;
        auto viewport_width  = viewport_height * (double(image.width()) / image.height());

        // Calculate the vectors across the horizontal and down the vertical viewport edges.
        auto viewport_u = Vec3d(viewport_width, 0, 0);
        auto viewport_v = Vec3d(0, -viewport_height, 0);

        // Calculate the horizontal and vertical delta vectors from pixel to pixel.
        pixel_delta_u = viewport_u / image.width();
        pixel_delta_v = viewport_v / image.height();

        // Calculate the location of the upper left pixel.
        auto viewport_upper_left = center - Vec3d(0, 0, focal_length) - viewport_u / 2 - viewport_v / 2;
        pixel00_loc              = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);
    }
    Color ray_color(const Ray& r, const Hittable& world) const
    {
        HitRecord rec;
        if (world.hit(r, interval(0.001, infinity), rec)) {
            return 0.5 * (rec.normal + Color(1, 1, 1));
        }

        Vec3d  unit_direction = r.dir().normalized();
        double a              = 0.5 * (unit_direction.y() + 1.0);

        return (1.0 - a) * Color(1.0, 1.0, 1.0) + a * Color(0.5, 0.7, 1.0);
    }

public:
    QImage image;

private:
    int     image_height;   // Rendered image height
    Point3d center;         // Camera center
    Point3d pixel00_loc;    // Location of pixel 0, 0
    Vec3d   pixel_delta_u;  // Offset to pixel to the right
    Vec3d   pixel_delta_v;  // Offset to pixel below
};

#endif