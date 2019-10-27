#include "mainwindow.h"
#include <QTextEdit>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextEdit obja;
    obja.setPlainText("hello");

    MainWindow w;
    w.show();
    return a.exec();
}
