#include "reposytoriactions.h"

ReposytoriActions::ReposytoriActions()
{

}


bool ReposytoriActions::append_action(IActionHandControl* new_action)
{
    bool state_append = true;
    list_action.append(new_action);
    return state_append;
}

bool ReposytoriActions::delete_action(int id_action)
{
    bool state_delete = true;
    delete list_action.value(id_action);
    list_action.removeAt(id_action);
    return state_delete;
}

IActionHandControl* ReposytoriActions::get_action(int id_action)
{
    return list_action.value(id_action);
}

bool ReposytoriActions::get_iterable()
{
    return iterable_actions;
}

int ReposytoriActions::get_num_action_rep()
{
    return num_act_rep;
}

bool ReposytoriActions::rearrange_action(int id_1, int id_2)
{
    bool state_rearrange = true;
    IActionHandControl* action_1 = list_action.takeAt(id_1);
    IActionHandControl* action_2 = list_action.takeAt(id_2);
    list_action.insert(id_2, action_1);
    list_action.insert(id_1, action_2);
    return state_rearrange;
}

bool ReposytoriActions::set_iterable(bool new_state)
{
    bool state_set = true;
    iterable_actions = new_state;
    return state_set;
}

bool ReposytoriActions::set_num_actions_repeat(int new_num)
{
    bool state_set = true;
    num_act_rep = new_num;
    return state_set;
}

int ReposytoriActions::count()
{
    return list_action.count();
}

ReposytoriActions::~ReposytoriActions()
{
//    for (int i = 0; i < list_action.count(); i++)
//    {
//        delete list_action.value(i);
//    }
}
