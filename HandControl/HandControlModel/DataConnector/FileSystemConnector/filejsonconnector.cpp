#include "filejsonconnector.h"
#include <HandControlModel/HandCommand/ActionHandControl/actionhandcontrol.h>
#include <QDebug>

FileJsonConnector::FileJsonConnector()
{
    path_to_files = QCoreApplication::applicationDirPath() + "\\DATA\\Commands";
}

FileJsonConnector::~FileJsonConnector()
{

}

// Загружает список команд из файла Commands.json.
// Возможно стоит делать создание файла, если он вдруг был не найден.
QStringList FileJsonConnector::get_list_commands(){
    QStringList list_commands;
    QJsonDocument doc_json_commands;
    doc_json_commands = load_json_doc(path_to_files+"\\Commands.json");
    QJsonArray array_commands_name = doc_json_commands.object().value("list_commands").toArray();

    for (int i = 0; i < array_commands_name.count(); i++)
        list_commands.append(array_commands_name[i].toString());

    return list_commands;
}


// Загрузка файла с диска и возвращение его в виде qjsondoc
QJsonDocument FileJsonConnector::load_json_doc(QString file_name)
{
    QFile file_info_commands;
    QJsonDocument json_doc;
    file_info_commands.setFileName(file_name);
    if ( file_info_commands.open(QIODevice::ReadOnly | QIODevice::Text) == true)
    {
        QString data_string_json = file_info_commands.readAll();
        json_doc = QJsonDocument::fromJson(data_string_json.toUtf8());
    }

    return json_doc;
}

// Загрузка команды из json файла
HandCommand FileJsonConnector::load_command(QString name_command)
{
    HandCommand new_command(name_command);
    QJsonDocument doc_json_commands;
    doc_json_commands = load_json_doc(path_to_files+"\\"+name_command+"\\command.json");
    ReposytoriActions new_rep_actions;
    new_rep_actions = load_actions_from_json(doc_json_commands.object());

    new_command.set_actions(new_rep_actions);
    return new_command;
}



//=========================Загрузка действий из json файла, поля "data_actions"=======================
ReposytoriActions FileJsonConnector::load_actions_from_json(QJsonObject json_data_actions)
{
    ReposytoriActions new_rep_actions;

    // Устнавливаем информацию о действия
    QJsonObject info_actions = json_data_actions.value("actions").toObject().value("info_actions").toObject();
    new_rep_actions.set_num_actions_repeat(info_actions.value("num_act_rep").toInt());
    new_rep_actions.set_iterable( static_cast<bool>(info_actions.value("iterable_actions").toInt()) );

    // Устанавливаем действия
    QJsonArray data_actions_array = json_data_actions.value("actions").toObject().value("data_actions").toArray();

    for (int i = 0; i < data_actions_array.count(); i++)
    {
        ActionHandControl* new_action = new ActionHandControl();
        load_action(*new_action, data_actions_array[i].toObject());
        new_rep_actions.append_action(new_action);
    }

    return new_rep_actions;
}

bool FileJsonConnector::load_action(IActionHandControl& action_hand_control, QJsonObject json_action)
{
    bool state_load = true;
    // Задаем положение кисти
    action_hand_control.set_direct_pos_brush( static_cast<bool>( json_action.value("state_pos_brush").toInt() ) );
    // Задаем положение большого пальца
    action_hand_control.set_right_thumb_position( static_cast<bool>( json_action.value("state_pos_thumb").toInt() ) );

    // Задаем ограничение задержки
    RangeStruct range_del;
    QJsonArray array_range_del = json_action.value("min_max_time").toArray();
    range_del.min = array_range_del[0].toInt();
    range_del.max = array_range_del[1].toInt();
    action_hand_control.set_range_delay_time(range_del);

    // Задаем задержку
    action_hand_control.set_delay(json_action.value("del_action").toInt());

    // Задаем ограничение положений пальцев
    RangeStruct range_actions;
    QJsonArray array_range_actions = json_action.value("min_max_action").toArray();
    range_actions.min = array_range_actions[0].toInt();
    range_actions.max = array_range_actions[1].toInt();
    action_hand_control.set_range_action_pos(range_actions);

    // Задаем положения пальцев
    action_hand_control.set_finger_position("thumb_finger", json_action.value("thumb_finger").toInt() );
    action_hand_control.set_finger_position("pointer_finger", json_action.value("pointer_finger").toInt() );
    action_hand_control.set_finger_position("middle_finger", json_action.value("middle_finger").toInt() );
    action_hand_control.set_finger_position("ring_finder", json_action.value("ring_finder").toInt() );
    action_hand_control.set_finger_position("little_finger", json_action.value("little_finger").toInt() );
    return state_load;
}

//====================================================================================================

bool FileJsonConnector::save_command(HandCommand hand_command)
{
    bool state_save = true;
    hand_command.get_actions();
    return state_save;
}
