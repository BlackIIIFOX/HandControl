#include "handcontrol.h"
#include <QApplication>
#include <HandControlModel/DataConnector/FileSystemConnector/filejsonconnector.h>
//#include <HandControlModel/HandCommand/handcommand.h>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    //HandControl w;
    //w.show();


    //=====================Тесты================================
    FileJsonConnector s;
    //HandCommand command("Name");
    //qDebug()<<command.name_command;




    //==========================================================

    return a.exec();
}
