#pragma once

#include <QThread>
#include <QDebug>
#include <QImage>

class RenderThread : public QThread 
{
    Q_OBJECT
public:
        RenderThread(QObject *parent = nullptr) : QThread(parent) {}
public:
    void run()override;
public Q_SLOTS:
    void stop() { m_stop = true; }

Q_SIGNALS:
    void renderFrame(const QImage &image); 
private:
    bool m_stop = false;
};