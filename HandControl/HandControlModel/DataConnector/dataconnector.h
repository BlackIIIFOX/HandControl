#ifndef DATACONNECTOR_H
#define DATACONNECTOR_H

#include <QObject>

class DataConnector : public QObject
{
    Q_OBJECT
public:
    explicit DataConnector(QObject *parent = nullptr);

signals:

public slots:
};

#endif // DATACONNECTOR_H