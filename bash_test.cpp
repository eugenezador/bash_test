#include "bash_test.h"
#include "ui_bash_test.h"


bash_test::bash_test(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::bash_test)
    , timer(new QTimer(this))
{
    ui->setupUi(this);

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
    // bash скрипт должен лежать в папке build-...
    p.start(QString("bash"), QStringList() << "set_hradset_output.sh");
    ui->progressBar->show();
}

