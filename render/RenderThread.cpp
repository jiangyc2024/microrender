#include "RenderThread.h"
#define IMAGE_WIDTH 800
#define IMAGE_HEIGHT 600

void RenderThread::run() {
    QImage image(IMAGE_WIDTH, IMAGE_HEIGHT, QImage::Format_RGB32);
    while (!m_stop) {
        render(image);
        emit renderFrame(image);
        QThread::msleep(30);
    }
}

void RenderThread::render(QImage& image) {
    image.fill(QColor(0, 0, 0));
    for (int j = 0; j < image.height(); j++) {
        for (int i = 0; i < image.width(); i++) {
            auto r = double(i) / (image.width() - 1);
            auto g = double(j) / (image.height() - 1);
            auto b = 0;

            int ir = int(255.999 * r);
            int ig = int(255.999 * g);
            int ib = int(255.999 * b);
            image.setPixel(i, j, qRgb(ir, ig, ib));
        }
    }
}
