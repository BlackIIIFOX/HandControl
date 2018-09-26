#include "reposytoricommands.h"

ReposytoriCommands::ReposytoriCommands()
{

}

bool ReposytoriCommands::append_command(HandCommand new_command)
{
    bool state_append = true;
    list_command.append(new_command);
    names_list_commands.append(new_command.name_command);
    return state_append;
}

bool ReposytoriCommands::delete_command(QString name_command)
{
    bool state_delete = true;
    for (int i = 0; i < list_command.count(); i++)
    {
        if (list_command.value(i).name_command == name_command)
        {
             list_command.removeAt(i);
             names_list_commands.removeAt(i);
        }
    }
    return state_delete;
}

QStringList ReposytoriCommands::get_names_commands()
{
    return names_list_commands;
}


HandCommand ReposytoriCommands::get_command(QString name_command)
{
    HandCommand returned_command;
    for (int i = 0; i < list_command.count(); i++)
    {
        if (list_command.value(i).name_command == name_command)
            returned_command = list_command.value(i);
    }
    return returned_command;
}
