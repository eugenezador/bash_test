#include "bash_test.h"

#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    bash_test w;
    w.show();
    QProcess p;
//    pacmd list-sinks | grep '  index' | cut -f6 -d' '
//    p.start(QString("pacmd"), QStringList() << "list-sinks | grep index");
    p.start(QString("bash"), QStringList() << "blut.sh");

//    p.waitForFinished(-1); // will wait forever until finished

    QString stdout = p.readAllStandardOutput();

    QString stderr = p.readAllStandardError();
    qDebug() << stdout;
    return a.exec();
}
