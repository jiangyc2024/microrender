#pragma once

#include <QMainWindow>
#include <QImage>

class RenderThread;
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void onRenderFrame(const QImage &image);

    void paintEvent(QPaintEvent *event) override;
private:
    RenderThread *renderThread = nullptr;
    QImage m_image;
};