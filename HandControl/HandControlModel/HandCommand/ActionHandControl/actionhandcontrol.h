#ifndef ACTIONHANDCONTROL_H
#define ACTIONHANDCONTROL_H

#include <QObject>

class ActionHandControl : public QObject
{
    Q_OBJECT
public:
    explicit ActionHandControl(QObject *parent = nullptr);

signals:

public slots:
};

#endif // ACTIONHANDCONTROL_H