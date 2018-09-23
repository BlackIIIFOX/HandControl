#ifndef DEVICECONNECTOR_H
#define DEVICECONNECTOR_H

#include <QObject>

class DeviceConnector : public QObject
{
    Q_OBJECT
public:
    explicit DeviceConnector(QObject *parent = nullptr);

signals:

public slots:
};

#endif // DEVICECONNECTOR_H