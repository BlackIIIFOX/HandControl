#ifndef IACTIONHANDCONTROL_H
#define IACTIONHANDCONTROL_H

#include <QObject>

class IActionHandControl : public QObject
{
    Q_OBJECT
public:
    explicit IActionHandControl(QObject *parent = nullptr);

signals:

public slots:
};

#endif // IACTIONHANDCONTROL_H