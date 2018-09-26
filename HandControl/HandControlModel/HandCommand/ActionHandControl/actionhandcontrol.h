#ifndef ACTIONHANDCONTROL_H
#define ACTIONHANDCONTROL_H

#include <QObject>
#include <HandControlModel/HandCommand/ActionHandControl/iactionhandcontrol.h>
#include <QMap>


class ActionHandControl : public IActionHandControl
{

public:
    ActionHandControl();
    bool set_right_thumb_position(bool new_position) override;
    bool set_finger_position(QString name_finger, int new_position) override;
    bool set_direct_pos_brush(bool new_position) override;
    bool set_delay(int delay_ms) override;
    bool set_range_action_pos(RangeStruct new_range_action) override;
    bool set_range_delay_time(RangeStruct new_range_delay) override;
    RangeStruct get_range_delay_time() override;
    RangeStruct get_range_action_pos() override;
    int get_delay() override;
    int get_finger_position(QString name_finger) override;
    bool get_direct_pos_brush() override;
    bool get_right_thumb_position() override;
    ~ActionHandControl() override;

private:
    int del_actions_ms;
    QMap<QString, int> fingers;
    bool state_pos_brush;
    bool state_pos_thumb;

    void create_fingers();
};

#endif // ACTIONHANDCONTROL_H
