#include "RenderThread.h"

void RenderThread::run() {
        QImage image(800, 600, QImage::Format_RGB32);
        while (!m_stop)
        {   
            image.fill(QColor(255, 0, 0));
            emit renderFrame(image);
            QThread::msleep(30);
        }
}
