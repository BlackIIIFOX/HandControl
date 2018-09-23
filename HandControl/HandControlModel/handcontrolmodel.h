#ifndef HANDCONTROLMODEL_H
#define HANDCONTROLMODEL_H

#include <QObject>

class HandControlModel : public QObject
{
    Q_OBJECT
public:
    explicit HandControlModel(QObject *parent = nullptr);

signals:

public slots:
};

#endif // HANDCONTROLMODEL_H