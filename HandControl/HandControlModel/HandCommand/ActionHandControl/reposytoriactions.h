#ifndef REPOSYTORIACTIONS_H
#define REPOSYTORIACTIONS_H

#include <QObject>
#include <HandControlModel/HandCommand/ActionHandControl/iactionhandcontrol.h>

class ReposytoriActions
{
public:
    ReposytoriActions();

    int count();
    bool append_action(IActionHandControl* new_action);
    bool delete_action(int id_action);
    IActionHandControl* get_action(int id_action);
    bool get_iterable();
    int get_num_action_rep();
    bool rearrange_action(int id_1, int id_2);
    bool set_iterable(bool new_state);
    bool set_num_actions_repeat(int new_num);
    ~ReposytoriActions();

private:
    int iterable_actions;
    int num_act_rep;
    QList<IActionHandControl*> list_action;
};

#endif // REPOSYTORIACTIONS_H
