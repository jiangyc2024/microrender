#include "MainWindow.h"
#include "RenderThread.h"
#include <QDebug>
#include <QPainter>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    renderThread = new RenderThread(this);
    renderThread->start();
    connect(renderThread, &RenderThread::renderFrame, this, &MainWindow::onRenderFrame);
    
}

MainWindow::~MainWindow() {
   if(renderThread &&renderThread->isRunning()){
       renderThread->stop();
   }
   renderThread->wait();
}

void MainWindow::onRenderFrame(const QImage& image) {
    // qDebug() << "render frame";
    m_image = image;
    repaint();
}

void MainWindow::paintEvent(QPaintEvent* event) 
{
    QMainWindow::paintEvent(event);
    QPainter painter(this);
    painter.drawImage(0, 0, m_image);
    
}
