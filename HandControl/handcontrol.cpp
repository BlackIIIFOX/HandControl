#include "handcontrol.h"
#include "ui_handcontrol.h"

HandControl::HandControl(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HandControl)
{
    ui->setupUi(this);
}

HandControl::~HandControl()
{
    delete ui;
}
