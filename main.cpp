#include "bash_test.h"

#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    bash_test w;
    w.show();
    return a.exec();
}
