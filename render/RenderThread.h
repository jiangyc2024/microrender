#pragma once

#include <QDebug>
#include <QImage>
#include <QThread>

#include "HittableList.h"
#include "Ray.h"
#include "Vec.h"
#include "camera.h"
class RenderThread : public QThread
{
    Q_OBJECT
public:
    RenderThread(QObject* parent = nullptr);

public:
    void run() override;
public Q_SLOTS:
    void stop()
    {
        m_stop = true;
    }

Q_SIGNALS:
    void renderFrame(const QImage& image);

private:
    bool m_stop = false;

    HittableList world;
    camera       cam;
};