#include "handcontrol.h"
#include <QApplication>
#include <HandControlModel/handcontrolmodel.h>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


     HandControl w;
     w.show();


    //=====================Тесты================================
    //HandControlModel model_new;




    //==========================================================

    return a.exec();
}
