#ifndef HANDCONTROL_H
#define HANDCONTROL_H

#include <QMainWindow>
#include <HandControlModel/handcontrolmodel.h>

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
    HandControlModel model_new;
};

#endif // HANDCONTROL_H
