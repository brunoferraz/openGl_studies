#ifndef GRID_H
#define GRID_H
#include <Display/abstractobj.h>

class Grid : public AbstractObj
{
    Q_OBJECT
public:
    explicit Grid(QObject *parent = 0);
    void display();
signals:

public slots:

};

#endif // GRID_H
