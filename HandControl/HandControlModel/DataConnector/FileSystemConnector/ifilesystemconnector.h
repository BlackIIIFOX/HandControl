#ifndef IFILESYSTEMCONNECTOR_H
#define IFILESYSTEMCONNECTOR_H

#include <QObject>
#include <HandControlModel/HandCommand/handcommand.h>

class IFileSystemConnector
{
public:
    QStringList virtual get_list_commands() = 0;
    HandCommand virtual load_command(QString name_command) = 0;
    bool virtual save_command(HandCommand hand_command) = 0;
    virtual ~IFileSystemConnector() = 0;
};

#endif // IFILESYSTEMCONNECTOR_H
