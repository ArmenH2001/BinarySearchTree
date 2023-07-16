#include <QApplication>
#include "widget.h"
#include <iostream>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWidget w;
    w.showMaximized();

    return app.exec();
}


