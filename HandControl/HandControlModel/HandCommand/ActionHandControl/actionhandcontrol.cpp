#include "actionhandcontrol.h"

ActionHandControl::ActionHandControl()
{
    create_fingers();
    del_actions_ms = 0;
    state_pos_brush = true;
    state_pos_thumb = false;
}

void ActionHandControl::create_fingers()
{
    fingers.insert("thumb_finger",0);
    fingers.insert("pointer_finger",0);
    fingers.insert("middle_finger",0);
    fingers.insert("ring_finder",0);
    fingers.insert("little_finger",0);

}

bool ActionHandControl::set_right_thumb_position(bool new_position)
{
    bool state_set = true;
    state_pos_thumb = new_position;
    return state_set;
}

bool ActionHandControl::set_finger_position(QString name_finger, int new_position)
{
    bool state_set = true;

    if (new_position>range_action_pos.max)
        new_position = range_action_pos.max;
    if (new_position<range_action_pos.min)
        new_position = range_action_pos.min;
    fingers[name_finger] = new_position;

    return state_set;
}

bool ActionHandControl::set_direct_pos_brush(bool new_position)
{
    bool state_set = true;
    state_pos_brush = new_position;
    return state_set;
}

bool ActionHandControl::set_delay(int new_delay_ms)
{
    bool state_set = true;

    if (new_delay_ms>range_del_time.max)
        new_delay_ms = range_del_time.max;
    if (new_delay_ms<range_del_time.min)
        new_delay_ms = range_del_time.min;
    del_actions_ms = new_delay_ms;
    return state_set;
}

bool ActionHandControl::set_range_action_pos(RangeStruct new_range_action)
{
    bool state_set = true;
    range_action_pos = new_range_action;
    return state_set;
}

bool ActionHandControl::set_range_delay_time(RangeStruct new_range_delay)
{
    bool state_set = true;
    range_del_time = new_range_delay;
    return state_set;
}

RangeStruct ActionHandControl::get_range_delay_time()
{
    return range_del_time;
}

RangeStruct ActionHandControl::get_range_action_pos()
{
    return range_action_pos;
}

int ActionHandControl::get_delay()
{
    return del_actions_ms;
}

int ActionHandControl::get_finger_position(QString name_finger)
{
    return fingers[name_finger];
}

bool ActionHandControl::get_direct_pos_brush()
{
    return state_pos_brush;
}

bool ActionHandControl::get_right_thumb_position()
{
    return state_pos_thumb;
}

ActionHandControl::~ActionHandControl()
{

}
