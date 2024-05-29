#include "MainWindow.h"
#include "Vec.h"
#include <Eigen/Eigen>
#include <QApplication>
#include <format>
#include <iostream>

void test() {
    Vec3f a(1, 2, 3);
    Vec3f b(4, 5, 6);
    // add
    std::cout << "add:" << a + b << std::endl;
    // broadcast
    std::cout << "broadcast:" << a * 3 << std::endl;
    // dot
    std::cout << "dot:" << a.dot(b) << std::endl;
    // cross
    std::cout << "norm:" << a.squaredNorm() << std::endl;
}

int main(int argc, char** argv) {
    test();
    QApplication app(argc, argv);
    MainWindow mainWindow;

    mainWindow.show();
    return app.exec();
    return 0;
}