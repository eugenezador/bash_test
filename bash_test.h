#ifndef BASH_TEST_H
#define BASH_TEST_H

#include <QMainWindow>
#include <QProcess>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class bash_test; }
QT_END_NAMESPACE

class bash_test : public QMainWindow
{
    Q_OBJECT

public:
    bash_test(QWidget *parent = nullptr);
    ~bash_test();

    void run_script();

private:
    Ui::bash_test *ui;

    QTimer *timer = nullptr;

};
#endif // BASH_TEST_H
