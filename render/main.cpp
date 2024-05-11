#include <QApplication>
#include "MainWindow.h"
#include <iostream>
#include <format>
#include <Eigen/Eigen>


void test(){
    Eigen::Matrix<int, 2,2> a;
    a<<1,2,3,4;
    a(1,1) = 100;
    std::cout << a(0,0)<<std::endl;
}

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    MainWindow mainWindow;

    mainWindow.show();
    return app.exec();
    return 0;
}