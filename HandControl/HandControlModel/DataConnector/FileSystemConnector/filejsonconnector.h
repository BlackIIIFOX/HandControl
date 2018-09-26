#ifndef FILEJSONCONNECTOR_H
#define FILEJSONCONNECTOR_H
#include <HandControlModel/DataConnector/FileSystemConnector/ifilesystemconnector.h>
#include <HandControlModel/HandCommand/ActionHandControl/reposytoriactions.h>
#include <HandControlModel/HandCommand/ActionHandControl/iactionhandcontrol.h>
#include <QObject>
#include <QDir>
#include <QCoreApplication>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>



// Класс реализует доступ к файловой системе программы через Json файлы.
// Структура JSON файла для хранения команды:
/*
 * {
        "name_command": "command_name",         // Название комманды
        "actions":                              // Содержит все данные, связанные с действиями
            {
                "info_actions":                 // Содержит информацию о действиях
                {
                    "iterable_actions": 0,      // Бесконечность действий
                    "num_act_rep": 1            // Кол-во повторений действий
                },
                "data_actions":                 // Содержит список структур действий, вида:
                [
                    {
                        "thumb_finger": 255,    // Положение большого пальца
                        "pointer_finger": 255,  // Положение указательного пальца
                        "middle_finger": 255,   // Положение среднего пальца
                        "ring_finder": 255,     // Положение безымянного пальца
                        "little_finger": 255,   // Положение мезинца
                        "del_action": 1000,     // Задержка до следующего действия. Измеряется в милисекундах
                        "state_pos_brush": 1,   // Если 1 - то кисть в прямом положении
                        "state_pos_thumb": 0,   // Если 1 - то палец развернут
                        "min_max_time": [0, 10000], // Минимальные и максимальные значения задежки (в милисекундах)
                        "min_max_action": [0,255]   // Минимальные и максимальные значения позиций
                    }
                ]
            }
   }
*/
class FileJsonConnector: public IFileSystemConnector
{
public:
    FileJsonConnector();
    QStringList get_list_commands() override;
    HandCommand load_command(QString name_command) override;
    bool save_command(HandCommand hand_command) override;
    ~FileJsonConnector() override;
private:
    QString path_to_files;

    QJsonDocument load_json_doc(QString file_name);
    ReposytoriActions load_actions_from_json(QJsonObject json_data_actions);
    bool load_action(IActionHandControl& test, QJsonObject json_action);
};

#endif // FILEJSONCONNECTOR_H
