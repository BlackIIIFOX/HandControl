#ifndef HANDCONTROL_H
#define HANDCONTROL_H

#include <QMainWindow>

namespace Ui {
class HandControl;
}

class HandControl : public QMainWindow
{
    Q_OBJECT

public:
    explicit HandControl(QWidget *parent = nullptr);
    ~HandControl();

private:
    Ui::HandControl *ui;
};

#endif // HANDCONTROL_H
