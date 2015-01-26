#ifndef TETRAHEDRON_H
#define TETRAHEDRON_H

#include <Display/Primitives/basicgeometry.h>

class Tetrahedron : public BasicGeometry
{
    Q_OBJECT
public:
    explicit Tetrahedron(QObject *parent = 0);
    void mouseOver();

signals:

public slots:

};

#endif // TETRAHEDRON_H
