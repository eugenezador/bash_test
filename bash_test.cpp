//#include <stdlib.h>
#include "bash_test.h"
#include "ui_bash_test.h"

#define SHELLSCRIPT "\
#/bin/bash \n\
pacmd set-default-sink $(pacmd list-sinks | grep '  index' | cut -f6 -d' ') \n\
"


bash_test::bash_test(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::bash_test)
    , timer(new QTimer(this))
{
    ui->setupUi(this);

//    system(SHELLSCRIPT);

    connect(timer, &QTimer::timeout, this, &bash_test::run_script);
    timer->start(2000);

    ui->progressBar->hide();

}

bash_test::~bash_test()
{
    delete ui;
}

void bash_test::run_script()
{
    QProcess p;
    p.start(QString("bash"), QStringList() << "set_hradset_output.sh");
    ui->progressBar->show();
}

