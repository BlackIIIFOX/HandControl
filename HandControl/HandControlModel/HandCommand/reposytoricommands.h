#ifndef REPOSYTORICOMMANDS_H
#define REPOSYTORICOMMANDS_H

#include <QObject>
#include <HandControlModel/HandCommand/handcommand.h>

class ReposytoriCommands
{
public:
    ReposytoriCommands();
    bool append_command(HandCommand new_command);
    bool delete_command(QString name_command);
    QStringList get_names_commands();
    HandCommand get_command(QString name_command);

private:
    QList<HandCommand> list_command;
    QStringList names_list_commands;

};

#endif // REPOSYTORICOMMANDS_H
