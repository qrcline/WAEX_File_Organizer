#ifndef HELPCENTER_H
#define HELPCENTER_H

#include <QMainWindow>

namespace Ui {
class HelpCenter;
}

class HelpCenter : public QMainWindow
{
    Q_OBJECT

public:
    explicit HelpCenter(QWidget *parent = nullptr);
    ~HelpCenter();

private:
    Ui::HelpCenter *ui;
};

#endif // HELPCENTER_H
