#pragma once

#include <QDebug>
#include <QImage>
#include <QThread>

class RenderThread : public QThread {
    Q_OBJECT
  public:
    RenderThread(QObject* parent = nullptr) : QThread(parent) {}

  public:
    void run() override;
  public Q_SLOTS:
    void stop() { m_stop = true; }
    void render(QImage& image);
  Q_SIGNALS:
    void renderFrame(const QImage& image);

  private:
    bool m_stop = false;
};