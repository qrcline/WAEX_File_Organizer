#ifndef SETTINGD_H
#define SETTINGD_H

#include <QDialog>
#include <mainwindow.h>

namespace Ui {
class settingD;
}

class settingD : public QDialog
{
    Q_OBJECT

public:
    explicit settingD(QWidget *parent );
    ~settingD();

private slots:
    void on_settingsClose_clicked();

private:
    Ui::settingD *ui;
    Ui::MainWindow* uiPointer;
    void setup();
    void closeEvent(QCloseEvent *bar);
};

#endif // SETTINGD_H
