#ifndef SETTINGD_H
#define SETTINGD_H

#include <QDialog>

namespace Ui {
class settingD;
}

class settingD : public QDialog
{
    Q_OBJECT

public:
    explicit settingD(QWidget *parent = nullptr);
    ~settingD();

private slots:
    void on_settingsClose_clicked();

private:
    Ui::settingD *ui;
    void setup();
};

#endif // SETTINGD_H
