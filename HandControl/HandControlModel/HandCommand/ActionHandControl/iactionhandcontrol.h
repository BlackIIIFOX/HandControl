#ifndef IACTIONHANDCONTROL_H
#define IACTIONHANDCONTROL_H

#include <QObject>

struct RangeStruct
{
    int min;
    int max;
};

class IActionHandControl
{

public:
    bool virtual set_right_thumb_position(bool new_position) = 0;
    bool virtual set_finger_position(QString name_finger, int new_position) = 0;
    bool virtual set_direct_pos_brush(bool new_position) = 0;
    bool virtual set_delay(int delay_ms) = 0;
    bool virtual set_range_action_pos(RangeStruct new_range_action) = 0;
    bool virtual set_range_delay_time(RangeStruct new_range_delay) = 0;
    RangeStruct virtual get_range_delay_time() = 0;
    RangeStruct virtual get_range_action_pos() = 0;
    int virtual get_delay() = 0;
    int virtual get_finger_position(QString name_finger) = 0;
    bool virtual get_direct_pos_brush() = 0;
    bool virtual get_right_thumb_position() = 0;
    virtual ~IActionHandControl() = 0;

protected:
    RangeStruct range_action_pos;
    RangeStruct range_del_time;

};

#endif // IACTIONHANDCONTROL_H
