#ifndef IDATACONNECTROR_H
#define IDATACONNECTROR_H

#include <QObject>

class IDataConnectror : public QObject
{
    Q_OBJECT
public:
    explicit IDataConnectror(QObject *parent = nullptr);

signals:

public slots:
};

#endif // IDATACONNECTROR_H