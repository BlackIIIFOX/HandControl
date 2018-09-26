#include "handcommand.h"

HandCommand::HandCommand(QString new_name_command)
{
    name_command = new_name_command;
}

HandCommand::HandCommand(){

}

bool HandCommand::set_actions(ReposytoriActions new_actions)
{
    bool state_set = true;
    rep_actions = new_actions;
    return state_set;
}


ReposytoriActions HandCommand::get_actions()
{
    return rep_actions;
}
