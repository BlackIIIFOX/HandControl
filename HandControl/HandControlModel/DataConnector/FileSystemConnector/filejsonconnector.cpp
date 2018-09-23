#include "filejsonconnector.h"
#include <QDebug>

FileJsonConnector::FileJsonConnector()
{
    //this->setParent(parent);
    qDebug()<<"asd";
}

FileJsonConnector::~FileJsonConnector()
{
    delete this;
}

QStringList FileJsonConnector::get_list_commands(){
    QStringList list_commands;

    return list_commands;
}

HandCommand FileJsonConnector::load_command(QString name_command)
{
    HandCommand new_command(name_command);

    return new_command;
}


bool FileJsonConnector::save_command(HandCommand hand_command)
{

}
