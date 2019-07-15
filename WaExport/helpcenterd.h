#ifndef HELPCENTERD_H
#define HELPCENTERD_H

#include <QWidget>

namespace Ui {
class helpCenterD;
}

class helpCenterD : public QWidget
{
    Q_OBJECT

public:
    explicit helpCenterD(QWidget *parent = nullptr);
    ~helpCenterD();

private:
    Ui::helpCenterD *ui;
};

#endif // HELPCENTERD_H
