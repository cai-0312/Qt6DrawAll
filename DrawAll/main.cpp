#include "MainWidgetDrawAll.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWidgetDrawAll window;
    window.show();
    return app.exec();
}
