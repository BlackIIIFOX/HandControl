#ifndef HANDCOMMAND_H
#define HANDCOMMAND_H

#include <QObject>
// #include <HandControlModel/HandCommand/ActionHandControl/iactionhandcontrol.h>
#include <HandControlModel/HandCommand/ActionHandControl/reposytoriactions.h>

class HandCommand
{
public:
    // Поля:
    QString name_command;

    // Методы:
    HandCommand(QString name_command);
    HandCommand();
    ReposytoriActions get_actions();
    bool set_actions(ReposytoriActions new_action);

private:
    ReposytoriActions rep_actions;

};

#endif // HANDCOMMAND_H
