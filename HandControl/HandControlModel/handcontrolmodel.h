#ifndef HANDCONTROLMODEL_H
#define HANDCONTROLMODEL_H

#include <QObject>
#include <HandControlModel/HandCommand/reposytoricommands.h>
#include <HandControlModel/DataConnector/FileSystemConnector/ifilesystemconnector.h>

class HandControlModel : public QObject
{
    Q_OBJECT
public:
    explicit HandControlModel(QObject *parent = nullptr);

signals:

public slots:


private:
    ReposytoriCommands commands;
    IFileSystemConnector* connector;

    ReposytoriCommands load_commands(IFileSystemConnector* connector);

};

#endif // HANDCONTROLMODEL_H
