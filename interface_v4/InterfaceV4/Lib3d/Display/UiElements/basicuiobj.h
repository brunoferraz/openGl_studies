#ifndef BASICUIOBJ_H
#define BASICUIOBJ_H
#include <QObject>
#include <Display/abstractobj.h>

class BasicUiObj : public AbstractObj
{
    Q_OBJECT
public:
    explicit BasicUiObj(QObject *parent = 0);

signals:

public slots:

};

#endif // BASICUIOBJ_H
