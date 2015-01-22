#ifndef GRID_H
#define GRID_H
#include <Display/UiElements/basicuiobj.h>

class Grid : public BasicUiObj
{
    Q_OBJECT
public:
    explicit Grid(QObject *parent = 0);
    void display();
signals:

public slots:

};

#endif // GRID_H
