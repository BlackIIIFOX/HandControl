#ifndef FILEJSONCONNECTOR_H
#define FILEJSONCONNECTOR_H
#include <HandControlModel/DataConnector/FileSystemConnector/ifilesystemconnector.h>
#include <QObject>

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
};

#endif // FILEJSONCONNECTOR_H
