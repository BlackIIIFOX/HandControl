#include "handcontrolmodel.h"
#include <HandControlModel/DataConnector/FileSystemConnector/filejsonconnector.h>
#include <HandControlModel/HandCommand/handcommand.h>
#include <HandControlModel/HandCommand/ActionHandControl/reposytoriactions.h>
#include <HandControlModel/HandCommand/ActionHandControl/actionhandcontrol.h>
#include <QDebug>

HandControlModel::HandControlModel(QObject *parent) : QObject(parent)
{
    connector = new FileJsonConnector();
    commands = load_commands(connector);
}

ReposytoriCommands HandControlModel::load_commands(IFileSystemConnector* connector)
{
    QStringList list_names_commands;

    list_names_commands = connector->get_list_commands();

    ReposytoriCommands rep_commands;

    foreach (QString name_command, list_names_commands) {
        HandCommand command = connector->load_command(name_command);
        rep_commands.append_command(command);
    }
    return rep_commands;
}
