#include "mainwindow.h"
#include <QApplication>

#include "attempt.h"

int main(int argc, char *argv[])
{
    Attempt attempt;

    QApplication a(argc, argv);
    MainWindow w(&attempt);
    w.show();

    return a.exec();
}
