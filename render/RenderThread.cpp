#include "RenderThread.h"

#include "Ray.h"
#include "Vec.h"
#include "rt.h"

#define IMAGE_WIDTH  800
#define IMAGE_HEIGHT 600
#include <memory>

#include "Sphere.h"
#include "camera.h"

using namespace std;
RenderThread::RenderThread(QObject* parent) : QThread(parent)
{
    world.add(make_shared<Sphere>(Point3d(0, 0, -1), 0.5));
    world.add(make_shared<Sphere>(Point3d(0, -100.5, -1), 100));
}

void RenderThread::run()
{
    QImage image(IMAGE_WIDTH, IMAGE_HEIGHT, QImage::Format_RGB32);
    while (!m_stop) {
        // render(image);
        cam.render(world);
        emit renderFrame(cam.image);
        QThread::msleep(30);
    }
}